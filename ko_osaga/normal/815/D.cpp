#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

struct rect{
	int x, y, z;
	bool operator<(const rect &r)const{
		return make_tuple(x, y, z) < make_tuple(r.x, r.y, r.z);
	}
};

int n, p, q, r;
vector<rect> v;

void add_rect(int x, int y, int z){
	v.push_back({x, y, z});
}

map<int, int> mp;

lint solve(){
	sort(v.begin(), v.end());
	int prevx = 1e9;
	lint area = 0;
	lint ret = 0;
	mp[0] = 1e9;
	mp[1e9] = 0;
	vector<rect> p = v;
	for(int i=p.size()-1; i>=0; i--){
		ret += 1ll * (prevx - p[i].x) * area;
		int e = i;
		while(e >= 0 && p[e].x == p[i].x){
			e--;
		}
		for(int j=e+1; j<=i; j++){
			auto it = mp.lower_bound(p[j].y);
			if(it->second >= p[j].z){
				continue;
			}
			int prevz = it->second;
			it--;
			while(it != mp.begin() && it->second <= p[j].z){
				area += 1ll * (it->second - prevz) * (p[j].y - it->first);
				prevz = it->second;
				auto nxt = it;
				nxt--;
				mp.erase(it);
				it = nxt;
			}
			area += 1ll * (p[j].z - prevz) * (p[j].y - it->first);
			mp[p[j].y] = p[j].z;
		}
		prevx = p[i].x;
		i = e+1;
	}
	ret += 1ll * prevx * area;
	return ret;
}

int main(){
	scanf("%d %d %d %d",&n,&p,&q,&r);
	for(int i=0; i<n; i++){
		int x, y, z;
		scanf("%d %d %d",&x,&y,&z);
		add_rect(x, y, r);
		add_rect(x, q, z);
		add_rect(p, y, z);
	}
	cout << 1ll * p * q * r - solve();
}