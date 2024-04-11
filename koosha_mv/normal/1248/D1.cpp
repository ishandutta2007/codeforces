#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
ll n,l,r,ans,p,a[505],mn1[505],mn2[505];
string s;
int calc(string s){
	ll ans=0;
	a[0]=0;
	f(i,1,s.size()){
		a[i]=a[i-1]+1;
		if(s[i]==')')
			a[i]-=2;
		mn1[i]=min(mn1[i-1],a[i]);
	}
	if(a[s.size()-1]!=0) return 0;
	f_(i,s.size()-1,0)
		mn2[i]=min(mn2[i+1],a[i]);
	f(i,1,s.size()){
		if(mn2[i]-a[i-1]>=0 && mn1[i-1]+a[s.size()-1]-a[i-1]>=0)
			ans++;
	}
	return ans;
}
int main(){
	cin>>n>>s;
	s=' '+s;
	f(i,1,n+1){
		f(j,1,i+1){
			swap(s[i],s[j]);
			p=calc(s);
			if(p>=ans){
				ans=p;
				l=i,r=j;
			}
			swap(s[i],s[j]);
		}
	}
	cout<<ans<<endl;
	cout<<l<<" "<<r<<endl;
}