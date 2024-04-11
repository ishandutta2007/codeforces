#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
ll n,ans,t1,t2,t,gh;
string s;
int main(){
	cin>>n;
	cin>>s;
	f(i,0,n){
		if(s[i]=='(') t1++;
		else t2++;
	}
	if(t1!=t2) return cout<<-1,0;
	f(i,0,n){
		if(s[i]=='(') t++;
		else t--;
		if(t<0 || (t==0 && s[i]=='('))
			ans++;
	}
	cout<<ans;
}