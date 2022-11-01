#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int N;
vector<pair<int, int>> v;

int main () {
	scanf("%d", &N);
	v.PB(MP(0, 0));
	fo(z, 0, N) {
		int s, d;
		scanf("%d %d", &s, &d);
		int e = s+d-1;

		bool bad = 0;
		fo(i, 0, (int) v.size()) {
			if (s > v[i].second || e < v[i].first) continue;
			bad = 1; break;
		}

		if (bad) {
			fo(i, 0, (int) v.size()) {
				if ((i+1 == (int) v.size() || v[i+1].first > v[i].second+d)) {
					v.PB(MP(v[i].second+1, v[i].second+d));
					printf("%d %d\n", v[i].second+1, v[i].second+d);
					sort(v.begin(), v.end());
					break;
				}
			}
		} else {
			v.PB(MP(s, e));
			printf("%d %d\n", s, e);
			sort(v.begin(), v.end());
		}
	}
	return 0;
}