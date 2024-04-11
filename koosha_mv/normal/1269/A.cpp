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
	if(n==1){cout<<9<<" "<<8;return 0;}
	cout<<n*4<<" "<<n*3;
}