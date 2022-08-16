#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

struct Zeros{
	int z, zz, zzz;
	bool operator < (const Zeros &o){
		if(zzz > o.zzz) return 1;
		if(o.zzz > zzz) return 0;
		return zz > o.zz;
	}
};

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; ll a, b, c;
		cin >> n >> a >> b >> c;
		vector<Zeros> zeros;
		int OO = 0, ZZ = 0;
		string s; cin >> s;
		for(int i = 0; i < n;){
			int j = i;
			while(s[i] == s[j] && i < n)i++;
			if(s[j] == '0'){
				int z = 1, zz = i - j - 1, zzz = 0;
				if(i == n || j == 0){
					z = 0; zzz = 1;
				}
				ZZ += zz;
				zeros.push_back({z, zz, zzz});
			} else OO += i - j - 1;
		}
		sort(all(zeros));
		ll ans = 0;
		for(int h = 0; h < 2; h++){
			ll val = 0;
			vector<Zeros> D = zeros;
			int zz = ZZ, oo = OO;
			for(int m = h; ;){
				ans= max(ans, val);
				if(m == 0){
					if(!oo)break;
					else{
						oo--;
						val += b;
					}
					m^=1;
				} else{
					if(D.empty()) break;
					else if(D.back().zz > 0){
						D.back().zz--;
						zz--;
						val += a;
						m^=1;
					} else if( (D.back().z + D.back().zzz) > 0){
						// don't take ?
						int max_zeros = min(oo + 1, zz);
						int max_ones = min(zz, oo);
						ans = max(ans, val + a * 1LL * max_zeros + b * 1LL * max_ones);
						// take ?
						val -= c;
						if(D.back().z > 0) oo++;
						D.pop_back();
						m^=1;
					} else{
						D.pop_back();
					}
				}
			}
			ans = max(ans, val);
		}
		cout << ans << endl;
	}
}