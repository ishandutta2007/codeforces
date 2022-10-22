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
const int N=2e5+99;
ll n,t,m,p[N],x,sum,ans[27];
string s;
int main(){
	get(t);
	f(salam,0,t){
		f(i,0,27) ans[i]=0;
		f(i,0,n+3) p[i]=0;
		Get(n,m);
		cin>>s;
		f(i,0,m){
			get(x);
			p[x]++;
		}
		sum=m+1;
		f(i,0,n){
			sum-=p[i];

			ans[s[i]-'a']+=sum;
		}
		f(i,0,26) cout<<ans[i]<<" ";
		cout<<endl;
	}
}