#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=1000;
ll n,q,m,a[N][3],ans,mx[N],mn[N];
pair<int,pair<ll,ll> > p[N];
int main(){
	cin>>q;
	f(q1,0,q){
		cin>>n>>m;
		f(i,1,n+1)
			cin>>p[i].first>>p[i].S.F>>p[i].S.S;
		mx[0]=m;
		mn[0]=m;
		ans=1;
		sort(p+1,p+n+1);
		f(i,1,n+1){
			mx[i]=mx[i-1]+(p[i].first-p[i-1].F);
			mn[i]=mn[i-1]-(p[i].first-p[i-1].F);
			if(mn[i]>p[i].S.S || mx[i]<p[i].S.F)
				ans=-1;
			mx[i]=min(mx[i],p[i].S.S);
			maxm(mn[i],p[i].S.F);
		}
		if(ans==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}