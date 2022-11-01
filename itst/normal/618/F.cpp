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

#define PII pair < int , int >
#define st first
#define nd second
#define ll long long
const int MAXN = 1e6 + 7;
ll A[MAXN] , B[MAXN];
PII pos[MAXN];

signed main(){
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    //freopen("out","w",stdout);
#endif
    int N = read();
    for(int i = 1 ; i <= N ; ++i)
	A[i] = A[i - 1] + read();
    for(int i = 1 ; i <= N ; ++i)
	B[i] = B[i - 1] + read();
    bool f = A[N] > B[N];
    if(f) swap(A , B);
    fill(pos , pos + N + 1 , PII(-1 , -1));
    int p = 0;
    for(int i = 0 ; i <= N ; ++i){
	while(B[p] < A[i]) ++p;
	if(pos[B[p] - A[i]] != PII(-1 , -1)){
	    PII t = pos[B[p] - A[i]];
	    if(!f){
		printf("%d\n" , i - t.first);
		for(int j = t.first + 1 ; j <= i ; ++j)
		    printf("%d " , j);
		printf("\n%d\n" , p - t.second);
		for(int j = t.second + 1 ; j <= p ; ++j)
		    printf("%d " , j);
	    }
	    else{
		printf("%d\n" , p - t.second);
		for(int j = t.second + 1 ; j <= p ; ++j)
		    printf("%d " , j);
		printf("\n%d\n" , i - t.first);
		for(int j = t.first + 1 ; j <= i ; ++j)
		    printf("%d " , j);
	    }
	    return 0;
	}
	else pos[B[p] - A[i]] = PII(i , p);
    }
    puts("-1");
    return 0;
}