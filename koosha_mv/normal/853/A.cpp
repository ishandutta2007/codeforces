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

int n,t,a[N],b[N],k;
ll sum,ans[N],jam;
set<pair<int,int> > s;
int main(){
	cin>>n>>k;
	f(i,1,n+1) cin>>a[i];
	f(i,1,k+1){ s.insert(mp(a[i],i)); sum+=a[i]; }
	f(i,1,n+1){
		if(i+k<=n) s.insert(mp(a[i+k],i+k)),sum+=a[i+k];
		pair<int,int> p=*s.rbegin();
		s.erase(p);
		ans[i]=p.S;
		jam+=1ll*(i+k-p.S)*a[p.S];
		b[p.S]=i+k;
	}
	cout<<jam<<endl;
	f(i,1,n+1) cout<<b[i]<<" ";
	
}