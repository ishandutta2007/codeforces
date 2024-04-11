#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
ll n;
int main(){
	cin>>n;
	if(n%3==0)
		cout<<1<<" "<<1<<" "<<n-2;
	else{
		cout<<2<<" "<<1<<" "<<n-3;
	}
}