#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll t,b,c,a[3];
int main(){
	cin>>t;
	f(sal,0,t){
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[2]>a[1]+a[0]+1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}