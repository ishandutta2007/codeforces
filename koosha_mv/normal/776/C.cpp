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
 
const ll N=5e5+9,inf=1e15;

ll t,n,k,a[N],ans;
map<ll,int> mark;

int main(){
	cin>>n>>k;
	mark[0]=1;
	f(i,1,n+1){
		cin>>a[i];
		a[i]+=a[i-1];
		if(k==1 || k==-1){
			if(k==-1) ans+=mark[a[i]+1];
			ans+=mark[a[i]-1];
		}
		else
			for(ll p=1;p<=inf;p*=k)
				ans+=mark[a[i]-p];
		mark[a[i]]++;
	}
	cout<<ans;
}