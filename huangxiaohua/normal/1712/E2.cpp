#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,m,t,l,r,tot;
int f[200500];
vector<pair<int,int> > q[200500];
ll res[200500],g[205000];

void add(int x,ll y){for(;x<=200000;x+=(-x&x)){g[x]+=y;}}
ll get(int x,ll y=0){for(;x;x-=(-x&x)){y+=g[x];}return y;}

int main(){
	ios::sync_with_stdio(0);
	for(i=1;i<=200000;i++)for(j=i+i;j<=200000;j+=i)f[j]++;
	for(i=1;i<=200000;i++)add(i,1ll*(f[i])*(f[i]-1)/2);
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>l>>r;
		q[l].push_back({r,i});
		res[i]=1ll*(r-l+1)*(r-l)*(r-l-1)/6;
		res[i]-=max(0,r/6-(l*2-1)/6);
		res[i]-=max(0,r/15-((l*5+1)/2-1)/15);
	}
	for(i=1;i<=200000;i++){
		for(auto [r,id]:q[i])res[id]-=get(r);
		for(j=i+i;j<=200000;j+=i){
			add(j,-1ll*(f[j])*(f[j]-1)/2);
			f[j]--;add(j,1ll*(f[j])*(f[j]-1)/2);
		}
	}
	for(i=1;i<=t;i++)cout<<res[i]<<' ';
}