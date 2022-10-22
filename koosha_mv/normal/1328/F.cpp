#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops cout<<"!"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
const int N=2e5+9;
ll n,k,a[N],b1[N],b2[N],ans=1e16;
map<int,int> mark;
int main(){
	Get(n,k);
	f(i,0,n) get(a[i]);
	sort(a,a+n);
	mark[a[0]]++;
	f(i,1,n)
		b1[i]=b1[i-1]+i*(a[i]-a[i-1]),mark[a[i]]++;
	f_(i,n-2,0)
		b2[i]=b2[i+1]+(a[i+1]-a[i])*(n-1-i);
	f(i,0,n){
		if(mark[a[i]]>=k) ans=0;
		minm(ans,b1[i]+b2[i]-n+k);
		if(i>=k-1)
			minm(ans,b1[i]-(i+1-k));
		if(k<=n-i){
			minm(ans,b2[i]-((n-i)-k));
		}
	}
	cout<<max(ans,1ll*0)<<endl;
}