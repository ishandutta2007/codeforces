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

const int N=53;

int n,t;
char a[N][N],x;

int main(){
	cin>>t;
	while(t--){
		int ans=1;
		cin>>n;
		f(i,0,n+1)
			f(j,0,n+1){
				if(i==n || j==n) a[i][j]='1';
				else cin>>a[i][j];
			}
		f(i,0,n)
			f(j,0,n)
				if(a[i][j]=='1' && a[i+1][j]=='0' && a[i][j+1]=='0') ans=0;
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}