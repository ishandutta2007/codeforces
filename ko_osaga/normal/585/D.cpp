#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int MAXN = 105;

struct tp{
	int x, y, z, sum;
	lint v;
	bool operator<(const tp &t)const{
		return make_tuple(x, y, z, -sum) < make_tuple(t.x, t.y, t.z, -sum);
	}
};

int n, a[25][3];
lint pw[26];

vector<tp> l, r;

void bktk(int s, int e, int x, int y, int z, int FuckingBoring, lint v, vector<tp> &ret){
	if(s == e){
		ret.push_back({x, y, z, FuckingBoring, v});
		return;
	}
	bktk(s+1, e, x + a[s][0] - a[s][1], y + a[s][1], z - a[s][0], 
			FuckingBoring + a[s][0] + a[s][1], v + 0 * pw[s], ret);
	bktk(s+1, e, x - a[s][1], y + a[s][1] - a[s][2], z + a[s][2],
			FuckingBoring + a[s][1] + a[s][2], v + 1 * pw[s], ret);
	bktk(s+1, e, x + a[s][0], y - a[s][2], z + a[s][2] - a[s][0],
			FuckingBoring + a[s][0] + a[s][2], v + 2 * pw[s], ret);
}

void trace(lint x){
	for(int i=0; i<n; i++){
		if(x % 3 == 0) puts("LM");
		if(x % 3 == 1) puts("MW");
		if(x % 3 == 2) puts("LW");
		x /= 3;
	}
}

int main(){
	pw[0] = 1;
	cin >> n;
	for(int i=0; i<n; i++){
		pw[i+1] = pw[i] * 3;
		for(int j=0; j<3; j++){
			cin >> a[i][j];
		}
	}
	bktk(0, n/2, 0, 0, 0, 0, 0, l);
	bktk(n/2, n, 0, 0, 0, 0, 0, r);
	for(auto &i : r){
		i.x *= -1;
		i.y *= -1;
		i.z *= -1;
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	int p = 0;
	lint ans = -1e9;
	lint mask = -1;
	for(auto &i : l){
		while(p < r.size() && make_tuple(r[p].x, r[p].y, r[p].z) < make_tuple(i.x, i.y, i.z)) p++;
		if(p < r.size() && r[p].x == i.x && r[p].y == i.y && r[p].z == i.z){
			if(ans < r[p].sum + i.sum){
				ans = r[p].sum + i.sum;
				mask = r[p].v + i.v;
			}
		}
	}
	if(mask == -1) puts("Impossible");
	else trace(mask);
}