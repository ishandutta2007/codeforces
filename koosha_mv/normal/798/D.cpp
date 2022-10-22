#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=1e5+9;
int n;
pair<int,pair<int,int> > a[N];
vector<int> ans;
void solve(){
	for(int i=0;i<n;i+=2){
		if(a[i].S.F>a[i+1].S.F)
			ans.pb(a[i].S.S);
		else
			ans.pb(a[i+1].S.S);
	}
}
int main(){
	cin>>n;
	f(i,0,n){gett(a[i].F);a[i].S.S=i+1;}
	f(i,0,n) gett(a[i].S);
	sort(a,a+n);
	ans.pb(a[n-1].S.S);
	n--;
	if(n%2==1)
		ans.pb(a[n-1].S.S),n--;
	solve();
	cout<<ans.size()<<endl;
	f(i,0,ans.size()) cout<<ans[i]<<" ";
}