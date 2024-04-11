#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2e5+9;
ll n,mn=1e13,a[2];
int main(){
	cin>>n;
	f(i,1,1e6+2){
		ll o=n/i;
		if(__gcd(o,i)==1 && max(o,i)<mn && n%i==0){
			mn=max(o,i),a[0]=o,a[1]=i;
		}
	}
	cout<<a[0]<<" "<<a[1];
}