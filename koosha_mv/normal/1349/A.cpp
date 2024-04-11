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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2e5+99;

ll n,t,a[N],mark[N],ans=1;
vector<ll> p[N];

int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		for(int j=2;j*j<=a[i];j++){
			if(a[i]%j==0){
				int c=0;
				while(a[i]%j==0)
					c++,a[i]/=j;
				p[j].pb(c);
			}
		}
		if(a[i]>1) p[a[i]].pb(1);
	}
	f(i,2,N){
		sort(p[i].begin(),p[i].end());
		if(p[i].size()==n-1) f(j,0,p[i][0]) ans*=i;
		if(p[i].size()==n) f(j,0,p[i][1]) ans*=i;
	}
	cout<<ans;
}