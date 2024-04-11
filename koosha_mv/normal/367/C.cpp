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
const int N=1e5+9;
ll n,m,a[N],x,ans;
ll calc(ll x){
	return (x*(x-1)/2)+1+((x%2==0)*(x/2-1));
}
int main(){
	Get(n,m);
	f(i,0,m)
		Get(x,a[i]);
	sort(a,a+m);
	f_(i,m-1,0){
		if(calc(m-i)>n)
			break;
		ans+=a[i];
	}
	cout<<ans;
}