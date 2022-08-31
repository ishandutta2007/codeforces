#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXT = 270000;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> a[i];
	int zerpos = find(all(a), 1) - a.begin();
	if(zerpos < n){
		bool ok = 1;
		for(int i = 0; i < zerpos; i++){
			if(a[i] && a[i] <= n - zerpos + i + 1){
				ok = 0;
			}
		}
		for(int i = zerpos; i < n; i++){
			if(a[i] != i - zerpos + 1) ok = 0;
		}
		if(ok){
			cout << zerpos << "\n";
			return 0;
		}
	}
	multiset<int> s;
	for(int i = 0; i < n; i++){
		if(a[i]) s.insert(a[i] - i - 1);
	}
	for(int i = 0; i <= n; i++){
		if(sz(s) == 0 || *s.begin() > -i){
			cout << i + n << endl;
			break;
		}
		if(a[i]) s.erase(s.find(a[i] - i - 1));
	}
}