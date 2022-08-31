#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;
const int MAXN = 100005;

vector<int> v[2][MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		int n, c; cin >> n >> c;
		vector<int> chk(c + 1);
		vector<int> sum(c + 1);
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			chk[x] = 1;
			sum[x]++;
		}
		for(int i = 1; i <= c; i++) sum[i] += sum[i - 1];
		bool good = 1;
		for(int i = 1; i <= c; i++){
			if(chk[i]) continue;
			for(int j = 1; j * i <= c; j++){
				if(chk[j] == 0) continue;
				int s = j * i;
				int e = j * (i +1) - 1;
				e = min(e, c);
				if(sum[e] != sum[s - 1]) good = 0;
			}
		}
		cout << (good ? "Yes" : "No") << "\n";
	}
}