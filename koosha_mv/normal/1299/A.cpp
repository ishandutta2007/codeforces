#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
const int N=3e5+99;
ll n,l[N],t[N],a[N],x,sum,sfr,k=0,p;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		x=a[i];
		p=0;
		while(x){
			if(x%2==1){
				t[p]++;
				l[p]=i;
			}
			x/=2,p++;
		}
	}
	f_(i,72,0){
		if(t[i]==1){
			k=l[i];
			break;
		}
	}
	cout<<a[k]<<" ";
	f(i,0,n){
		if(i!=k) cout<<a[i]<<" ";
	}
}