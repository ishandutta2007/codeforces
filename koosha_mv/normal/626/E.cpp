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
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=2e5+9;
ll n,ans1,ans2,l,r,mid,g,p,a[N],pr[N];
ll inter(int l,int r){if(l==0) return pr[r];return pr[r]-pr[l-1];}
double mxans=0,av1,av2;
bool check(int c,int x,int t,int sum){
	av1=double(inter(n-1-c,n-1)+inter(x-c,x)+sum)/double(t+2*(c+1));
	av2=double(inter(n-1-c-1,n-1)+inter(x-c-1,x)+sum)/double(t+2*(c+2));
	return av1<=av2;
}
double solve(int x,int t,int sum,int o){
	l=-1,r=o;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid,x,t,sum)) l=mid;
		else r=mid;
	}
	return r;
}
int main(){
	srand(time(NULL));
	cin>>n;
	f(i,0,n)
		cin>>a[i];
	sort(a,a+n);
	
	pr[0]=a[0];
	f(i,1,n) pr[i]=a[i]+pr[i-1];
	
	f(i,0,n-1){
		p=min(i-1,n-1-i);
		g=solve(i-1,1,a[i],p);
		av1=double(inter(n-1-g,n-1)+inter(i-1-g,i-1)+a[i])/double(1+2*(g+1));
		if(av1-a[i]>mxans)
			mxans=av1-a[i],ans1=i,ans2=g+1;
	}
	f(i,0,n-2){
		p=min(i-1,n-2-i);
		g=solve(i-1,2,a[i]+a[i+1],p);
		av1=double(inter(n-1-g,n-1)+inter(i-1-g,i-1)+a[i]+a[i+1])/double(2+2*(g+1));
		av2=(double(a[i])+double(a[i+1]))/double(2);
		if(av1-av2>mxans)
			mxans=av1-av2,ans1=n+i,ans2=g+1;
	}
	if(ans1>=n){
		ans1-=n;
		cout<<2*ans2+2<<endl;
		f_(i,ans1-1,ans1-ans2)
			cout<<a[i]<<" ";
		cout<<a[ans1]<<" "<<a[ans1+1]<<" ";
		f_(i,n-1,n-ans2) cout<<a[i]<<" ";
		return 0;
	}
	cout<<2*ans2+1<<endl;
	cout<<a[ans1]<<" ";
	f_(i,ans1-1,ans1-ans2) cout<<a[i]<<" ";
	f_(i,n-1,n-ans2) cout<<a[i]<<" ";
}