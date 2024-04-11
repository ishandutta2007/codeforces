#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+99;

int n,k,t,l,r=1e9+1,mid,a[N];

bool check(int x){
	bool last=0;
	int now=0,ans=0,c=0;
	if(k%2==0){
		ans=0;
		f(i,0,n-1){
			if(a[i]<=x && last==0)
				last=1,ans++;
			else
				last=0;
		}
		last=0;
		f(i,1,n){
			if(a[i]<=x && last==0)
				last=1,c++;
			else
				last=0;
		}
		maxm(ans,c);
		if(ans>=k/2) return 1;
		return 0;
	}
	f(i,1,n-1){
		if(a[i]<=x && last==0)
			last=1,ans++;
		else
			last=0;
	}
	last=0;
	f(i,0,n){
		if(a[i]<=x && last==0)
			last=1,c++;
		else
			last=0;
	}
	if(ans>=k/2 || c>k/2) return 1;
	return 0;
}
int main(){
	cin>>n>>k;
	f(i,0,n) gett(a[i]);
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r;
}