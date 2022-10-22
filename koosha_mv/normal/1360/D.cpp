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

int n,t,k,a[N];

int solve(int x){
	if(x>k) return n;
	return n/x;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		int ans=n;
		for(int i=1;i*i<=n;i++)
			if(n%i==0){
				minm(ans,solve(i));minm(ans,solve(n/i));
			}
		cout<<ans<<endl;
	}
}