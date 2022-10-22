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
const int N=2e5+99;
ll t,n,k,ans1,ans2;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n>>k;
		ll l=0,r=n+1,mid;
		while(l+1<r){
			mid=(l+r)/2;
			if(mid*(mid+1)/2<k)
				l=mid;
			else r=mid;
		}
		ans1=n-l-2;
		ans2=n-(k-(l*(l+1))/2);
		f(i,0,n){
			if(i!=ans1 && i!=ans2) cout<<'a';
			else cout<<'b';
		}
		cout<<endl;
	}
}