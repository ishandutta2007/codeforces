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
const int N=1e5+9;
int n,p,t,r,l;
double a[N],ans,y=1;
int main(){
	cout.precision(7);
	cin>>n>>p;
	f(i,0,n){
		cin>>l>>r;
		t=(r/p)-((l-1)/p);
		a[i]=double(t)/double(r-l+y);
		a[i]=y-a[i];
	}
	f(i,0,n)
		ans+=(a[i]*a[(i+1)%n]);
	ans=double(n)-ans;
	cout<<ans*double(2000)<<endl;
}