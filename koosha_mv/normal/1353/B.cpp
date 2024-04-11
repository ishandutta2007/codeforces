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

const int N=5e5+9;

int n,a[N],b[N],k,t;
ll ans;

int main(){
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>k;
		f(i,0,n) cin>>a[i];
		f(i,0,n) cin>>b[i];
		sort(a,a+n);
		sort(b,b+n);
		reverse(b,b+n);
		f(i,0,k)
			if(b[i]>a[i])
				swap(a[i],b[i]);
		f(i,0,n) ans+=a[i];
		cout<<ans<<endl;
	}
}