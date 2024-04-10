#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;
const int N = 1000;
const int INF = MM;

int aim[100];
int n; 
char s[100];
int pre[111][111];
 
struct Edge{
    int from,to,cap,flow,cost;
};
struct MCMF{
    int n,m,s,t;
    vector<Edge>edges;
    vector<int>G[N];
    int inq[N];//
    int d[N];//Bellman-Ford
    int p[N];//
    int a[N];//
 
    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++)
            G[i].clear();
        edges.clear();
    }
    void addedge(int from,int to,int cap,int cost){
        edges.push_back((Edge){from,to,cap,0,cost});
        edges.push_back((Edge){to,from,0,0,-cost});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

	void GetAim() {
		for (int i = 1; i <= 64; i++) {
			for (auto &j : G[i]) {
				//cout << i << ' ' << edges[j].cost << ' ' << edges[j].cap << ' ' << edges[j].flow << endl;
				if (edges[j].cost > 0 && edges[j].flow > 0) {
					aim[i] = edges[j].to - 64;
				}
			}
		}
	}
 
    bool BellmanFord(int s,int t,int&flow,long long&cost){
        for(int i=0;i<n;i++)
            d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=0,inq[s]=1,p[s]=0,a[s]=INF;
 
        queue<int>q;
        q.push(s);
        while(!q.empty()){
            int u=q.front();q.pop();
            inq[u]=0;
            for(int i=0;i<G[u].size();i++){
                Edge&e=edges[G[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];//
                    a[e.to]=min(a[u],e.cap-e.flow);//min{ue}
                    if(!inq[e.to]){q.push(e.to);inq[e.to]=1;}
                }
            }
        }
        if(d[t]==INF)
            return false;
        flow+=a[t];
        cost+=(long long)d[t]*a[t];
        int u=t;
        while(u!=s){
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
            u=edges[p[u]].from;
        }
        return true;
    }

    int MincostMaxflow(int s,int t,long long&cost){
        int flow=0;
        cost=0;
        while(BellmanFord(s,t,flow,cost));
            return flow;
    }
} nico;

int vis[9][9];
PII a[1111];

void gao(int _x, int _y) {
	int st = (_x - 1) * 8 + _y;
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			vis[i][j] = INF;
	queue<PII> Q;
	Q.push(PII(_x, _y));
	vis[_x][_y] = 1;
	static int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
	static int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 8; i++) {
			int u = x + dx[i], v = y + dy[i];
			if (1 <= u && u <= 8 && 1 <= v && v <= 8 && vis[u][v] == INF) {
				vis[u][v] = vis[x][y] + 1;
				pre[st][(u-1)*8+v] = (x-1)*8+y;
				Q.push(PII(u, v));
			}
		}
	}
	nico.addedge(0, st, 1, 0);
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++) if ((i - 1) * 8 + j <= ::n){
			nico.addedge(st, 64 + (i - 1) * 8 + j, 1, vis[i][j]);
		}
}

map<int, int> E[1111];
int cb[1111];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		a[i] = PII(s[1] - '0', s[0] - 'a' + 1);
	}
	nico.init(130);
	//for (int i = 1; i <= 64; i++)
	//	nico.addedge(0, i, 1, 0);
	for (int i = 1; i <= n; i++)
		nico.addedge(64 + i, 129, 1, 0);
	for (int i = 1; i <= n; i++) {
		gao(a[i].first, a[i].second);
	}
	ll p = 0;
	nico.MincostMaxflow(0, 129, p);
	//cout << p << endl;
	nico.GetAim();
	auto pt = [](int x) {
		printf("%c%d", 'a' + (x - 1) % 8, (x - 1) / 8 + 1);
	};
	for (int i = 1; i <= n; i++) {
		int st = (a[i].first - 1) * 8 + a[i].second;
		int ed = aim[st];
		while (ed != st) {
			int pr = pre[st][ed];
			E[pr][ed]++;
			ed = pre[st][ed];
			//cout << i << ' ' << st << ' ' << ed << endl;
		}
		cb[st] = i;
		//pt(aim[st]);
		//cout << ' ' << st << ' ' << aim[st] << ' ' << endl;
	}
	vector<PII> ans;
	do {
		int flag = 0;
		for (int i = 1; i <= 64; i++)
			if (cb[i]) {
				for (auto &j : E[i]) {
					if (cb[j.first] == 0) {
						ans.push_back(PII(i, j.first));
						cb[j.first] = cb[i];
						cb[i] = 0;
						if (j.second == 1)
							E[i].erase(j.first);
						else
							E[i][j.first]--;
						flag = 1;
						goto KKE;
					}
				}
			}
		KKE:
		if (!flag) break;
	} while (true);
	printf("%d\n", (int)ans.size());
	for (auto &x : ans) {
		pt(x.first);
		putchar('-');
		pt(x.second);
		puts("");
	}
	return 0;
}