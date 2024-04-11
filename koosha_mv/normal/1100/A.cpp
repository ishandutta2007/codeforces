#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
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
const int N=3e5+9;
int n,k,a[N],t1,t2,ans,g1,g2;
int main(){
	cin>>n>>k;
	f(i,0,n){
		cin>>a[i];
		g1+=(a[i]==1);
	}
	g2=n-g1;
	f(i,0,k){
		t1=0,t2=0;
		f(l,0,n){
			if(l%k==i){
				t1+=(a[l]==1);
				t2+=(a[l]==-1);
			}
		}
		maxm(ans,abs((g1-t1)-(g2-t2)));
	}
	cout<<ans;
}