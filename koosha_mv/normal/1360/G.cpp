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

const int N=52;

int n,m,a,b,t,c,p,ans[N][N];

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>a>>b;
		c=0;
		f(i,0,n)
			f(j,0,m)
				ans[i][j]=0;
		if(n*a==m*b){
			cout<<"YES"<<endl;
			f(i,0,m){
				p=b;
				for(;p--;c=(c+1)%n)
					ans[c][i]=1;
			}
			f(i,0,n){
				f(j,0,m)
					cout<<ans[i][j];
				cout<<endl;
			}	
		}
		else cout<<"NO"<<endl;
	}
}