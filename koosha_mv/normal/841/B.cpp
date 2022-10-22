#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=1e6+9;
ll n,s,x,a[N],k;
int main(){
	cin>>n;
	f(i,1,n+1){
		scanf("%I64d",&x);
		s+=x;
		a[i]=a[i-1]+x;
		if(a[i]%2==1)
			 k=1;
	}
	if(s%2==1 || k==1) cout<<"First";
	else cout<<"Second";
}