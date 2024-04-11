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

int n,t,a[N],ans[N],p1,p2;
set<int> s;
int main(){
	fill(ans,ans+N,-1);
	cin>>n;
	f(i,0,n+1) s.insert(i);
	f(i,0,n+1){
		if(i<n)
			cin>>a[i];
		else
			a[i]=n+1;
		if(i>0 && a[i]>a[i-1]){
			ans[i]=a[i-1],s.erase(a[i-1]);
		}
	}
	f(i,0,n){
		if(ans[i]==-1){
			ans[i]=*s.begin();
			s.erase(ans[i]);
		}
		cout<<ans[i]<<" ";
	}
}