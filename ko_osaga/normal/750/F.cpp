#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

map<int, vector<int> > cache;

vector<int> ask(int x){
	if(cache.find(x) != cache.end()) return cache[x];
	printf("? %d\n", x);
	fflush(stdout);
	int s;
	cin >> s;
	vector<int> v(s);
	for(auto &i : v) cin >> i;
	return cache[x] = v;
}

void report(int x){
	printf("! %d\n", x);
	fflush(stdout);
}

int getnxt(int prv, int pos){
	auto k = ask(pos);
	for(auto &i : k){
		if(i == prv) continue;
		return i;
	}
	return 0;
}

void upup(int x, int y, int z, int h, int ph){
	if(h == 1){
		report(z);
		return;
	}
	if(h == 2){
		auto k = ask(z);
		for(auto &j : k){
			if(j != x && j != y){
				report(j);
			}
		}
		return;
	}
	if(h == 3){
		auto k = ask(z);
		int nxt = -1;
		for(auto &j : k){
			if(j != x && j != y){
				nxt = j;
			}
		}
		k = ask(nxt);
		vector<int> v;
		for(auto &j : k){
			if(j != z){
				v.push_back(j);
			}
		}
		if(ask(v[0]).size() == 2) report(v[0]);
		else report(v[1]);
		return;
	}
	if(h == 4){
		auto k = ask(z);
		int nxt1 = -1;
		for(auto &j : k){
			if(j != x && j != y){
				nxt1 = j;
			}
		}
		k = ask(nxt1);
		vector<int> v2;
		for(auto &j : k){
			if(j != z) v2.push_back(j);
		}
		vector<int> v1;
		for(auto &j : v2){
			auto l = ask(j);
			for(auto &k : l){
				if(k != nxt1) v1.push_back(k);
			}
		}
		for(int i=0; i+1<v1.size(); i++){
			if(ask(v1[i]).size() == 2){
				report(v1[i]);
				return;
			}
		}
		report(v1.back());
		return;
	}
	auto w = ask(z);
	vector<int> l;
	for(int i=h; i<ph; i++) l.push_back(-1);
	int prv = z;
	int cur = -1;
	l.push_back(prv);
	for(auto &k : w){
		if(k != x && k != y){
			cur = k;
		}
	}
	while(1){
		l.push_back(cur);
		int w = getnxt(prv, cur);
		if(w == 0) break;
		prv = cur;
		cur = w;
	}
	auto pth = l;
	int m = pth.size() / 2;
	upup(pth[m-1], pth[m+1], pth[m], ph - m, ph);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cache.clear();
		int h;
		cin >> h;
		auto t = ask(1);
		if(t.size() == 2){
			report(1);
		}
		else if(t.size() == 1){
			vector<int> pth;
			pth.push_back(1);
			int prv = 1;
			int cur = t[0];
			while(1){
				pth.push_back(cur);
				int w = getnxt(prv, cur);
				if(w == 0) break;
				prv = cur;
				cur = w;
			}
			int m = pth.size() / 2;
			upup(pth[m-1], pth[m+1], pth[m], h - m, h);
		}
		else if(t.size() == 3){
			vector<int> l, r;
			int prv = t[0], cur = 1;
			while(1){
				l.push_back(cur);
				int w = getnxt(prv, cur);
				if(w == 0) break;
				prv = cur;
				cur = w;
			}
		    prv = t[1], cur = 1;
			while(1){
				r.push_back(cur);
				int w = getnxt(prv, cur);
				if(w == 0) break;
				prv = cur;
				cur = w;
			}
			reverse(r.begin(), r.end());
			r.pop_back();
			for(auto &i : l) r.push_back(i);
			vector<int> pth = r;
			int m = pth.size() / 2;
			upup(pth[m-1], pth[m+1], pth[m], h - m, h);
		}
	}
}