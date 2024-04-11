#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 200005;

vector<pi> duval(string &s){
	int n = sz(s);
	vector<pi> v;
	for(int i = 0; i < n; ){
		int j = i + 1, k = i;
		while(j < n && s[k] <= s[j]){
			if(s[k] == s[j]) j++, k++;
			else if(s[k] < s[j]) j++, k = i;
		}
		v.emplace_back(i, j - k);
		while(i <= k){
			i += j - k;
		}
	}
	return v;
}

vector<int> duval2(string &s){
	int n = sz(s);
	vector<int> v;
	for(int i = 0; i < n; ){
		int j = i + 1, k = i;
		while(j < n && s[k] <= s[j]){
			if(s[k] == s[j]) j++, k++;
			else if(s[k] < s[j]) j++, k = i;
		}
		while(i <= k){
			i += j - k;
			v.push_back(i);
		}
	}
	return v;
}

string rev(string x){
	reverse(all(x)); return x;
}

string prefixReversal(string &s){
	string t = s;
	reverse(all(t));
	auto getPos = [&](string &t){
		auto ans = duval2(t);
		return sz(s) - (sz(ans) >= 2 ? ans[sz(ans) - 2] : 0);
	};
	int l = getPos(t);
	t.push_back('z' + 1);
	int r = getPos(t);
	string g = rev(s.substr(0, l)) + min(s.substr(l), rev(s.substr(l)));
	string h = rev(s.substr(0, r)) + min(s.substr(r), rev(s.substr(r)));
	return min(g, h);
}

bool cmp(int x, int y, string &d, string &r, vector<int> &matches, vector<int> &snatches){
	if(x == y) return false;
	if(x > y) assert(0);
	int l = y - x;
	if(matches[x] >= l){
		if(snatches[l] >= sz(d) - y) return false;
		return r[l + snatches[l]] < r[snatches[l]];
	}
	return r[matches[x]] < d[x + matches[x]];
}

string reversal(string d){
	string ret = min(d, rev(d));
	ret = min(ret, prefixReversal(d));
	if(sz(d) > 1){
		auto r = rev(d);
		vector<int> matches(sz(d) + 1);
		vector<int> snatches(sz(d) + 1);
		{
			vector<int> fail(sz(r) + 1);
			int p = 0;
			for(int i = 1; i < sz(r); i++){
				while(p && r[i] != r[p]){
					p = fail[p];
					snatches[i - p] = max(snatches[i - p], p);
				}
				if(r[i] == r[p]) p++;
				fail[i + 1] = p;
				snatches[i + 1 - p] = max(snatches[i + 1 - p], p);
			}
			p = 0;
			for(int i = 0; i <= sz(d); i++){
				while(p && (i == sz(d) || d[i] != r[p])){
					p = fail[p];
					matches[i - p] = max(matches[i - p], p);
				}
				if(i == sz(d)) break;
				if(d[i] == r[p]) p++;
				matches[i + 1 - p] = max(matches[i + 1 - p], p);
			}
		}
		int cur = 1;
		for(int i = 2; i < sz(d); i++){
			if(!cmp(cur, i, d, r, matches, snatches)) cur = i; 
		}
		ret = min(ret, d.substr(0, cur) + rev(d.substr(cur)));
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s; cin >> s;
	int k; cin >> k;
	string r = s; reverse(all(r));
	if(k == 1){
		cout << min(s, r) << "\n";
		return 0;
	}
	auto d = duval(r);
	string ans;
	if(k > 2){
		int lst = sz(s);
		while(sz(d) && k > 2){
			auto p = d.back(); d.pop_back();
			ans += r.substr(p.first);
			r.resize(p.first);
			lst = p.first;
			k--;
			if(p.second == 1){
				while(sz(d) && d.back().second == 1){
					auto p = d.back(); d.pop_back();
					ans += r.substr(p.first);
					r.resize(p.first);
					lst = p.first;
				}
			}
		}
	}
	reverse(all(r));
	ans += reversal(r);
	cout << ans << endl;
}