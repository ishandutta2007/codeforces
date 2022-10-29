#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 1000 + 10;

int n, m;
int t, K;

void prework(){

}

void read(){

}

int dis[MAXN], vis[MAXN];
typedef pair<int, PII> PIP;
vector<PII> E[MAXN];
vector<PIP> eg;
int a[MAXN][MAXN];

void spfa(int s){
	for (int i = 1; i <= n; i++)
		dis[i] = MM, vis[i] = 0;
	dis[s] = 0;
	vis[s] = 1;
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()){
		int x = Q.front();
		Q.pop();
		vis[x] = 0;
		for (auto &y : E[x]){
			if (dis[y.first] > dis[x] + y.second){
				dis[y.first] = dis[x] + y.second;
				if (!vis[y.first]){
					Q.push(y.first);
					vis[y.first] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		//ds[s][i] = dis[i];
		if (dis[i] != MM)
			eg.push_back(PIP(dis[i], PII(s, i)));
	}
}

class Network {
public:
    typedef int VAL;
    static const int SIZE = 2005;  
    static const int INF = 1000000007;
    typedef struct ARC{int t,c; VAL w; ARC* o;}* PTR;
    ARC arc[2000005];
    PTR now[SIZE],e[SIZE];  
    int cnt[SIZE],l[SIZE],r[SIZE],edge;
    VAL sum; 
    void clear(){memset(e,edge=sum=0,sizeof(e));} 
    ARC& REV(PTR x){return arc[(x-arc)^1];}   
    int flow(int S, int T){return improved_sap(S,T,INF);}
    PTR add_edge(int x, int y, int c, VAL w = 0){
        e[x]=&(arc[edge++]=(ARC){y,c,+w,e[x]});
        e[y]=&(arc[edge++]=(ARC){x,0,-w,e[y]});
        return e[x];
    }
    int aug(int S, int T, int& can){
        int x,z=T,use=can;
        for(x=S;x!=T;x=now[x]->t) if(use>now[x]->c) use=now[z=x]->c;
        for(x=S;x!=T;x=now[x]->t){
                now[x]->c-=use;
            REV(now[x]).c+=use;
            sum+=use*now[x]->w;
        }
        can-=use;
        return z;
    }
    int improved_sap(int S, int T, int can){ // can
        if(S==T) return can;
        int in=can,x,m;
        memcpy(now,e,sizeof(now));
        memset(cnt,0,sizeof(cnt));
        fill_n(l,SIZE,int(SIZE));
        for(int i=m=l[r[0]=T]=0;i<=m;i++){
            cnt[l[x=r[i]]]++;
            for(PTR u=e[x];u;u=u->o)
                if(l[u->t]==SIZE && REV(u).c) l[r[++m]=u->t]=l[x]+1;
        }
        for(x=r[S]=S;l[S]!=SIZE;x=r[x]){
        JMP:for(PTR& u=now[x];u;u=u->o) if(l[u->t]<l[x] && u->c){
                r[u->t]=x;
                x=u->t==T?aug(S,T,can):u->t;
                if(x==T) return in; else goto JMP;
            }
            if(!--cnt[l[x]]) break; else l[x]=SIZE;
            for(PTR u=e[x];u;u=u->o)
                if(l[u->t]+1<l[x] && u->c) now[x]=u,l[x]=l[u->t]+1;
            if(l[x]!=SIZE) cnt[l[x]]++;
        }
        return in-can;
    }
} nico;

int st[MAXN];
int isst[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%d%d%d", &n, &m, &t, &K);
	for (int i = 1; i <= t; i++){
		scanf("%d", &st[i]);
		isst[st[i]]++;
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = MM;
	
	for (int i = 1; i <= m; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[y][x] = a[x][y] = min(a[x][y], z);
		//E[x].push_back(PII(y, z));
		//E[y].push_back(PII(x, z));
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++){
			if (a[i][j] != MM){
				E[i].push_back(PII(j, a[i][j]));
				E[j].push_back(PII(i, a[j][i]));
			}
		}
	
	for (int i = 1; i <= n; i++)
		if (isst[i]){
			spfa(i);
		}
	nico.clear();
	sort(eg.begin(), eg.end());
	for (int i = 1; i <= n; i++)
		if (isst[i]){
			nico.add_edge(0, i, isst[i]);
		}
	for (int i = 1; i <= n; i++)
		nico.add_edge(n + i, 2 * n + 1, 1);
	int ans = 0;
	for (int i = 0; i < eg.size(); i++){
		nico.add_edge(eg[i].second.first, eg[i].second.second + n, 1);
		while(i + 1 < eg.size() && eg[i+1].first == eg[i].first){
			i++;
			nico.add_edge(eg[i].second.first, eg[i].second.second + n, 1);
		}
		ans += nico.flow(0, 2 * n + 1);
		//cout << eg[i].first << ' ' << ans << endl;
		if (ans >= K){
			printf("%d\n", eg[i].first);
			return ;
		}
	}
	printf("-1\n");
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}