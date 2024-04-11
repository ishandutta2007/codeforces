#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
ll ans,n,b,a[1000],x,z,f,t[1009],st;
int main(){
	cin>>n>>b;
	f(i,0,n){
		cin>>a[i];
		if(i>0 && f==z){
			t[st]=abs(a[i]-a[i-1]),st++;
		}
		f+=(a[i]%2==1),z+=(a[i]%2==0);
	}
	sort(t,t+st);
	f(i,0,st){
		if(b-t[i]>=0){
			b-=t[i];
			ans++;
		}
	}
	cout<<ans;
}