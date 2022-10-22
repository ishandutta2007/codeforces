#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;
int n, k, root = 31; 
const int maxn = 2e5 + 2, pwr = 1 << 23;

int binpow(int a, int n)
{
	int res = 1;
	while(n)
	{
		if(n&1) res = (res * a) % mod; 
		a = (a * a) % mod;
		n >>= 1; 
	}
	return res; 
}
 
void ntt(vector<int> &a, int n, bool inv)
{
	for(int i=1,j=0;i<n;i++)
	{
		int bit = n >> 1 ; 
		for(;j&bit;bit>>=1) j ^= bit; 
		j ^= bit; 
		if(i < j) swap(a[i], a[j]);
	}
	for(int l=2;l<=n;l<<=1)
	{
		int r = (inv? binpow(root, mod-2): root); 
		for(int i=l;i<pwr;i<<=1) r = (r * r) % mod; 
		
		for(int i=0;i<n;i+=l)
		{
			int w = 1;
			for(int j=0;j<l/2;j++)
			{
				int u = a[i+j], v = w * a[i+j+l/2] % mod; 
				a[i+j] = u + v < mod ? u + v: u + v - mod; // avoiding % operator 
				a[i+j+l/2] = u - v >= 0 ? u - v : u - v + mod; 
				w = (w * r * 1LL) % mod; 
			}
		}
	}
	if(inv) 
	{
		int div = binpow(n, mod-2); 
		for(auto &x:a) x = (x*div)%mod; 
	}
}
 
void mul(vector<int> &a, vector<int> b){
	for(int i = 0; i < a.size(); i++) 
	    a[i] = (a[i] * b[i]) % mod; 
}
 
void bp(vector<int> &a, int k) 
{
	vector<int> res; res.assign(a.size(), 1);
	while(k)
	{
		if(k&1) mul(res, a);
		mul(a, a); 
//		for(auto i: res) cout << i << ' '; cout << '\n';
		k >>= 1;  
	} 
	a = res; 
}
 
signed main(){
	cin >> n >> k ;
	vector<int> a(10, 0);
	
	for(int i=0, tmp;i<k;i++) {
		cin >> tmp; 
		a[tmp] = 1; 
	}
	
	int upp = 1;
	while(upp < 5*n) upp <<= 1;
	a.resize(upp); 
	
	ntt(a, upp, 0);  	
	bp(a, n/2); 
	ntt(a, upp, 1);
	 
	int res = 0; 
	for(auto i:a) res = (res + i*i%mod) % mod; 
	cout << res ;
}