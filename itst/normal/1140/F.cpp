#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<stack>
#include<cmath>
#include<random>
//This code is written by Itst
using namespace std;

#define int long long
inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c) && c != EOF){
        if(c == '-')
            f = 1;
        c = getchar();
    }
    if(c == EOF)
        exit(0);
    while(isdigit(c)){
	a = a * 10 + c - 48;
        c = getchar();
    }
    return f ? -a : a;
}

const int MAXN = 6e5 + 7;
#define PII pair < int , int >
#define st first
#define nd second
map < PII , int > mp;
vector < PII > Edge[MAXN << 2];
int fa[MAXN] , szX[MAXN] , szY[MAXN] , Q , ans;

int find(int x){
    return fa[x] == x ? x : find(fa[x]);
}

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
void addEdge(int x , int l , int r , int L , int R , PII pos){
    if(l >= L && r <= R){
	Edge[x].push_back(pos);
	return;
    }
    if(mid >= L) addEdge(lch , l , mid , L , R , pos);
    if(mid < R) addEdge(rch , mid + 1 , r , L , R , pos);
}

void merge(int x , int y , stack < int > &stk){
    x = find(x); y = find(y);
    if(x == y) return;
    ans -= szX[x] * szY[x] + szX[y] * szY[y];
    if(szX[x] + szY[x] < szX[y] + szY[y])
	swap(x , y);
    fa[y] = x; szY[x] += szY[y]; szX[x] += szX[y];
    ans += szX[x] * szY[x];
    stk.push(y);
}

void work(int x , int l , int r){
    stack < int > stk;
    int lastans = ans;
    for(auto t : Edge[x])
	merge(t.st , t.nd + 300000 , stk);
    if(l == r)
	printf("%lld " , ans);
    else{
	work(lch , l , mid);
	work(rch , mid + 1 , r);
    }
    while(!stk.empty()){
	int t = stk.top(); stk.pop();
	int p = find(t);
	szX[p] -= szX[t]; szY[p] -= szY[t];
	fa[t] = t;
    }
    ans = lastans;
}

signed main(){
    Q = read();
    for(int i = 1 ; i <= Q ; ++i){
	int a = read() , b = read();
	PII t = PII(a , b);
	if(mp.find(t) == mp.end()) mp[t] = i;
	else{
	    addEdge(1 , 1 , Q , mp[t] , i - 1 , t);
	    mp.erase(mp.find(t));
	}
    }
    for(auto t : mp)
	addEdge(1 , 1 , Q , t.second , Q , t.first);
    for(int i = 1 ; i <= 3e5 ; ++i)
	szX[fa[i] = i] = 1;
    for(int i = 3e5 + 1 ; i <= 6e5 ; ++i)
	szY[fa[i] = i] = 1;
    work(1 , 1 , Q);
    return 0;
}