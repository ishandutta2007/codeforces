#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e5+9;
ll n,x,y,t,k;
ll saghf(ll x,ll y){
	return (x/y)+(x%y>0);
}
int main(){
	cin>>t;
	f(q,0,t){
		cin>>x>>y;
		k=0;
		ll p=sqrt(y);
		f(i,max((ll)0,p-2),p+3){
			f(j,max((ll)0,p-2),p+3){
				if(i*j>=y && i+j-1<=x)
					k=1;
			}
		}
		if(k==1 || x>=y)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}