#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>


#include <vector>

namespace atcoder {

namespace internal {

template <class T> struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    explicit mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        std::vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder


std::vector<int> V;
std::vector< std::pair<int,int> > P;
int x[1010],y[1010],ans[1010];
std::map<int,int> M,count;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		P.clear();
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		std::sort(x+1,x+a+1);
		std::sort(y+1,y+a+1);
		
		int d;
		for(int i=1;i<=a;i++) V.push_back(x[i]+y[a-i+1]);
		std::sort(V.begin(),V.end());
		if(V[0]==V.back())
		{
			d = V[0];
			for(int i=1;i<=a;i++) P.push_back(std::make_pair(i,a-i+1));
		}
		else
		{
			M.clear();
			count.clear();
			int control = 0;
			if(y[a]>=x[a])
			{
				for(int i=a;i>=1;i--) M[x[i]] = i;
				for(int i=1;i<=a;i++) count[x[i]]++;
				
				for(int i=1;i<=a;i++)
				{
					d = y[a]-x[i];
					
					atcoder::mf_graph<int> G(2*a+3);
					int source = 2*a+1, sink = 2*a+2;
					for(int j=1;j<=a;j++)
					{
						if(M.find(d-y[j])!=M.end()) G.add_edge(j,a+M[d-y[j]],1);
						if(M.find(y[j]-d)!=M.end()) G.add_edge(j,a+M[y[j]-d],1);
						if(M.find(y[j]+d)!=M.end()) G.add_edge(j,a+M[y[j]+d],1);
					}
					for(int j=1;j<=a;j++) G.add_edge(source,j,1);
					for(int j=1;j<=a;j++) if(M[x[j]]==j) G.add_edge(a+j,sink,count[x[j]]);
					int F = G.flow(source,sink);
					if(F==a)
					{
						for(int j=0;j<G.edges().size();j++)
						{
							if(G.get_edge(j).flow==0) continue;
							int from = G.get_edge(j).from;
							int to = G.get_edge(j).to-a;
							if(1<=from&&from<=a&&1<=to&&to<=a)
							{
								P.push_back(std::make_pair(M[x[to]],from));
								M[x[to]]++;
							}
						}
						control = 1;
						break;
					}
				}
				if(control==0)
				{
					printf("NO\n");
					continue;
				}
			}
			else
			{
				for(int i=a;i>=1;i--) M[y[i]] = i;
				for(int i=1;i<=a;i++) count[y[i]]++;
				
				for(int i=1;i<=a;i++)
				{
					d = x[a]-y[i];
					
					atcoder::mf_graph<int> G(2*a+3);
					int source = 2*a+1, sink = 2*a+2;
					for(int j=1;j<=a;j++)
					{
						if(M.find(d-x[j])!=M.end()) G.add_edge(j,a+M[d-x[j]],1);
						if(M.find(x[j]-d)!=M.end()) G.add_edge(j,a+M[x[j]-d],1);
						if(M.find(x[j]+d)!=M.end()) G.add_edge(j,a+M[x[j]+d],1);
					}
					for(int j=1;j<=a;j++) G.add_edge(source,j,1);
					for(int j=1;j<=a;j++) if(M[y[j]]==j) G.add_edge(a+j,sink,count[y[j]]);
					int F = G.flow(source,sink);
					if(F==a)
					{
						for(int j=0;j<G.edges().size();j++)
						{
							if(G.get_edge(j).flow==0) continue;
							int from = G.get_edge(j).from;
							int to = G.get_edge(j).to-a;
							if(1<=from&&from<=a&&1<=to&&to<=a)
							{
								P.push_back(std::make_pair(from,M[y[to]]));
								M[y[to]]++;
							}
						}
						control = 1;
						break;
					}
				}
				if(control==0)
				{
					printf("NO\n");
					continue;
				}
			}
		}
		
		int p1 = 0, p2 = d;
		for(int i=0;i<P.size();i++)
		{
			int d1 = x[P[i].first];
			int d2 = y[P[i].second];
			if(d1+d2==d) ans[i+1] = d1;
			else if(d1-d2==d) ans[i+1] = d1;
			else ans[i+1] = -d1;
		}
		
		int min = 0;
		for(int i=1;i<=a;i++) min = min<ans[i]?min:ans[i];
		p1 -= min ,p2 -= min;
		for(int i=1;i<=a;i++) ans[i] -= min;
		
		printf("YES\n");
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
		printf("%d %d\n",p1,p2);
	}
}