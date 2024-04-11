#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+9;
int ans,n,t,a[N],mark[N],t1[N],t2[N];
string s[N];
bool check(string g){
	int mn=0,sum=0;
	f(i,0,g.size()){
		sum+=(g[i]=='(');
		sum-=(g[i]==')');
		minm(mn,sum);
	}
	if((sum>=0 && mn<0) || (sum<=0 && mn<sum)) return 0;
	return 1;
}
int main(){
	cin>>n;
	f(i,0,n) cin>>s[i];
	f(i,0,n){
		if(check(s[i])){
			t=0;
			f(j,0,s[i].size()){
				t+=(s[i][j]=='(');
				t-=(s[i][j]==')');
			}
			if(t>=0) t1[t]++;
			else t2[-1*t]++;
		}
	}
	ans+=t1[0]/2;
	f(i,1,N){
		ans+=min(t1[i],t2[i]);
	}
	cout<<ans;
}