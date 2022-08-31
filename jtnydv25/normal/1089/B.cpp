#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
// vertices 1 to V
// call Matching & then Output
// returns number of vertices matched
// O(E.sqrt(V))
const int N = 505;
int V, E;
vector<int> graph[N];
int Mate[N];
int subset[N];
int vAncestors[N];
int wAncestors[N];
int even[N], odd[N];
int path[N];
int nil = -1;
int parent[N], _rank[N];
queue<int> _queue;
map <int, pair<int, int>> bridges;

void init(){
	V = E = 0;
	nil = -1;

	for(int i = 0; i < N; i++) graph[i].clear();
	while(!_queue.empty()) _queue.pop();
	bridges.clear();

	memset(Mate, 0, sizeof Mate);
	memset(subset, 0, sizeof subset);
	memset(vAncestors, 0, sizeof vAncestors);
	memset(wAncestors, 0, sizeof wAncestors);
	memset(even, 0, sizeof even);
	memset(odd, 0, sizeof odd);
	memset(path, 0, sizeof path);
	for(int i = 0; i < N; i++) parent[i] = i, _rank[i] = 0;

}

int par(int x){
    if (parent[x]==x) return x;
    return parent[x]=par(parent[x]);
}

void merge(int x,int y) {
    int px = par(x);
    int py = par(y);
    if(_rank[px] > _rank[py])
        parent[py] = px;
    else
        parent[px] = py;   
    if(_rank[px] == _rank[py])
        _rank[py]++;
}

int lok(int curr, int (&anc)[N]) {
    curr = par(curr);
    anc[curr] = 1;
    int pa = par(even[curr]);
    if(pa == curr)
        return curr;
    anc[pa] = 1;
    return par(odd[pa]);
}

void reverse(int i, int j) {
    while(i<j) {
        swap(path[i], path[j]); i++; j--;
    }
}

int build(int i, int start, int goal) { 
    while(1) {
        while(odd[start] != nil) {
            pair<int, int> a = bridges[start];
            int j = build(i, a.F, start);
            reverse(i, j-1); i=j;
            start = a.S;
        }
        path[i++] = start;
        if(!Mate[start])
            return i;
        path[i++] = Mate[start];

        if(path[i-1] == goal)  
            return i;
        start = odd[path[i-1]];
    }
}

void aug(int v) {
    int n = build(0, v, nil);
    for(int i=2; i<n; i+=2) {
        Mate[path[i]] = path[i-1];
        Mate[path[i-1]] = path[i];
    } 
}

vector<int> blossomsup(int v,int w, int base) {
    int n=0;
    path[n++]=par(v); 
    pair<int, int> b = mp(v,w);

    while(path[n-1] != base) {
        int u = even[path[n-1]];
        path[n++] = u;
        bridges[u] = b;
        _queue.push(u);
        path[n++] = (par(odd[u]));
    }
    vector<int> c(n);
    for(int i=0; i<n; i++)  c[i] = path[i];
    return c;
}

void blossom(int v, int w, int base) {
    base = par(base);
    vector<int> supports1 = blossomsup(v,w,base); 
    vector<int> supports2 = blossomsup(w,v,base);
    for(int i=0; i<supports1.size(); i++) {
        merge(supports1[i], supports1[0]);
    }
    for(int i=0; i<supports2.size(); i++) {
        merge(supports2[i], supports2[0]);
    }
    even[par(base)] = even[base];
}

int check(int v, int w) {
    if(par(v) == par(w))
            return 0;
    for(int i=1; i<=V; i++)  {
        vAncestors[i] = wAncestors[i] = 0;
    }
    int vcurr=v; int wcurr=w;
    while(1) {
        vcurr = lok(vcurr, vAncestors);
        wcurr = lok(wcurr, wAncestors);
        if(vcurr == wcurr) {
            blossom(v,w,vcurr);
            return 0;
        }
        if(par(even[vcurr]) == vcurr && par(even[wcurr]) == wcurr) {
            aug(v); aug(w);
            Mate[v]=w; Mate[w]=v;
            return 1;
        }
        if(wAncestors[vcurr]) {
            blossom(v,w,vcurr);
            return 0;
        }
        if(vAncestors[wcurr]) {
            blossom(v,w,wcurr);
            return 0;
        }
    }
}

int augment() {
    for(int i=1; i<=V; i++)  {
        even[i] = odd[i] = -1;
        parent[i] = i; _rank[i] = 0;
    }
    while(!_queue.empty())
        _queue.pop();
    bridges.clear();
    for(int i=1; i<=V; i++) {
        if(subset[i] && !Mate[i]) {
            even[i] = i;
            _queue.push(i);
        }
    }
    while(!_queue.empty()) {
        int v = _queue.front();
        _queue.pop();

        for(int i=0; i<graph[v].size(); i++) {
            int w = graph[v][i];
            if(!subset[w])
                continue;
            if(even[par(w)] != nil) {
                if(check(v, w))
                    return 1;
            }
            else if(odd[w] == nil) {
                odd[w] = v;
                int u = Mate[w];
                if(even[par(u)] == nil) {
                    even[u] = w;
                    _queue.push(u);
                }
            }
        }
    }
    return 0;
}

void Matching() {
    for(int i=1 ; i<=V; i++) {
        Mate[i] = 0;
        vAncestors[i] = wAncestors[i] = 0;
        subset[i] = 1;
    }
    while(augment());
}

int Output() {
    int Count = 0;
    for (int i = 1; i <= V; i++)
        if (Mate[i] > i)
            Count++;
    return Count;
}

void add_edge(int i, int j){
	graph[i].push_back(j);
	graph[j].push_back(i);
}

vector<int> con[N];
char s[N];
int main(){
	int t; sd(t);
	while(t--){
		int n, m; sd(n); sd(m);
		for(int i = 1; i <= n; i++) con[i].clear();
		for(int i = 1; i <= n; i++){
			scanf("%s", s);
			for(int j = 0; j < m; j++) if(s[j] == '1') con[i].push_back(j + 1);
		}
		int lo = 0, hi = m >> 1;
		while(lo < hi){
			int mmid = (lo + hi) >> 1; 
			int mid = 2 * mmid + (m & 1);
			init();
			V = 2 * n + m + mid;
			for(int i = 1; i <= n; i++){
				add_edge(i, i + n);
				for(int j : con[i]) add_edge(i, j + 2 * n), add_edge(i + n, j + 2 * n);
			}
			for(int i = 1; i <= m; i++)
				for(int j = 1; j <= mid; j++) add_edge(2 * n + i, 2 * n + m + j);
			Matching();
			int num = Output();
			if(2 * Output() == 2 * n + m + mid){
				hi = mmid;
			} else lo = mmid + 1;
		}
		printf("%d\n", (m>>1) - lo);
	}	
}