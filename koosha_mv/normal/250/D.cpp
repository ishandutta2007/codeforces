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
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=1e5+9;
int n,m,a,b,x,l,r,mid,ans1,ans2,p,A[N],B[N];
double ans=1e9;
double Get_ans(int p1,int x){
	double k=sqrt(double(1ll*a*a+1ll*A[p1]*A[p1]));
	k+=(double(sqrt(1ll*(A[p1]-x)*(A[p1]-x)+1ll*(b-a)*(b-a))));
	return k;
}
int solve(int x){
	l=-1,r=n-1;
	while(l+1<r){
		mid=(l+r)/2;
		if(Get_ans(mid,x)>=Get_ans(mid+1,x))
			l=mid;
		else
			r=mid;
	}
	return r;
}
int main(){
	Gett(n,m);
	Gett(a,b);
	f(i,0,n)
		gett(A[i]);
	f(i,0,m)
		gett(B[i]);
	f(i,0,m){
		gett(x);
		p=solve(B[i]);
		if(Get_ans(p,B[i])+x<ans){
			ans=Get_ans(p,B[i])+x;
			ans1=p+1;
			ans2=i+1;
		}
	}
	cout<<ans1<<" "<<ans2;
}