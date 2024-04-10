//In the name of GOD
#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
const ll tof = 1100;
const ll tof2 = 91;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, q;
long long a[maxn], k[maxn], s[maxn], s1[maxn], s2[maxn], s3[maxn];
ll cnt[maxn][tof2];
vector<ll> b[maxn], vec;

int main(){
	fast_io;
	char ch;
	long long v, x, p1, p2;
	
	cin >> n >> m >> q;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(ll i = 1; i <= m; i++){
		cin >> k[i];
		b[i].resize(k[i]);
		for(ll j = 0; j < k[i]; j++){
			cin >> b[i][j];
			s[i] += a[b[i][j]];
		}
		sort(b[i].begin(), b[i].end());
		if(b[i].size() > tof) vec.pb(i);
	}
	for(ll j = 1; j <= m; j++){
		for(ll i = 0; i < vec.size(); i++){
			v = vec[i];
			p1 = 0;
			p2 = 0;
			while(p1 < b[v].size() && p2 < b[j].size()){
				if(b[v][p1] == b[j][p2]){
					cnt[j][i]++;
					p1++;
					p2++;
				}
				else if(b[v][p1] < b[j][p2]) p1++;
				else p2++;
			}
		}
	}
	for(ll i = 0; i < q; i++){
		cin >> ch >> v;
		if(ch == '?'){
			if(b[v].size() > tof) cout << s2[v] + s[v] << '\n';
			else{
				x = s[v];
				for(ll j = 0; j < b[v].size(); j++){
					x += s1[b[v][j]];
				}
				for(ll j = 0; j < vec.size(); j++){
					x += s3[vec[j]] * cnt[v][j];
				}
				cout << x << '\n';
			}
		}
		else{
			cin >> x;
			for(ll j = 0; j < vec.size(); j++){
				s2[vec[j]] += cnt[v][j] * x;
			}
			if(b[v].size() > tof) s3[v] += x;
			else{
				for(ll j = 0; j < b[v].size(); j++){
					s1[b[v][j]] += x;
				}
			}
		}
	}
	
	
	return 0;
}