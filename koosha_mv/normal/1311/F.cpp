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
const int N=2e5+3;
ll k=18,n,tvn=131072,ct,b[N],p,ans,e=2e5+999,g[N],cnt;
string s;
pair<ll,ll> a[N];
map<ll,ll> tedad,t2,mark;
string binary(ll m,ll k){
	string g="";
	f(i,0,k){
		g+=char((m%2)+'0');
		m=m/2;
	}
	return g;}
int main(){
	cin>>n;
	f(i,0,n) get(a[i].F);
	f(i,0,n){get(a[i].S);g[i]=a[i].S;}
	sort(a,a+n);
	sort(g,g+n);
	f(i,0,n){
		if(i==0 || g[i]!=g[i-1]){
			cnt++;
			mark[g[i]]=cnt;
		}
	}
	f(i,0,n){
		b[i]=e-(mark[a[i].S]);
		s=binary(tvn*2-b[i],k);
		p=tvn*2;ct=tvn;
		f_(l,k-1,0){
			if(s[l]=='1'){
				p-=ct;
				ans+=(t2[p]*a[i].F)-tedad[p];
			}
			ct/=2;
		}
		s=binary(b[i],k);
		p=0;ct=tvn;
		f_(l,k-1,0){
			if(s[l]=='1'){
				p+=ct;
				tedad[p]+=a[i].F;
				t2[p]++;
			}
			ct/=2;
		}
	}
	cout<<ans;
}