#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=1e3+9;
ll n,a[N][2],e=2e9,k,t;
vector<int> ans,ans2;
void solve(){
	f(i,0,n){
		a[i][0]/=2,a[i][1]/=2;
		if((a[i][0]+e)%2+(a[i][1]+e)%2>0)
			k=1;
	}
}
int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i][0]>>a[i][1];
		if(i>0)
			a[i][0]-=a[0][0],a[i][1]-=a[0][1],a[i][0]*=2,a[i][1]*=2;
	}
	a[0][0]=0,a[0][1]=0;
	while(!k)
		solve();
	f(i,0,n){
		if((a[i][0]+e)%2!=(a[i][1]+e)%2)
			ans.pb(i+1);
		if((a[i][0]+e)%2==(a[i][1]+e)%2 && a[i][0]/2*2==a[i][0]) ans2.pb(i+1);
	}
	if(ans.size()){
		cout<<ans.size()<<endl;
		print(ans,ans.size());
	}
	else{
		cout<<ans2.size()<<endl;
		print(ans2,ans2.size());
	}
}