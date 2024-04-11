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
 
const int N=8009;

int n,t,a[N],mark[N];

int main(){
	cin>>t;
	while(t--){
		int ans=0;
		fill(mark,mark+n+5,0);
		cin>>n;
		f(i,1,n+1){ gett(a[i]); a[i]+=a[i-1]; }
		f(i,0,n+1)
			f(j,0,i-1)
				if(a[i]-a[j]<=n) mark[a[i]-a[j]]=1;
		f(i,1,n+1)
			if(mark[a[i]-a[i-1]]==1) ans++;
		cout<<ans<<endl;
	}
}