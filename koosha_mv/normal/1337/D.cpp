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

const int N=3e5+9;
int n,t,r,g,b,sr[N],sg[N],sb[N],s[3][N];
ll ans;
int binary(int an,int x){
	int l=-1,r1,mid;
	if(an==0) r1=r;
	if(an==1) r1=g;
	if(an==2) r1=b;
	while(l+1<r1){
		mid=(l+r1)/2;
		if(s[an][mid]<=x) l=mid;
		else r1=mid;
	}
	return l;
}
ll solve1(){
	ll res=2e18,p,e1,e2,g1,g2;
/*	print(s[0],r);
	print(s[1],g);
	print(s[2],b);
	cout<<endl;*/
	f(i,0,r){
		p=binary(1,s[0][i]);
		if(p==-1) e1=-1;
		else e1=s[0][i]-s[1][p];
		if(s[1][p]==s[0][i]) e2=0;
		else{
			if(p==g-1) e2=-1;
			else e2=s[1][p+1]-s[0][i];
		}
		p=binary(2,s[0][i]);
		if(p==-1) g1=-1;
		else g1=s[0][i]-s[2][p];
		if(s[2][p]==s[0][i]) g2=0;
		else{
			if(p==b-1) g2=-1;
			else g2=s[2][p+1]-s[0][i];
		}
		if(e1>=0 && g2>=0)minm(res,(e1*e1+g2*g2+e1*g2)*2ll);
		if(e2>=0 && g1>=0)minm(res,(e2*e2+g1*g1+g1*e2)*2ll);
	}
	return res;
}
void swap(int x){
	if(x==1){
		swap(r,g);
		f(i,0,max(r,g))
			swap(s[0][i],s[1][i]);
	}
	else{
		swap(r,b);
		f(i,0,max(r,b))
			swap(s[0][i],s[2][i]);
	}
}
int main(){
	cin>>t;
	while(t--){
		ans=2e18;
		cin>>r>>g>>b;
		f(i,0,r) gett(s[0][i]);
		f(i,0,g) gett(s[1][i]);
		f(i,0,b) gett(s[2][i]);
		sort(s[0],s[0]+r);
		sort(s[1],s[1]+g);
		sort(s[2],s[2]+b);
		minm(ans,solve1());
		swap(1);
		minm(ans,solve1());
		swap(2);
		minm(ans,solve1());
		cout<<ans<<endl;
	}
}