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

const int N=55;

int n,m,t,ans1,ans2,a[N][N],dp[N][N];

int main(){
	cin>>t;
	while(t--){
		ans1=ans2=0;
		cin>>n>>m;
		f(i,0,n)
			f(j,0,m)
				cin>>a[i][j];
		f(i,0,n){
			int sum=0;
			f(j,0,m)
				sum+=a[i][j];
			if(sum==0) ans1++;
		}
		f(j,0,m){
			int sum=0;
			f(i,0,n)
				sum+=a[i][j];
			if(sum==0) ans2++;
		}
		minm(ans1,ans2);
		if(ans1%2) cout<<"Ashish";
		else cout<<"Vivek";
		cout<<endl;
	}
}