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
const int N=5e5+9;
int n,t,k=1;
string s,ans;
int main(){
	cin>>s;
	f(i,0,s.size()) t+=(s[i]=='1');
	if(t==s.size()) return cout<<s,0;
	f(i,0,s.size())
		if(s[i]!='1')
			ans+=s[i];
	f(i,0,ans.size()){
		if(ans[i]=='2' && k){
			k=0;
			f(j,0,t)
				cout<<'1';
			}
		cout<<ans[i];
	}
	if(k)
		f(i,0,t)
			cout<<'1';
}