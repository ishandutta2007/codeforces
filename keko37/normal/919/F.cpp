#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 1000005;

int tc, r;
int p[MAXN], br[MAXN], bio[MAXN];
vector <int> v, g[MAXN];
queue <int> q;

vector <int> f (int x) {
	vector <int> t;
	while (x) {
		t.push_back(x%5);
		x/=5;
	}
	reverse(t.begin(), t.end());
	return t;
}

inline int eval (vector <int> t) {
	int res=0;
	for (int i=0; i<t.size(); i++) {
		res=res*5+t[i];
	}
	return res;
}

void gen (int x, int d) {
	if (d==8) {
		v.push_back(x);
		return;
	}
	for (int i=x%5; i<5; i++) {
		gen(x*5+i, d+1);
	}
}

void edges (int a, int b) {
	if (a==0 || b==0) return;
	vector <int> va=f(a), vb=f(b), nb;
	int cvor=495*p[b]+p[a];
	for (int i=0; i<va.size(); i++) {
		for (int j=0; j<vb.size(); j++) {
			int x=va[i]+vb[j];
			if (x>=5) x-=5;
			nb=vb;
			nb[j]=x;
			sort(nb.begin(), nb.end());
			int sus=495*p[a]+p[eval(nb)];
			br[cvor]++;
			g[sus].push_back(cvor);
		}
	}
}

void bfs () {
	while (!q.empty()) {
		int f=q.front();
		q.pop();
		if (bio[f]) continue;
		if (f<495) bio[f]=1; else if (f%495==0) bio[f]=2; else if (br[f]==0) bio[f]=2; else bio[f]=1;
		if (bio[f]==1) {
			for (int i=0; i<g[f].size(); i++) {
				int sus=g[f] [i];
				br[sus]--;
				if (br[sus]==0) q.push(sus);
			}
		} else {
			for (int i=0; i<g[f].size(); i++) {
				int sus=g[f] [i];
				q.push(sus);
			}
		}
	}
}

void nodes () {
	for (int i=0; i<v.size(); i++) {
		p[v[i]]=i;
		q.push(i);
		q.push(495*i);
	}
	for (int i=0; i<v.size(); i++) {
		for (int j=0; j<v.size(); j++) {
			edges(v[i], v[j]);
		}
	}
}

int main () {
	gen(0, 0);
	nodes();
	bfs();
	cin >> tc;
	for (int ii=0; ii<tc; ii++) {
		scanf("%d", &r);
		vector <int> va(8, 0), vb(8, 0);
		for (int i=0; i<8; i++) {
			scanf("%d", &va[i]);
		}
		for (int i=0; i<8; i++) {
			scanf("%d", &vb[i]);
		}
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
		if (r==0) swap(va, vb);
		int sol=bio[495*p[eval(vb)]+p[eval(va)]];
		if (sol==0) {
			cout << "Deal" << endl;
		} else if (sol==1) {
			if (r==0) cout << "Alice" << endl; else cout << "Bob" << endl;
		} else {
			if (r==1) cout << "Alice" << endl; else cout << "Bob" << endl;
		}
	}
	return 0;
}