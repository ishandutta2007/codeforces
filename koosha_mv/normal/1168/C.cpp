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

const int N=3e5+99,lg=19;

int n,t,m,x,l,r,nr[N][lg],dp[lg],a[N],dist[N],last[lg];
string s1="Shi",s2="Fou";
queue<int> q;

bool is_bit(int x,int y){
	return (x%(1<<(y+1))>=(1<<y));
}
void make(){
	f(i,0,N) f(j,0,lg) nr[i][j]=last[j]=N-1;
	f_(i,n-1,0){
		f(j,0,lg)
			if(is_bit(a[i],j)){
				nr[i][j]=i;
				f(k,0,lg)
					minm(nr[i][k],nr[last[j]][k]);
				last[j]=i;
			}
	}
}	
string solve(int x,int y){
	f(i,0,lg)
		if(is_bit(a[y],i) && nr[x][i]<=y)
			return s1;
	return s2;
}

int main(){
	f(i,0,N)
		f(j,0,lg)
			nr[i][j]=N;
	cin>>n>>m;
	f(i,0,n) gett(a[i]);
	make();
	
	f(i,0,m){
		Gett(l,r)--l,--r;
		cout<<solve(l,r)<<'\n';
	}
}