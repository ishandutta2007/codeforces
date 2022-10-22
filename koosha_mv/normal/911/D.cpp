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
int n,q,m,x,y,a[1600];
bool ans;
int main(){
	cin>>n;
	f(i,0,n) cin>>a[i];
	f(i,0,n){
		f(j,i+1,n)
			if(a[j]<a[i]) ans=!ans;
	}
	cin>>m;
	f(i,0,m){
		cin>>x>>y;
		if((y-x+1)%4>=2) ans=!ans;
		if(ans) cout<<"odd"<<endl;
		else cout<<"even"<<endl;
	}
}