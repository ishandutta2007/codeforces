#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=105,mod=1e9+7;
int n,a[N],t,p;
int main(){
	cin>>t;
	f(q,0,t){
		cin>>n;
		int k=1;
		f(i,0,n) cin>>a[i];
		f(i,0,n-1){
			if(a[i]%2!=a[i+1]%2)
				k=0;
		}
		if(k) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}