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
const int N=5e5+99;
int n,t,mark[N],ans[N],anss[N],mv[N],a[N],sum,p1=2;
int main(){
	cin>>n;
	mv[n]=n;
	mark[n]=1;
	f_(i,n-1,2){
		mv[i]=mv[i+1];
		for(int j=i*2;j<=n;j+=i){
			if(mark[j]==1){
				mv[i]--;
				mark[j]=0;
			}
		}
		mark[i]=1;
	}
	f(i,2,n+1){
		while(mv[p1]<i) p1++;
		cout<<p1-1<<" ";
	}
}