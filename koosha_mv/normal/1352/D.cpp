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

int n,t,a[N],ans,d1,d2;

void solve(int l,int r,int last,bool turn){
	ans++;
	if(r<l) return ;
	if(turn){
		int sum=0;
		int i;
		for(i=r;i>=l && sum<=last;i--)
			sum+=a[i],d2+=a[i];
		solve(l,i,sum,!turn);
	}
	else{
		int sum=0;
		int i;
		for(i=l;i<=r && sum<=last;i++)
			sum+=a[i],d1+=a[i];
		solve(i,r,sum,!turn);
	}
}
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n;
		f(i,0,n) cin>>a[i];
		d1=a[0];
		d2=0;
		ans=0;
		solve(1,n-1,a[0],1);
		cout<<ans<<" "<<d1<<" "<<d2<<endl;
	}
}