#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define X first
#define Y second

#define pb push_back

const int K = 500000;

int n, P, Q, R;
vector<pii> v[K + 1];
set<pii> s;
ll c, r;

int main(){
	scanf("%d%d%d%d", &n, &P, &Q, &R);
	for(int i = 0, x, y, z; i < n; i++){
		scanf("%d%d%d", &x, &y, &z);
		v[R].pb({x, y});
		v[z].pb({P, y});
		v[z].pb({x, Q});
	}
	s.insert({0, K + 1});
	s.insert({K + 1, 0});
	for(int i = R; i >= 1; i--){
		for(auto &p : v[i]){
			auto it = s.lower_bound(p);
			if(it->Y >= p.Y) continue;
			int fy = it->Y;
			int ly = fy;
			for(it--; it->Y <= p.Y ; ){
				c -= 1LL * it->X * (it->Y - ly);
				ly = it->Y;
				auto itt = it;
				it--;
				s.erase(itt);		
			}
			c += 1LL * p.X * (p.Y - fy) - 1LL * it->X * (p.Y - ly);
			s.insert(p);
		}
		r += c;
	}
	printf("%lld\n", 1LL * P * Q * R - r);
}