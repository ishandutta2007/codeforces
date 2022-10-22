#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3e5+9;

int n,dist[N];
pair<int,int> d[N];

int main(){
	cin>>n;
	f(i,0,n){ gett(d[i].F); d[i].S=i+1; }	
	
	sort(d,d+n);
	reverse(d,d+n);
	
	f(i,0,n){
		if(i<n-1) cout<<d[i].S*2-1<<" "<<d[i+1].S*2-1<<endl;
		dist[i]=d[i].S*2-1;
	}
	f(i,0,n){
		cout<<d[i].S*2<<" "<<dist[d[i].F+i-1]<<endl;
		if(dist[d[i].F+i]==0) dist[d[i].F+i]=d[i].S*2;
	}
}