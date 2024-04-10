#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n;
ll pw[201000];
int main() {
	scanf("%d",&n);
	pw[0]=1;
	for (int i=1;i<=n;i++) pw[i]=pw[i-1]*10%mod;
	for (int i=1;i<=n;i++) {
		if (i==n) { puts("10"); continue; }
		int d=0;
		if (i<=n-2) d=(d+10*(n-i-1)*9*9*pw[n-i-2])%mod;
		d=(d+2*10*9*pw[n-i-1])%mod;
		printf("%d ",d);
	}
}