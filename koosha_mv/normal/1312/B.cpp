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
const int N=200;
ll n,t,m,a[N];
int main(){
	cin>>t;
	
	f(q,0,t){
		cin>>n;
		f(i,0,n) cin>>a[i];
		sort(a,a+n);
		f_(i,n-1,0) cout<<a[i]<<" ";
		cout<<endl;
	}
}