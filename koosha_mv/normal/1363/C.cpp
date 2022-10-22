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

const int N=5000;

int n,t,x,y,u,deg[N];

int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>u;
		f(i,1,n+1) deg[i]=0;
		f(i,1,n){
			cin>>x>>y;
			deg[x]++,deg[y]++;
		}
		if(deg[u]==1 || n==1) cout<<"Ayush"<<endl;
		else
			cout<<(n%2 ? "Ashish":"Ayush")<<endl;
	}
}