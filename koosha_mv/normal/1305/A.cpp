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
const int N=5e5+9;
ll n,a[N],b[N],t;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n;
		f(i,0,n) cin>>a[i];
		f(i,0,n) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		f(i,0,n) cout<<a[i]<<" ";
		cout<<endl;
		f(i,0,n) cout<<b[i]<<" ";
		cout<<endl;
	}
}