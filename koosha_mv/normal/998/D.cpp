#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll mark[55],n,cnt,ans=0;
int main(){
	cin>>n;
	f(i,0,50) mark[i]=1e10;
	f(i,0,49){
		f(j,0,49){
			minm(mark[(i*9+j*4)%49],i+j);
		}
	}
	f(i,0,49){
		if(mark[i]<=n)
			ans+=n-mark[i]+1;
	}
	cout<<ans;
}