#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define hash fuck
string s;

vector<int> l[600000], r[600000];

int hash(string s){
	int ret = 0;
	for(auto &i : s){
		ret *= 26;
		ret += (i - 'a');
	}
	if(s.size() == 2) ret += 26;
	if(s.size() == 3) ret += 26 * 26 + 26;
	if(s.size() == 4) ret += 26 * 26 * 26 + 26 * 26 + 26;
	return ret;
}

map<pi, int> mp;

int query(int x, int y, int len){
	if(mp.find(pi(x, y)) != mp.end()) return mp[pi(x, y)];
	int ret = 1e9;
	if(l[x].size() < r[y].size()){
		for(auto &i : l[x]){
			auto p = lower_bound(r[y].begin(), r[y].end(), i + len - 1);
			if(p != r[y].end()) ret = min(ret, *p - i + 1);
		}
	}
	else{
		for(auto &i : r[y]){
			auto p = upper_bound(l[x].begin(), l[x].end(), i - len + 1);
			if(p != l[x].begin()){
				p--;
				ret = min(ret, i - *p + 1);
			}
		}
	}
	return mp[pi(x, y)] = ret;
}

int main(){
	cin >> s;
	for(int len=1; len<=4; len++){
		for(int i=0; i+len-1<s.size(); i++){
			int p1 = hash(s.substr(i, len));
			l[p1].push_back(i);
			r[p1].push_back(i+len-1);
		}
	}
	int q;
	cin >> q;
	while(q--){
		char sb[6], tb[6];
		scanf("%s %s", sb, tb);
		string s = sb, t = tb;
		if(s.size() > t.size()) swap(s, t);
		bool ok = 0;
		for(int i=0; i+s.size()-1<t.size(); i++){
			if(t.substr(i, s.size()) == s){
				ok = 1;
				break;
			}
		}
		if(ok){
			if(l[hash(t)].empty()) puts("-1");
			else printf("%d\n", t.size());
			continue;
		}
		int p = hash(s), q = hash(t);
		int r = max((int)s.size(), (int)t.size());
		int ret = min(query(p, q, r), query(q, p, r));
		if(ret > 1e8) ret= -1;
		printf("%d\n", ret);
	}
}