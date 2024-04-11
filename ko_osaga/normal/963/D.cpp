#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 100005;

namespace sfxarray{
	int ord[MAXN], nord[MAXN], cnt[MAXN], aux[MAXN];
	void solve(int n, char *str, int *sfx, int *rev, int *lcp){
		int p = 1;
		memset(ord, 0, sizeof(ord));
		for(int i=0; i<n; i++){
			sfx[i] = i;
			ord[i] = str[i];
		}
		int pnt = 1;
		while(true){
			memset(cnt, 0, sizeof(cnt));
			for(int i=0; i<n; i++) cnt[ord[min(i + p, n)]]++;
			for(int i=1; i<=n || i<=255; i++){
				cnt[i] += cnt[i-1];
			}
			for(int i=n-1; i>=0; i--){
				aux[--cnt[ord[min(i + p, n)]]] = i;
			}
			memset(cnt, 0, sizeof(cnt));
			for(int i=0; i<n; i++) cnt[ord[i]]++;
			for(int i=1; i<=n || i<=255; i++){
				cnt[i] += cnt[i-1];
			}
			for(int i=n-1; i>=0; i--){
				sfx[--cnt[ord[aux[i]]]] = aux[i];
			}
			if(pnt == n) break;
			pnt = 1;
			nord[sfx[0]] = 1;
			for(int i=1; i<n; i++){
				if(ord[sfx[i-1]] != ord[sfx[i]] ||
					ord[sfx[i-1] + p] != ord[sfx[i] + p]){
					pnt++;
				}
				nord[sfx[i]] = pnt;
			}
			memcpy(ord, nord, sizeof(int) * n);
			p <<= 1;
		}
		for(int i=0; i<n; i++) rev[sfx[i]] = i;
		int h = 0;
		for(int i=0; i<n; i++){
			if(rev[i]){
				int prv = sfx[rev[i] - 1];
				while(str[prv + h] == str[i + h]) h++;
				lcp[rev[i]] = h;
			}
			if(h) h--;
		}
	}
}

int n, q;
char str[MAXN + MAXN], buf[MAXN];
int sfx[MAXN], rev[MAXN], lcp[MAXN];
int ret[MAXN];

struct query{
	int s, e, l, len, idx;
	bool operator<(const query &q)const{
		return pi(s / 300, e) < pi(q.s / 300, q.e);
	}
};

set<int> s;
vector<query> v;
int chk[MAXN];
int redir[MAXN];

void REM(int x){
	if(chk[x]){
		chk[x] = 0;
		s.erase(rev[x]);
	}
}

void ADD(int x){
	if(!chk[x]){
		chk[x] = 1;
		s.insert(rev[x]);
	}
}

void solve(){
	int st = 1, ed = 0;
	for(auto &i : v){
		while(st > i.s) ADD(--st);
		while(ed < i.e) ADD(++ed);
		while(st < i.s) REM(st++);
		while(ed > i.e) REM(ed--);
		auto it = s.begin();
		int k = i.l;
		if(s.size() < k) ret[i.idx] = -1;
		else{
			auto nit = it;
			for(int i=1; i<k; i++) nit++;
			ret[i.idx] = 1e9;
			while(nit != s.end()){
				ret[i.idx] = min(ret[i.idx], *nit - *it + i.len);
				nit++;
				it++;
			}
		}
	}
}

int main(){
	map<tuple<int, int, int>, int> mp;
	scanf("%s", str);
	scanf("%d",&q);
	n = strlen(str);
	sfxarray::solve(n, str, sfx, rev, lcp);
	memcpy(rev,sfx,sizeof(sfx));
	for(int i=0; i<q; i++){
		int k;
		scanf("%d %s", &k, buf);
		int s = 0, e = n-1;
		for(int j=0; buf[j]; j++){
			if(s > e) break;
			int ls = s, le = e + 1;
			while(ls != le){
				int m = (ls + le) / 2;
				if(str[sfx[m] + j] < buf[j]) ls = m + 1;
				else le = m;
			}
			int rs = s, re = e + 1;
			while(rs != re){
				int m = (rs + re) / 2;
				if(str[sfx[m] + j] <= buf[j]) rs = m + 1;
				else re = m;
			}
			s = ls, e = re - 1;
		}
		query q = {s, e, k, (int)strlen(buf), i};
		if(s > e){
			ret[i] = -1;
			continue;
		}
		v.push_back(q);
	}
	sort(v.begin(), v.end());
	solve();
	for(int i=0; i<q; i++){
		printf("%d\n", ret[i]);
	}
}