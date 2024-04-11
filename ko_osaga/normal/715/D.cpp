#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;

int cnt[38];

struct wall{
	int sx, sy, ex, ey;
};

vector<wall> v;

int main(){
	lint t;
	cin >> t;
	printf("42 42\n");
	for(int i=0; i<38; i++){
		cnt[i] = t % 3;
		t /= 3;
	}
	assert(t == 0);
	v.push_back({40, 41, 40, 42});
	v.push_back({41, 41, 41, 42});
	v.push_back({41, 40, 42, 40});
	v.push_back({41, 41, 42, 41});
	for(int i=1; i<=37; i++){
		v.push_back({i, i+4, i, i+5});
		v.push_back({i+4, i, i+5, i});
	}
	for(int i=1; i<=39; i++){
		if(i < 39) v.push_back({i, i+3, i+1, i+3});
		if(i < 39) v.push_back({i+3, i, i+3, i+1});
		if(i == 39 || cnt[i-1] <= 1){
			v.push_back({i+2, i, i+3, i});
		}
		if(i == 39 || cnt[i-1] <= 0){
			v.push_back({i, i+2, i, i+3});
		}
	}
	printf("%d\n", v.size());
	for(auto &i : v){
		if(i.sx + i.sy > i.ex + i.ey) swap(i.sx, i.ex), swap(i.sy, i.ey);
		printf("%d %d %d %d\n", i.sx, i.sy, i.ex, i.ey);
	}
}