#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

const int N = 4e5 + 10;
const int INF = 1.1e9;

template<class T>
struct rollback_array{
	stack<pair<int, T>> changes;
	T arr[N];
	rollback_array(){}
	void setall(T x){
		for(int i = 0; i < N; i++) arr[i] = x;
	}
	T get(int i){
		return arr[i];
	}
	void update(int i, T v, bool roll = 0){
		if(roll) changes.push({i, arr[i]});
		arr[i] = v;
	}
	void click(){
		changes.push({INF, T()});
	}
	void roll_back_to_the_last_click(){
		while(!changes.empty()){
			auto it = changes.top();
			changes.pop();
			if(it.F == INF) return;
			arr[it.F] = it.S;
		}
	}
};

rollback_array<int> par, e, rnk;

const int MAXLOG = 31;

struct XOR{
    int base[MAXLOG];

    XOR(){memset(base, 0, sizeof base);}
    void init()
    {
    memset(base, 0, sizeof base);
    }

    void add(int val)
    {
      for(int i = MAXLOG - 1; i >= 0; i--)
      if((val >> i) & 1)
      {
        if(!base[i]) { base[i] = val; return; }
        else val ^= base[i];
      }
  }

  int getmin(int x){
    sort(base, base+MAXLOG);
    reverse(base, base + MAXLOG);
    for(int i = 0; i < MAXLOG; i++) if((x ^ base[i]) < x) x ^= base[i];
    return x;
  }
};

XOR basis;

void init(){
  for(int i = 1; i < N; i++) par.update(i, i), rnk.update(i, 1), e.update(i, 0);
  basis.init();
}

pii root(int x, bool roll = 0){
	int parx = par.get(x);
	int ex = e.get(x);
	if(x == parx) return {x, 0};
	auto rt = root(parx, roll);
	rt.S ^= ex;
	// if(roll){
	// 	par.update(x, rt.F, 1);
	// 	e.update(x, rt.S, 1);
	// }
	return rt;
}

bool merge(int x, int y, int t, bool roll = 0){
  pii P = root(x, roll), Q = root(y, roll);
  x = P.F, y = Q.F;
  int edge = P.S ^ Q.S ^ t;
  if(x == y){
    basis.add(edge);
    return 0;
  }
  int rnkx = rnk.get(x), rnky = rnk.get(y);
  if(rnkx > rnky) swap(x, y);
  par.update(x, y, roll);
  e.update(x, edge, roll);
  if(rnkx == rnky){
    rnk.update(y, rnky + 1, roll);
  }
  return 1;
}

int getPath(int a, int b){
  pii P = root(a), Q = root(b);
  if(P.F != Q.F) return -1;
  return P.S ^ Q.S;
}

map<pii, int> compress;
set<pii> edges;

int ty[N], x[N], y[N], d[N], a[N], b[N], c[N], ind[N];
int u[N], v[N], w[N];
rollback_array<int> currEdges;
int cnt = 0;
int n, q, m;
rollback_array<int> F1, F2;

void click_all(bool clickF = 0){
	par.click(); rnk.click();
	currEdges.click();
	if(clickF) F1.click(), F2.click();	
}
 
void roll_back(bool rollF = 0){
	par.roll_back_to_the_last_click();
	rnk.roll_back_to_the_last_click();
	currEdges.roll_back_to_the_last_click();
	if(rollF){
		F1.roll_back_to_the_last_click();
		F2.roll_back_to_the_last_click();
	}
}

void dfs(int s = 1, int e = q, int pos = 1){
	if(s == e){
		if(ty[s] == 3){
			int val = getPath(x[s], y[s]);
			assert(val != -1);
			printf("%d\n", basis.getmin(val));
		}
		return;
	}

	int mid = (s + e) >> 1;
	// take a snap of the current state
	click_all(1);
	XOR basis2 = basis;
	vector<int> A, B;
	for(int i = s; i <= mid; i++) if(ty[i] != 3){
		F1.update(ind[i], pos, 1);
		A.push_back(ind[i]);
	}
	for(int i = mid + 1; i <= e; i++) if(ty[i] != 3){
		F2.update(ind[i], pos, 1);
		B.push_back(ind[i]);
	}
	
	for(int it : B) if(F1.get(it) != pos){
		if(currEdges.get(it) >= 0){
			int ew = currEdges.get(it);
			merge(u[it], v[it], ew, 1);
		}
	}
	dfs(s, mid, pos << 1);
	roll_back();
	click_all();
	basis = basis2;

	for(int i = s; i <= mid; i++){
		auto it = ind[i];
		if(ty[i] == 3) continue;
		currEdges.update(it, ty[i] == 1 ? d[i] : -1, 1);
	}

	for(int it : A){
		if(F2.get(it) != pos){
			if(currEdges.get(it) >= 0){
				int ew = currEdges.get(it);
				merge(u[it], v[it], ew, 1);
			}
		}
	}

	dfs(mid + 1, e, pos << 1 | 1);
	roll_back(1);
	basis = basis2;
}	
int fixedEdges[N];
int main(){
    sd(n); sd(m);

    for(int i = 1; i <= m; i++){
        sd(a[i]); sd(b[i]); sd(c[i]);
        if(a[i] > b[i]) swap(a[i], b[i]);
        edges.insert({a[i], b[i]});        
    }

    sd(q);

    for(int i = 1; i <= q; i++){
    	sd(ty[i]), sd(x[i]), sd(y[i]);
    	if(x[i] > y[i]) swap(x[i], y[i]);
    	if(ty[i] == 1) sd(d[i]);
    	if(ty[i] != 3){
    		edges.insert({x[i], y[i]});
    	}
    }

    for(auto it : edges){
    	compress[it] = ++cnt;
    	u[cnt] = it.F;
    	v[cnt] = it.S;
    }
    memset(fixedEdges, -1, sizeof fixedEdges);
    currEdges.setall(-1);
    for(int i = 1; i <= m; i++){
    	currEdges.update(compress[{a[i], b[i]}], c[i]);
    	fixedEdges[compress[{a[i], b[i]}]] = c[i];
    }

    for(int i = 1; i <= q; i++) if(ty[i] < 3){
    	ind[i] = compress[{x[i], y[i]}];
    	fixedEdges[ind[i]] = -1;
    }
    
    init();

    for(int i = 1; i < N; i++) if(fixedEdges[i] >= 0){
    	merge(u[i], v[i], fixedEdges[i]);
    }
    dfs();
}