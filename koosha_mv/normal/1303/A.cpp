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
const int N=3e5+9;
ll n,t,ans,k,t1=1,a1,a2,t2;
string s;
int main(){
	cin>>t;
	f(q,0,t){
		ans=0,k=0,t1=0,t2=0;
		cin>>s;
		f(i,0,s.size()){
			if(s[i]=='1') t1++;
		}
		f(i,0,s.size()){
			if(s[i]=='1') k=1,t2++;
			if(t2<t1 && k==1 && s[i]=='0') ans++;
		}
		cout<<ans<<endl;
	}
}