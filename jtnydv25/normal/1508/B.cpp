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
#endif

const ll INF = 1LL << 60;

ll mul2(ll x){
	return min(INF, 2 * x);
}

const int N = 100005;
ll powers[N];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	powers[0] = 1;
	for(int i = 1; i < N; i++) powers[i] = mul2(powers[i - 1]);
	int t; cin >> t;
	while(t--){
		int n; ll k;
		cin >> n >> k;
		if(k > powers[n - 1]){
			cout << -1 << "\n";
			continue;
		}
		vector<int> perm(n + 1);
		iota(all(perm), 0);
		int i = 1;
		while(i <= n){
			for(int j = i; j <= n; j++){
				// [i, j]
				ll num = j == n ? 1 : powers[n - 1 - j];
				if(num >= k){
					reverse(perm.begin() + i, perm.begin() + j + 1);
					i = j + 1;
					break;
				} else{
					k -= num;
				}
			}
		}
		for(int i = 1; i <= n; i++) cout << perm[i] << " ";
		cout << "\n";
	}
}