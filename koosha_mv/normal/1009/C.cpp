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
ll n,t,x,y,m,mid,e,ans;
int main(){
	cin>>n>>m;
	mid=n/2+1;
	e+=mid*(mid-1)/2;
	if(n%2==0) mid--;
	e+=(mid*(mid-1))/2;
	f(i,0,m){
		Get(x,y);
		ans+=x*n;
		if(y>=0)
			ans+=n*(n-1)/2*y;
		else
			ans+=e*y;
	}
	double p=double(ans)/double(n);
	cout << fixed << setprecision(30) << p << endl;
}