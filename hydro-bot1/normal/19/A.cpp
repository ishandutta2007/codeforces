// Hydro submission #621cb9e3cdb5d839880bd46f@1646049764516
#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;

const int MAXN = 200100;
typedef long long ll;

struct node{
	int score, balls, overballs;
	bool operator<(const node& b) const{
		if(b.score == score && overballs == b.overballs) 
			return b.balls < balls;
		else if(b.score == score) 	
			return b.overballs < overballs;
		else return  b.score < score; 
	}
};

unordered_map<string, node> mp;

void slove() {
	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		string a; cin >> a;
	}
	for(int i = 1; i <= (n * (n - 1)) / 2; i++){
		string a, b; cin >> a >> b;
		int p = 0, q = 0;
		for(int j = 0; j < (int)a.size(); j++){
			if(a[j] == '-') {
				p = j;
				break;
			}
		}
		for(int j = 0; j < (int) b.size(); j++){
			if(b[j] == ':'){
				q = j;
				break;
			}
		}
		string x = a.substr(0, p), y = a.substr(p + 1);
		int valx = stoi(b.substr(0, q));
		int valy = stoi(b.substr(q + 1));
		mp[x].balls += valx;
		mp[y].balls += valy;
		if(valx == valy) {
			mp[x].score += 1;
			mp[y].score += 1;
		} else if(valx > valy) {
			mp[x].score += 3;
			mp[x].overballs += valx - valy;
			mp[y].overballs += valy - valx;
		} else {
			mp[y].score += 3;
			mp[y].overballs += valy - valx;
			mp[x].overballs += valx - valy;
		}


	}
	vector<pair<node, string>> vec;
	for(auto c : mp){
		vec.push_back({c.second, c.first});
	}
	sort(vec.begin(), vec.end());
	for(auto c : vec){
		 // cout << c.first.score << ' ' << c.first.overballs << ' ' << c.first.balls << ' ' << c.second << '\n';
	}
	vector<string> k;
	for(int i = 0; i < (int)vec.size()/ 2; i++){
		k.push_back(vec[i].second);
	}
	sort(k.begin(), k.end());
	for(auto c : k){
		cout << c << '\n';
	}

}



int main(){
	//ios_base::sync_with_stdio(0), cin.tie(0);
	slove();
	

}