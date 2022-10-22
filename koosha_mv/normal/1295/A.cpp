#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=105;
ll n,t;
string ans;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n;
		ans="";
		f(i,0,n/2)
			ans+="1";
		if(n%2==1)
			ans[0]='7';
		cout<<ans<<endl;
	}
}