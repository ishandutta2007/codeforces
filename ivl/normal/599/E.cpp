#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pll pair < ll, ll >
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

void imp(){cout << 0 << endl; exit(0);}

int n, m, q;
int LCA[20][20];
vector < pii > E;
bool mat[20][20];
int mat2[20];

int Count[20][20];
int Bio[20];
int CheckDFS(int id, int p){
	if (Bio[id] == 1) imp();
	if (Bio[id] == 2) return Count[id][p];
	Bio[id] = 1;
	int &r = Count[id][p];
	REP(i,n) if (mat[id][i] && i != p) r += CheckDFS(i, id);
	Bio[id] = 2;
	return r;
}

map < pii, int > M;
unordered_map < int, int > M2;
int Has[20];
const int None = -1;

int LOW[1<<13];
int low(int bit){
	if (bit == 0) return -1;
	int cnt = 0;
	while (bit%2 == 0) ++cnt, bit >>= 1;
	return cnt;
}

bitset<20> CANT[1<<13];

ll dp(int id, int bit, bool ch = true){ // bit ne ukljucuje id
	static ll memo[20][1<<13][2];
	static bool bio[20][1<<13][2];
	
	ll &R = memo[id][bit][ch];
	if (bio[id][bit][ch]++) return R;
	R = 0;
	
	//TRACE("a");
	if (M2.count(bit)) if (M2[bit] != id) return R=0; // mora bit c od lca(a,b) = c
	//TRACE("b");
	if (ch) if ((Has[id]&bit) != Has[id]) return R=0;
	//TRACE("c");
	if (CANT[bit][id]) return R=0;
	//TRACE("d");
	
	if (bit == 0) return R = 1;
	
	int bit2 = (bit & mat2[id]);
	
	if (!bit2){
		bit2 = bit;
		int t = LOW[bit];
		do {
			if ((bit2>>t)&1){
				if (M.count({bit, bit2})){
					int bl = M[{bit, bit2}];
					if (bl != None && ((bit2>>bl)&1)) R += dp(bl, bit2^(1<<bl)) * dp(id, bit^bit2, false);
				} else REP(i,n) if ((bit2>>i)&1){
					R += dp(i, bit2^(1<<i)) * dp(id, bit^bit2, false);
					//TRACE(id _ bitset<4>(bit) _ i _ bitset<4>(bit2) _ R);
				}
			}
			bit2 = (bit&(bit2-1));
		} while (bit2 != bit);
		
		//TRACE(id _ bitset<4>(bit) _ R);
		
		return R;
	}
	
	int t = (1<<LOW[bit2]); 
	
	//TRACE(id _ bitset<6>(bit) _ LOW[bit2]);
	
	int bit3 = bit;
	do {
		if ((bit2&bit3) == t)
			if (!M.count({bit, bit3}) || M[{bit, bit3}] == LOW[bit2]){
				//TRACE(id _ bitset<6>(bit) _ bitset<6>(bit3));
				R += dp(LOW[bit2], bit3^t) * dp(id, bit^bit3, false);
			}
		
		
		bit3 = (bit&(bit3-1));
	} while (bit3 != bit);
	
	return R;
}

void AddEdge(int u, int v){
	REP(bit,1<<n){
		int bit2 = bit;
		do {
			
			if (((bit>>u)&1) && ((bit>>v)&1))
				if (((bit2>>u)&1) && !((bit2>>v)&1)){
					if (!M.count({bit, bit2})) M[{bit, bit2}] = v;
					if (M[{bit, bit2}] != v) M[{bit, bit2}] = None;
				}
			
			bit2 = (bit&(bit2-1));
		} while (bit2 != bit);
	}
}

void AddLCA(int a, int b, int c){
	if (a == b && a != c) imp();
	if (a == b) return;
	//if (a == c){parent(a, b); return;}
	//if (b == c){parent(b, a); return;}
	
	if (c != a) Has[c] |= (1<<a);
	if (c != b) Has[c] |= (1<<b);
	
	REP(bit,1<<n){
		
		if (((bit>>a)&1) && ((bit>>b)&1) && !((bit>>c)&1)){
			if (!M2.count(bit)) M2[bit] = c;
			if (M2[bit] != c) M2[bit] = None;
		}
		
		if (((bit>>a)&1) && !((bit>>b)&1)){
			if (b != c) CANT[bit][b] = 1;
		}
		if (((bit>>b)&1) && !((bit>>a)&1)){
			if (a != c) CANT[bit][a] = 1;
		}
		
	}
}

int main(){
	memset(LCA, -1, sizeof LCA);
	REP(i,1<<13) LOW[i] = low(i);
	
	cin >> n >> m >> q;
	REP(i,m){
		int u, v;
		cin >> u >> v, --u, --v;
		E.pb({u,v});
		AddEdge(u, v);
		AddEdge(v, u);
		mat[u][v] = mat[v][u] = true;
		mat2[u] |= (1<<v);
		mat2[v] |= (1<<u);
	}
	REP(i,q){
		int a, b, c;
		cin >> a >> b >> c, --a, --b, --c;
		if (LCA[a][b] != -1 && LCA[a][b] != c) imp();
		LCA[a][b] = LCA[b][a] = c;
		AddLCA(a, b, c);
	}
	
	REP(i,n){
		memset(Bio, 0, sizeof Bio);
		CheckDFS(i, i);
	}
	
	cout << dp(0, (1<<n)-2) << endl;
	
	/*while (true){
		int a, b;
		cin >> a >> b;
		cout << dp(a, b) << endl;
	}*/
	
	return 0;
}