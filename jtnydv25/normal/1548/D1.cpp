#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif
bool chk(vector<int> v){
	vector<int> x(3), y(3);
	for(int l = 0; l < 3; l++){
		x[l] = v[l] >> 1;
		y[l] = v[l] & 1;
	}
	int num = 0;
	for(int p = 0; p < 3; p++){
		for(int q = p + 1; q < 3; q++){
			num ^= (x[p] != x[q] || y[p] != y[q]);
		}
	}
	return num == 0;
}

ll C(int n, int k){
	ll ret = 1;
	for(int i = 1; i <= k; i++){
		ret *= n - i + 1;
		ret /= i;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n; cin >> n;
	vector<int> num(4);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		x/=2; y/=2;
		num[(x % 2) * 2 + (y % 2)]++;
	}
	ll ans = 0;
	ll bad = 0;
	for(int cnt0 = 0; cnt0 <= 3; cnt0++){
		for(int cnt1 = 0; cnt1 <= 3; cnt1++){
			for(int cnt2 = 0; cnt2 <= 3; cnt2++){
				for(int cnt3 = 0; cnt3 <= 3; cnt3++){
					if(cnt0 + cnt1 + cnt2 + cnt3 == 3){
						ll ways = C(num[0], cnt0);
						ways *= C(num[1], cnt1);
						ways *= C(num[2], cnt2);
						ways *= C(num[3], cnt3);
						if(!ways) continue;
						vector<int> vv;
						for(int i = 0; i < cnt0; i++) vv.push_back(0);
						for(int i = 0; i < cnt1; i++) vv.push_back(1);
						for(int i = 0; i < cnt2; i++) vv.push_back(2);
						for(int i = 0; i < cnt3; i++) vv.push_back(3);

						if(chk(vv)){
							ans += ways;
						} else bad += ways;
					}
				}
			}
		}
	}
	cout << ans << endl;
}