#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 500005;

struct seg{
	int typ;
	int s, e;
	bool operator<(const seg &x)const{
		return s < x.s;
	}
	bool operator!=(const seg &x)const{
		return typ != x.typ || s != x.s || e != x.e;
	}
};

int n, a[MAXN];
int ret[MAXN];
vector<int> pos[MAXN];
int b[MAXN];

int solve(){
	for(int i=0; i<n+2; i++) pos[a[i]].push_back(i);
	int mxv = *max_element(a + 1, a + n + 1);
	set<seg> s;
	s.insert({0, 0, n+1});
	set<int> rems;
	for(int i=1; i<=n; i++) rems.insert(i);
	auto MARK = [&](int s, int e, int x){
		auto itr = rems.lower_bound(s);
		while(itr != rems.end() && *itr <= e){
			ret[*itr] = x;
			itr = rems.erase(itr);
		}
	};
	int ret = 0;
	auto FUCK = [&](int s, int e, int i){
		if(s > e) return;
		int len = e - s + 1;
		ret = max(ret, (len+1)/2);
		if(b[s-1] && b[e+1]){
			MARK(s, e, i);
			return;
		}
		if(!b[s-1] && !b[e-1]) return;
		if(b[s-1]){
			MARK(s, s + len / 2 - 1, i);
		}
		if(b[e+1]){
			MARK(e - len / 2 + 1, e, i);
		}
	};
	for(int i=mxv; i>=0; i--){
		vector<int> lookup;
		auto INSERT = [&](seg x, int coalL, int coalR){
			if(x.s > x.e) return;
			if(coalR){
				auto l = s.lower_bound(x);
				if(l != s.end() && l->typ == x.typ && x.e + 1 == l->s){
					x.e = l->e;
					s.erase(l);
				}
				else if(x.e + 1 < n+2 && x.typ == b[x.e+1]) x.e++;
			}
			if(coalL){
				auto l = s.lower_bound(x);
				if(l != s.begin() && prev(l)->typ == x.typ && x.s - 1 == prev(l)->e){
					x.s = prev(l)->s;
					s.erase(prev(l));
				}
				else if(x.s - 1 >= 0 && x.typ == b[x.s-1]) x.s--;
			}
			lookup.push_back(x.s);
			if(x.s < x.e){
				s.insert(x);
			}
		};
		for(auto &j : pos[i]){
			b[j] = 1;
			auto itr = s.lower_bound({0, j+1, -1});
			if(itr != s.begin() && prev(itr)->e >= j){
				auto rem = *--itr;
				s.erase(itr);
				INSERT((seg){rem.typ, rem.s, j-1}, 1, 0);
				INSERT((seg){rem.typ, j+1, rem.e}, 0, 1);
			}
			INSERT({1, j, j}, 1, 1);
		}
	//	for(auto &x : s) printf("[%d, %d, %d]", x.s, x.e, x.typ);
	//	puts("");
		for(auto &l : lookup){
			auto itr = s.lower_bound({-1, l+1, -1});
			if(itr != s.begin()) itr--;
			if(itr->typ) MARK(itr->s, itr->e, i);
			if(itr != s.begin()){
				FUCK(prev(itr)->e + 1, itr->s - 1, i);
			}
			if(next(itr) != s.end()){
				FUCK(itr->e + 1, next(itr)->s - 1, i);
			}
		}
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
//	a[i] = rand() % 5 + 1;
	}
	a[0] = a[1];
	a[n+1] = a[n];
	vector<int> crd(a+1, a+n+1);
	sort(all(crd));
	crd.resize(unique(all(crd)) - crd.begin());
	for(int i=0; i<n+2; i++){
		a[i] = lower_bound(all(crd), a[i]) - crd.begin();
	}
	printf("%d\n", solve());
	for(int i=1; i<=n; i++) printf("%d ", crd[ret[i]]);
	/*
	for(int c=0; ; c++){
		auto med = [&](int i){
			int sum = a[i-1] + a[i] + a[i+1];
			int mxx = max({a[i-1], a[i], a[i+1]});
			int mnn = min({a[i-1], a[i], a[i+1]});
			return sum - mxx - mnn;
		};
		bool upd = 0;
		for(int j=1; j<=n; j++){
			b[j] = med(j);
			if(a[j] != b[j]){
				upd = 1;
			}
		}
		b[0] = a[0];
		b[n+1] = a[n+1];
		if(!upd){
			puts("");
			cout << c << endl;
			for(int j=1; j<=n; j++) assert(crd[b[j]] == crd[ret[j]]);
			break;
		}
		else memcpy(a, b, sizeof(int) * (n+4));
	}*/
}