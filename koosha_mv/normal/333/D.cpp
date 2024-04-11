#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=1001;
int n,m,l,mid,c,r=N*N*N,mp[N][N],g[N][N],a[N];
bool check(int x){
	f(i,0,N) f(j,0,N) g[i][j]=0;
	f(i,0,n){
		c=0;
		f(j,0,m)
			if(mp[i][j]>=x)
				a[c++]=j;
		f(k1,0,c){
			f(k2,k1+1,c){
				if(g[a[k1]][a[k2]]==1) return 1;
				g[a[k1]][a[k2]]=1;
			}
		}
	}
	return 0;
}
int main(){
	cin>>n>>m;
	f(i,0,n)
		f(j,0,m)
			gett(mp[i][j]);
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
}