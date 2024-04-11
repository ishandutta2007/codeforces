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
const int N=3e5+99;
ll n,ans=0,p,a[N];
int main(){
	cin>>n;
	f(i,0,n/2){
		cin>>a[i];
	}
	sort(a,a+n/2);
	f(i,0,n/2){
		ans+=abs(a[i]-(i*2+1));
	}
	f(i,0,n/2){
		p+=abs(a[i]-(i*2+2));
	}
	cout<<min(ans,p);
}