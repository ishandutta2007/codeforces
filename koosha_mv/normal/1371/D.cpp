#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define SZ(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=400;

int n,k,t,p,x,y,a[N][N];
ll ans;

int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		f(i,0,n) f(j,0,n) a[i][j]=0;
		x=0,y=0,p=0;
		f(q,0,k){
			if(p==n) x++,p=0;
			a[x][y]=1;
			x=(x+1)%n;
			y=(y+1)%n;
			p++;
		}
		ans=0;
		if(k%n!=0) ans=2;
		cout<<ans<<endl;
		f(i,0,n){
			f(j,0,n)
				cout<<a[i][j];
			cout<<endl;	
		}
	}
}