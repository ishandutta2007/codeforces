#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//miller rabin primality 7 set for 64 bit int {2, 325, 9375, 28178, 450775, 9780504, 1795265022}
#define abs(x) ((x)>0?(x):-(x))
#define max(x,y)(x>y?x:y)
#define rep(i,start,lim) for(int i=start;i<=lim;i++)
#define repr(i,start,lim) for(int i=start;i>=lim;i--)
#define scan(x) scanf("%lld",&x)
#define print(x) printf("%lld ",x)
#define br printf("\n")
#define ss string
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pll pair<int,int>
#define MOD         1000000007
#define PI          3.14159265358979323
#define INF 1000000000LL * 1000000000
#define f first
#define s second
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define endl '\n'
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long int
typedef long double ld;

int32_t main(){
	sync;int n,k;cin>>n>>k;
	vector<int> a(n);
	for(auto &it:a)cin>>it;
	sort(a.begin(), a.end());
	if(k==n)return cout<<a[k-1],0;
	if(k==0){
		int x=a[k]-1;return cout<<(x>=1?x:-1),0;

	}
	int x=a[k-1];
	cout<<(x==a[k]?-1:x);
	
	return 0;
}