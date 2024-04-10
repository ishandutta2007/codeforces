#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
struct flow_graph{
    int MAX_V,E,s,t,head,tail;
    int *cap,*to,*next,*last,*dist,*q,*now;
    
    flow_graph(){}
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], q = new int[MAX_V], dist = new int[MAX_V], now = new int[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
    }
    
    int* add_edge(int u, int v, int uv, int vu = 0){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = vu, next[E] = last[v]; last[v] = E++;
        return cap+E-2;
    }
	
	bool bfs(){
		fill(dist,dist+MAX_V,-1);
		head = tail = 0;
		
		q[tail] = t; ++tail;
		dist[t] = 0;
		
		while(head<tail){
			int v = q[head]; ++head;
			
			for(int e = last[v];e!=-1;e = next[e]){
				if(cap[e^1]>0 && dist[to[e]]==-1){
					q[tail] = to[e]; ++tail;
					dist[to[e]] = dist[v]+1;
				}
			}
		}
		
		return dist[s]!=-1;
	}
	
	int dfs(int v, int f){
		if(v==t) return f;
		
		for(int &e = now[v];e!=-1;e = next[e]){
			if(cap[e]>0 && dist[to[e]]==dist[v]-1){
				int ret = dfs(to[e],min(f,cap[e]));
				
				if(ret>0){
					cap[e] -= ret;
					cap[e^1] += ret;
					return ret;
				}
			}
		}
		
		return 0;
	}
	
	long long max_flow(int source, int sink){
		s = source; t = sink;
		long long f = 0;
		int x;
		
		while(bfs()){
			for(int i = 0;i<MAX_V;++i) now[i] = last[i];
			
			while(true){
				x = dfs(s,INT_MAX);
				if(x==0) break;
				f += x;
			}
		}
		
		return f;
	}
}G;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int na,nb,m; cin >> na >> nb >>m;
    G = flow_graph(na+nb+2,m+na+nb);
    vector<int*> icaps;
    for(int i=1;i<=na;++i) {
        icaps.push_back(G.add_edge(0,i,0));
    }

    for(int i=1;i<=nb;++i) {
        icaps.push_back(G.add_edge(i+na, na+nb+1,0));
    }
    vi dega(na), degb(nb);
    vector<int*> ecaps;
    vector<pi> es(m);
    for(auto& [u,v]: es) {
        cin >> u >> v;
        ecaps.push_back(G.add_edge(u,v+na,1));
        dega[u-1]++,degb[v-1]++;
    }
    int klim = min(*min_element(all(dega)),*min_element(all(degb)));
    int flow=0;
    for(int k=0;k<=klim;++k) {
        flow+=G.max_flow(0,na+nb+1);
        cout << k*(na+nb)-flow << ' ';
        vi ans;
        fill(all(dega),0); fill(all(degb),0);
        auto add = [&](int i) {
            auto [u,v] = es[i];
            dega[u-1]++,degb[v-1]++;
            ans.push_back(i);
        };
        for(int i=0;i<m;++i) if(*ecaps[i]==0) {
            add(i);
        }
        for(int i=0;i<m;++i) if(*ecaps[i]==1) {
            auto [u,v] = es[i];
            if(dega[u-1]<k or degb[v-1]<k) 
                add(i);
        }
        for(auto i : ans) cout << i+1 << ' ';
        cout << '\n';
        for(auto i : icaps) (*i)++;
    }
}