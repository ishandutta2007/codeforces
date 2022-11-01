#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n;
int x, y, z;
int len, pos;
vector<vector<int> > sg;
map<vector<vector<int> >, int> mp;

ll a;
int f[4], sum;

inline int mex(int x, int y, int z){
	for(int i = 0;i <= 3;i++) if((x ^ i) && (y ^ i) && (z ^ i)) return i;
}

inline int get(ll x){
	if(x < pos) return x;
	return pos + (x - pos) % len;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &n, &x, &y, &z);
		sg.clear(), sg.push_back({0, 0, 0}), mp.clear();
		while(1){
			vector<int> v(3, 0);
			int cnt = sg.size();
			v[0] = mex(sg[max(cnt - x, 0)][0], sg[max(cnt - y, 0)][1], sg[max(cnt - z, 0)][2]);
			v[1] = mex(sg[max(cnt - x, 0)][0], sg[max(cnt - z, 0)][2], 4);
			v[2] = mex(sg[max(cnt - x, 0)][0], sg[max(cnt - y, 0)][1], 4);//debug: 
			sg.push_back(v), ++cnt;//debug:pushback++cnt 
			if(cnt >= 5){
				vector<vector<int> > vv(sg.end() - 5, sg.end());
				if(pos = mp[vv]){
					len = cnt - 4 - pos;
					break;
				}
				mp[vv] = cnt - 4;
			}
		}
		memset(f, 0, sizeof(f)), sum = 0;
		for(int i = 1;i <= n;i++){
			scanf("%lld", &a);
			int now = sg[get(a)][0], X = sg[get(max(a - x, 0ll))][0], Y = sg[get(max(a - y, 0ll))][1], Z = sg[get(max(a - z, 0ll))][2];
			sum ^= now, ++f[now ^ X], ++f[now ^ Y], ++f[now ^ Z];
		}
		printf("%d\n", f[sum]);
	}
		
}