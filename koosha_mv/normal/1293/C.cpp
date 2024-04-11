#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=42;
ll n,q,mark[3][200009],t,x,y;
ll mv(ll x,ll y){
	return (mark[3-x][y]+mark[3-x][y-1]+mark[3-x][y+1]);
}
int main(){
	cin>>n>>q;
	f(i,0,q){
		cin>>x>>y;
		if(mark[x][y]==1)
			t-=mv(x,y);
		else
			t+=mv(x,y);
		mark[x][y]=!mark[x][y];
		if(t>0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}