#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i<b;i+=2)
#define ll long long
long long n,s,sum=0,ar[200000],i,m=0;
int main() {
	cin >> n >> s;
	f(i,0,n){cin >> ar[i];sum += ar[i];}
	f (i,0,n)cout<<max(s-sum+ar[i]-1,1LL*0)+max(ar[i]-s+n-1,1LL*0)<<" ";
}