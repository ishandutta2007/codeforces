#include <bits/stdc++.h>
#include<algorithm>
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
const int N=5005,mod=1e9+7;
int n,t,a[N],mn[N],mx[N];
int main(){
	cin>>t;
	f(q,0,t){
		f(i,0,N) mn[i]=1e5,mx[i]=-1;
		int ans=0;
		cin>>n;
		f(i,0,n) cin>>a[i];
		f(i,0,n){
			mx[a[i]]=i;
			minm(mn[a[i]],i);
		}
		f(i,0,n+2){
			if(mx[i]!=-1 && mx[i]>mn[i]+1)
				ans=1;
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}