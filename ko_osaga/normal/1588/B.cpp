#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 1600;

lint query(int s, int e){
	cout << "? " << s << " " << e << endl;
	lint x; cin >> x; return x;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int s = 1, e = n;
		while(s != e){
			int m = (s + e) / 2;
			if(query(1, m)) e = m;
			else s = m + 1;
		}
		// [1, s] have inversion >= 1
		int ai = s - 1;
		lint delta = query(ai, n) - query(ai + 1, n);
		int aj = ai + delta + 1;
		lint total = query(aj, n);
		int ak = aj;
		{
			lint s = 1, e = n;
			while(s != e){
				lint m = (s + e) / 2;
				if(m * (m - 1) / 2 >= total) e = m;
				else s = m + 1;
			}
			ak += s - 1;
		}
		cout << "! " << ai <<  " " << aj << " " <<  ak << endl;
	}

}