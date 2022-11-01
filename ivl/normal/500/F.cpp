#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#define x first
#define y second

using namespace std;

int KS[4005];
stack < pair < int, int > > S;
void add(int x, int y){ // x = cijena, y = brutalnost
	 for (int i = 4005; i - x >= 0; --i){
	 	 if (KS[i] < KS[i - x] + y){
	   	 	S.push(make_pair(i, KS[i]));
	   	 	KS[i] = KS[i - x] + y;
		 }
	 }
}
void rem(){
	 pair < int, int > p = S.top(); S.pop();
	 KS[p.x] = p.y;
}

//int gr[100005], sz[100005];
//int un(int x){if (x == gr[x]) return x; return un(gr[x]);}
//pair < int, int > join(int a, int b){a = un(a); b = un(b); if (a == b) return make_pair(-1, -1); if (sz[a] < sz[b]) swap(a, b); sz[a] += sz[b]; gr[b] = a; return make_pair(b, sz[b]);}
// returna (node koji se attacha, size stabla koje se attacha)

vector < pair < int, int > > tur[1 << 16];
int slo, shi; pair < int, int > sval;
void update(int id = 1, int lo = 0, int hi = (1 << 15) - 1){
	 if (lo > shi || hi < slo) return;
	 if (lo >= slo && hi <= shi){tur[id].push_back(sval); return;}
	 update(id * 2, lo, (lo + hi) / 2);
	 update(id * 2 + 1, (lo + hi + 1) / 2, hi);
}

int n, p, q;
vector < pair < int, int > > V[1 << 15]; // V[a].push_back(b);
char in[105];
int out[100005];

/*stack < pair < int, int > > S;
void add(int a, int b){S.push(join(a, b));}
void rem(){
	 pair < int, int > p = S.top();
	 S.pop();
	 if (p.x == -1) return;
	 int par = gr[p.x];
	 sz[par] -= p.y;
	 sz[p.x] = p.y;
	 gr[p.x] = p.x;
}*/
void solve(int id){
	 S.push(make_pair(-1, -1));
	 for (int i = 0; i < tur[id].size(); ++i) add(tur[id][i].x, tur[id][i].y);
	 if (id >> 15){
	 	int iid = id - (1 << 15);
	 	for (int i = 0; i < V[iid].size(); ++i){
			out[V[iid][i].y] = KS[V[iid][i].x];
		}
     }
     else {solve(2 * id); solve(2 * id + 1);}
     while (S.top().x != -1) rem();
     S.pop();
}

int main(){
	
	//for (int i = 0; i <= 100003; ++i){gr[i] = i; sz[i] = 1;}
	
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; ++i){
		int c, h, t; scanf("%d%d%d", &c, &h, &t);
		slo = t; shi = t + p - 1; sval = make_pair(c, h);
		update();
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i){
		int a, b; scanf("%d%d", &a, &b); V[a].push_back(make_pair(b, i));
	}
    solve(1);
    for (int i = 0; i < q; ++i) printf("%d\n", out[i]);
	return 0;
}