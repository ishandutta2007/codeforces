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
ll n,ans,t;
string a,b,c;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>a>>b>>c;
		n=a.size();
		ans=1;
		f(i,0,n){
			if(c[i]!=a[i] && c[i]!=b[i]) ans=0;
		}
		if(ans==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}