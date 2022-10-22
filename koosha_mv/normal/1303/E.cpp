#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5+9;
ll n,q1,dp[405];
bool ans;
string s,t,s1,s2;
bool solve(){
	f(i,0,402) dp[i]=-1;
	dp[0]=0;
	f(i,0,s.size()){
		f_(j,s1.size(),0){
			if(dp[j]<s2.size() && s2[dp[j]]==s[i])
				dp[j]++;
			if(j>0 && s1[j-1]==s[i])
				maxm(dp[j],dp[j-1]);
		}
	}
	return (dp[s1.size()]==s2.size());
}
int main(){
	cin>>q1;
	f(q,0,q1){
		cin>>s>>t;ans=0;
		f(i1,0,t.size()){
			s1="",s2="";
			f(j1,0,t.size()){
				if(j1<i1) s1+=t[j1];
				else s2+=t[j1];
			}
			ans=(ans || solve());
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}