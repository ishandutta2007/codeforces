#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
//typedef pair<int, int> pi;
const int MAXN = 200005;

struct expr{
	string s;
	int type;
	int mask;
	bool operator<(const expr &e)const{
		return make_pair(s.size(), s) > make_pair(e.s.size(), e.s);
	}
};

priority_queue<expr> pq;
bool vis[256][3];
string ans[256][3];

int main(){
	pq.push({"x", 2, 240});
	pq.push({"y", 2, 204});
	pq.push({"z", 2, 170});
	while(!pq.empty()){
		auto x = pq.top();
		pq.pop();
		if(vis[x.mask][x.type]) continue;
		vis[x.mask][x.type] = 1;
		ans[x.mask][x.type] = x.s;
		if(x.type == 0){
			pq.push({"(" + x.s + ")", 2, x.mask});
			for(int j=0; j<256; j++){
				if(vis[j][1]){
					pq.push({x.s + "|" + ans[j][1], 0, x.mask | j});
				}
			}
		}
		if(x.type == 1){
			pq.push({x.s, 0, x.mask});
			for(int j=0; j<256; j++){
				if(vis[j][0]){
					pq.push({ans[j][0] + "|" + x.s, 0, x.mask | j});
				}
				if(vis[j][2]){
					pq.push({x.s + "&" + ans[j][2], 1, x.mask & j});
				}
			}
		}
		if(x.type == 2){
			pq.push({"!" + x.s, 2, 255 ^ x.mask});
			pq.push({x.s, 1, x.mask});
			for(int j=0; j<256; j++){
				if(vis[j][1]){
					pq.push({ans[j][1] + "&" + x.s, 1, x.mask & j});
				}
			}
		}
	}
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int i = 0;
		for(int j=0; j<8; j++) if(s[j] & 1) i |= (1<<j);
		vector<string> ret;
		for(int j=0; j<3; j++) if(vis[i][j]) ret.push_back(ans[i][j]);
		cout << *min_element(ret.begin(), ret.end(), [&](const string &a, const string &b){
			return make_pair(a.size(), a) < make_pair(b.size(), b);
		}) << endl;
	}
}