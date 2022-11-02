#include <cstdio>
#include <algorithm>

#define FOR(a,b,c) for (int c = (a), __for = (b); c < __for; ++c)
#define REP(n) for (int __rep = 0, __for = (n); __rep < __for; ++__rep)
#define x first
#define y second

using namespace std;

const int oo = 1000000000;

const int offset = (1 << 18);
int tur[offset * 2];
void reset(){FOR(0,offset * 2,i) tur[i] = -1;}
void set(int id, int lo, int hi, int pos, int val){
	if (lo > pos || hi < pos) return;
	if (lo == hi){tur[id] = val; return;}
	int mid = (lo + hi) / 2;
	set(id * 2, lo, mid, pos, val);
	set(id * 2 + 1, mid + 1, hi, pos, val);
	tur[id] = min(tur[id * 2], tur[id * 2 + 1]);
}
void set(int pos, int val){set(1, 0, offset - 1, pos, val);}
int getMin(int id, int lo, int hi, int slo, int shi){
	if (lo > shi || hi < slo) return oo;
	if (lo >= slo && hi <= shi) return tur[id];
	int mid = (lo + hi) / 2;
	return min(
			getMin(id * 2, lo, mid, slo, shi),
			getMin(id * 2 + 1, mid + 1, hi, slo, shi)
			);
}
int getMin(int lo, int hi){return getMin(1, 0, offset - 1, lo, hi);}

class prav{
public:
	int x1, y1, x2, y2;
	prav(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0) : x1(_x1), y1(_y1), x2(_x2), y2(_y2){}
};

int n, m, k, q;
pair < int, int > r[200005];
prav in[200005];
bool good[200005];

void solve(){
	vector < pair < int, int > > sweep;
	reset();
	FOR(0,k,i) sweep.push_back(r[i]);
	FOR(0,q,i) sweep.push_back({in[i].x2, oo + i});
	sort(sweep.begin(), sweep.end());
	for (auto x : sweep){
		if (x.y >= oo){ // pravokutnik
			int t = x.y - oo; //if (t == 0) printf(" -%d- %d\n", in[t].y1, getMin(in[t].y1, in[t].y2));
			good[t] |= (getMin(in[t].y1, in[t].y2) >= in[t].x1);
		}
		else { // kula
			//printf(" ~~ %d %d\n", x.y, x.x);
			set(x.y, x.x);
		}
	}
}

int main(){
	scanf("%d%d%d%d", &n, &m, &k, &q);
	FOR(0,k,i) scanf("%d%d", &(r[i].x), &(r[i].y));
	FOR(0,q,i) scanf("%d%d%d%d", &(in[i].x1), &(in[i].y1), &(in[i].x2), &(in[i].y2));
	solve();
	FOR(0,k,i) swap(r[i].x, r[i].y);
	FOR(0,q,i) swap(in[i].x1, in[i].y1), swap(in[i].x2, in[i].y2);
	swap(n, m);
	solve();
	FOR(0,q,i) if (good[i]) printf("YES\n"); else printf("NO\n");
	return 0;
}