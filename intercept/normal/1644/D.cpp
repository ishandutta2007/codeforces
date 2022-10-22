#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=2e5+9;
int vis[M][2],x[M],y[M];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
int ca=0;
void work(){
	ca++;
	int n,m,k,q,l=0,r=0,w=0;
	cin>>n>>m>>k>>q;
	for(int i=1;i<=q;++i){
		cin>>x[i]>>y[i];
	}
	for(int i=q;i>=1;--i){
		if(vis[x[i]][0]!=ca&&vis[y[i]][1]!=ca){
			vis[x[i]][0]=ca;
			vis[y[i]][1]=ca;
			if(l<n||r<m)w++,l=min(l+1,n),r=min(r+1,m);
		}
		else if(vis[x[i]][0]!=ca&&r<m)vis[x[i]][0]=ca,++l,++w;
		else if(vis[y[i]][1]!=ca&&l<n)vis[y[i]][1]=ca,++r,++w;
	}
	cout<<kpow(k,w)<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 5
-2 -7 -1
*/