#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)1e9 + 7;
const LL NS = (LL)54;
LL T, A, B;
vector<pair<LL, LL>> vc;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T--){
		cin >> A >> B;
		if(A % B){
			cout << A << '\n';
		}
		else{
			vc.clear();
			for(LL i = 2; i * i <= B; ++i){
				if(B % i == 0){
					vc.push_back({i, 0});
					while(B % i == 0){
						vc[(int)vc.size() - 1].second += 1;
						B /= i;
					}
				}
			}
			if(B > 1){
				vc.push_back({B, 1});
			}
			LL ans = 0;
			for(auto&i:vc){
				LL val = 1;
				LL b = A;
				LL cnt = i.second - 1;
				while(b % i.first == 0){
					b /= i.first;
					if(cnt){
						val *= i.first;
						--cnt;
					}
				}
				ans = max(ans, val * b);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}