#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=1e3+9;
int n,a[N],ans[N][N],m[N][2],g[N],e;
vector<pair<int,int> > p;
pair<int,int> k;
int solve(int x,int y){
	return min(x-1,y);
}
int main(){
	cin>>n;
	f(i,1,n+1)
		cin>>a[i];
	p.pb(mp(1,n+2));
	f(i,1,n+1){
		while(p[p.size()-1].S-p[p.size()-1].F==1)
			p.pop_back();
		m[i][0]=p[p.size()-1].F;
		m[i][1]=p[p.size()-1].S;
		e=solve(m[i][1]-m[i][0],a[i]);
		a[i]-=e;
		f(j,m[i][0],m[i][0]+e)
			ans[i][j]=1;
		k=p[p.size()-1];
		p.pop_back();
		p.pb(mp(m[i][0],m[i][0]+e));
		p.pb(mp(m[i][0]+e,m[i][1]));
	}
	f(i,1,n+1){
		f(j,1,n+2){
			if(a[i] && (j<m[i][0] || j>=m[i][1]))
				ans[i][j]=1,a[i]--;
		}
	}
	cout<<n+1<<endl;
	f(i,1,n+2){
		f(j,1,n+1)
			cout<<ans[j][i];
		cout<<endl;
	}
}