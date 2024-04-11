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

const int N=70;

int n,m,t,x,ans,a[N][N],mark1[N],mark0[N];

int main(){
	cin>>t;
	f(q,0,t){
		f(i,0,N) mark0[i]=0,mark1[i]=0;
		cin>>n>>m;
		ans=0;
		f(i,0,n) 
			f(j,0,m){
				cin>>a[i][j];
				if((n+m)%2!=0 || (i+j)*2+2!=n+m){
					x=min(i+j,n+m-2-(i+j));
					if(a[i][j]==0) mark0[x]++;
					else mark1[x]++;
				}
			}
		f(i,0,N)
			ans+=min(mark1[i],mark0[i]);
		cout<<ans<<endl;
		
	}
}