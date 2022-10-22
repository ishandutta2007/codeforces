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
const int N=2e5+9;
const double e=0.0000000000001;
int n,a[N];
double l=-20000,r=20000,mid,ans;
bool check(double p){
	double sum=0,mn=0,mx=0,mini=0,maxi=0;
	f(i,0,n){
		sum+=a[i]-p;
		maxm(maxi,sum-mn);
		maxm(mini,mx-sum);
		maxm(mx,sum);
		minm(mn,sum);
	}
	ans=max(maxi,mini);
	if(maxi>mini) return 1;
	return 0;
}
int main(){
	cin>>n;
	f(i,0,n) gett(a[i]);
	f(i,0,2560){
		mid=(l+r)/2.0;
		if(check(double(mid)))
			l=mid;
		else
			r=mid;
	}
	cout << fixed << setprecision(30) << ans << endl;
}