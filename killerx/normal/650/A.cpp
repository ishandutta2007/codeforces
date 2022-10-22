#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<vector>
#define ll long long
#define MP make_pair
#define PB push_back
using namespace std;
int read(){
	int x=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(; isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
const int N=1<<18;
int n,x[N],y[N];
map<int,int>row,col;
map<pair<int,int>,int>same;
int main(){
    n=read();
    ll ans=0;
    for(int i=0;i<n;++i){
        x[i]=read(),y[i]=read();
        row[x[i]]++;
        col[y[i]]++;
        same[MP(x[i],y[i])]++;
        ans+=row[x[i]]-1;
        ans+=col[y[i]]-1;
        ans-=same[MP(x[i],y[i])]-1;
    }
    printf("%lld\n",ans);
	return 0;
}