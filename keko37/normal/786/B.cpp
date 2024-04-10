#include<iostream>
#include<cstdio>
#include<vector>
#include<set>

using namespace std;

typedef long long llint;

const int MAXN = 100005;
const llint INF = 100000000000000000LL;

int n, q, st, typ, pot=1, x, y, c, od;
llint dist[4*MAXN] [3];

struct edge {
	int to, tip;
	llint cost;
	edge (int _to, int _tip, llint _cost) {
		to=_to; tip=_tip; cost=_cost;
	}
};

bool operator< (edge e1, edge e2) {
	return e1.cost<=e2.cost;
}

set <edge> s;
vector <edge> v[4*MAXN] [3];

void tournament_init () {
	while (pot<n) pot*=2;
	for (int i=1; i<pot; i++) {
		v[i] [0].push_back(edge(i*2, 0, 0));
		v[i] [0].push_back(edge(i*2+1, 0, 0));
		v[i*2] [pot/2>i].push_back(edge(i, 1, 0));
		v[i*2+1] [pot/2>i].push_back(edge(i, 1, 0));
	}
}

void ubaci (int cvor, int from, int to, int low, int high, int sender, int t, int w) {
	if (from<=low && high<=to) {
		if (t==0) {
			v[sender] [0].push_back(edge(cvor, t, w));
		} else {
			v[cvor] [cvor<pot].push_back(edge(sender, 0, w));
		}
		return;
	}
	if (to<low || high<from) return;
	ubaci(cvor*2, from, to, low, (low+high)/2, sender, t, w);
	ubaci(cvor*2+1, from, to, (low+high)/2+1, high, sender, t, w);
}

void dijkstra () {
	for (int i=1; i<2*pot; i++) {
		for (int j=0; j<2; j++) {
			if (i==st && j==0) continue;
			s.insert(edge(i, j, INF));
			dist[i] [j]=INF;
		}
	}
	s.insert(edge(st, 0, 0));
	dist[st] [0]=0;
	while (!s.empty()) {
		int cvor=s.begin()->to;
		int vrst=s.begin()->tip;
		s.erase(s.begin());
		for (int i=0; i<v[cvor] [vrst].size(); i++) {
			int sus=v[cvor] [vrst] [i].to;
			int bow=v[cvor] [vrst] [i].tip;
			llint uda=v[cvor] [vrst] [i].cost;
			if (dist[cvor] [vrst]+uda<dist[sus] [bow]) {
				s.erase(edge(sus, bow, dist[sus] [bow]));
				dist[sus] [bow]=dist[cvor] [vrst]+uda;
				s.insert(edge(sus, bow, dist[sus] [bow]));
			}
		}
	}
}

int main () {
	cin >> n >> q >> st;
	tournament_init();
	st=st-1+pot;
	for (int i=0; i<q; i++) {
		scanf("%d", &typ);
		if (typ==1) {
			scanf("%d%d%d", &x, &y, &c);
			v[x-1+pot] [0].push_back(edge(y-1+pot, 0, c));
		} else if (typ==2) {
			scanf("%d%d%d%d", &od, &x, &y, &c);
			ubaci(1, x-1, y-1, 0, pot-1, od-1+pot, 0, c);
		} else {
			scanf("%d%d%d%d", &od, &x, &y, &c);
			ubaci(1, x-1, y-1, 0, pot-1, od-1+pot, 1, c);
		}
	}
	dijkstra();
	for (int i=pot; i<pot+n; i++) {
		if (dist[i] [0]==INF) printf("-1 "); else printf("%I64d ", dist[i] [0]);
	}
	return 0;
}