#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 300300
#define NMAX 
#define MMAX 

using namespace std;

int n, k, a[DMAX], val, p[DMAX];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

struct nod {
	int nr;
	nod * v[2];
	nod() {
		nr = 0;
		v[0] = v[1] = 0;
	}
}*root;

void insert(nod * cnod, int nr, int lvl) {
	if(lvl == 31) {
		cnod->nr++;
		return;
	}

	if( ((1 << (30 - lvl)) & nr) != 0) {
		if(cnod->v[1] == 0) cnod->v[1] = new nod();
		insert(cnod->v[1], nr, lvl + 1);
	} else {
		if(cnod->v[0] == 0) cnod->v[0] = new nod();	
		insert(cnod->v[0], nr, lvl + 1);
	}
	cnod->nr = 0;
	if(cnod->v[0]) cnod->nr += cnod->v[0]->nr;
	if(cnod->v[1]) cnod->nr += cnod->v[1]->nr;
}


void get_max(nod * cnod, int nr, int lvl) {
	if(lvl == 31) {
		cout << val << ' ';
		// cout << endl;
		cnod->nr--;
		return;
	}

	int bit = (((1 << (30 - lvl)) & nr) != 0);
	// dbg(bit);
	if(cnod->v[bit] == 0) {
		bit = 1 - bit;
		val += (1 << (30 - lvl));
	}
	// dbg(bit);
	get_max(cnod->v[bit], nr, lvl + 1);
	cnod->nr--;
	if(cnod->v[bit]->nr == 0) {
		delete(cnod->v[bit]);
		cnod->v[bit] = 0;
	}

	// if(cnod->v[0]) cnod->nr += cnod->v[0]->nr;
	// if(cnod->v[1]) cnod->nr += cnod->v[1]->nr;
}



int main() {
	ios_base::sync_with_stdio(false);
	root = new nod();

	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		insert(root, p[i], 1);
	}

	for(int i = 1; i <= n; i++) {
		val = 0;
		get_max(root, a[i], 1);
	}

}