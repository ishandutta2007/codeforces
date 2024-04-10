#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<cstring>
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)){
	a = a * 10 + c - 48;
	c = getchar();
    }
    return a;
}

#define st first
#define nd second
struct PII{
    int first , second;
    PII(int x = 0 , int y = 0):first(x) , second(y){}
    bool operator ==(PII a){return a.st == first && a.nd == second;}
    bool operator !=(PII a){return !(*this == a);}
};
const int MAXN = 3e5 + 7 , Base = 131 , MOD1 = 1e9 + 7 , MOD2 = 1e9 + 9;
PII powBs[MAXN] , sum[MAXN] , powInv[MAXN];
int arr[MAXN] , N;

PII operator *(PII a , PII b){
    return PII(1ll * a.st * b.st % MOD1 , 1ll * a.nd * b.nd % MOD2);
}

PII operator +(PII a , PII b){
    PII t(a.st + b.st , a.nd + b.nd);
    if(t.st >= MOD1) t.st -= MOD1;
    if(t.nd >= MOD2) t.nd -= MOD2;
    return t;
}

PII operator -(PII a , PII b){return a + PII(MOD1 - b.st , MOD2 - b.nd);}

struct BIT{
#define lowbit(x) (x & -x)
    PII arr[MAXN];
    BIT(){memset(arr , 0 , sizeof(PII) * (N + 1));}

    void add(int pos , PII cur){
	while(pos <= N){
	    arr[pos] = arr[pos] + cur;
	    pos += lowbit(pos);
	}
    }

    PII get(int pos){
	PII sum = PII(0 , 0);
	while(pos){
	    sum = sum + arr[pos];
	    pos -= lowbit(pos);
	}
	return sum;
    }
}Tree1 , Tree2;

inline int poww(long long a , int b , int MOD){
    int times = 1;
    while(b){
	if(b & 1) times = times * a % MOD;
	a = a * a % MOD;
	b >>= 1;
    }
    return times;
}

void init(){
    powBs[0] = sum[0] = powInv[0] = PII(1 , 1);
    for(int i = 1 ; i <= N ; ++i){
	powBs[i] = powBs[i - 1] * PII(Base , Base);
	sum[i] = sum[i - 1] + powBs[i];
    }
    powInv[1] = PII(poww(Base , MOD1 - 2 , MOD1) , poww(Base , MOD2 - 2 , MOD2));
    for(int i = 2 ; i <= N ; ++i)
	powInv[i] = powInv[i - 1] * powInv[1];
}

void work(){
    for(int i= 1 ; i <= N ; ++i)
	Tree1.add(arr[i] , powBs[arr[i]]);
    for(int i = N ; i ; --i){
	Tree1.add(arr[i] , PII(0 , 0) - powBs[arr[i]]);
	if(arr[i] != 1 && arr[i] != N){
	    int l1 = 1 , r1 = arr[i] - 1 , l2 = arr[i] + 1 , r2 = N;
	    if(r2 - l2 < r1 - l1) l1 = r1 - (r2 - l2);
	    else r2 = l2 + (r1 - l1);
	    PII t = (Tree1.get(r1) - Tree1.get(l1 - 1)) * powInv[l1] + (Tree2.get(N + 1 - l2) - Tree2.get(N - r2)) * powInv[N - r2 + 1];
	    if(t != sum[r1 - l1]){
		puts("YES");
		exit(0);
	    }
	}
	Tree2.add(N - arr[i] + 1 , powBs[N - arr[i] + 1]);
    }
}

signed main(){
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    //freopen("out","w",stdout);
#endif
    N = read();
    init();
    for(int i = 1 ; i <= N ; ++i)
	arr[i] = read();
    work();
    puts("NO");
    return 0;
}