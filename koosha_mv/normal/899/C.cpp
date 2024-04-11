#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll n,x,y,a,s,ans[100009],k;
int main(){
	cin>>n;
	s=(n*(n+1))/4;
	f_(i,n,1){
		if(a<s){
			ans[k]=(min(i,s-a)),k++;
			a+=(min(i,s-a));
		}
	}
	if(n%4==0 || n%4==3) cout<<0<<endl;
	else cout<<1<<endl;
	cout<<k<<" ";
	f(i,0,k)
		cout<<ans[i]<<" ";
}