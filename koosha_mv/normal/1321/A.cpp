#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=3e5+99;
ll n,ans=1,t2,t1,a[N],b[N];
int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
	}
	f(i,0,n){
		cin>>b[i];
		if(b[i]!=a[i]) ans=1;
	}
	f(i,0,n){
		if(a[i]==1 && b[i]==0) t1++;
		if(a[i]==0 && b[i]==1) t2++;
	}
	if(t1==0){cout<<-1;return 0;}
	t2++;
	cout<<t2/t1+(t2%t1>0);
}