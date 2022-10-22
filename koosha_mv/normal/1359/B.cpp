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

const int N=5e5+99;

int t,n,m,x,y;
char c;

int main(){
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n>>m>>x>>y;
		minm(y,x*2);
		f(i,0,n){
			int last=0;
			f(j,0,m){
				cin>>c;
				if(c=='.'){
					if(last==1) ans=ans-x+y,last=0;
					else ans+=x,last=1;
				}
				else last=0;
			}
		}
		cout<<ans<<endl;
	}
}