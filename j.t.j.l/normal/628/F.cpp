#include<bits/stdc++.h>

using namespace std;

const int MAXN=70000,MAXM=440000;
struct Dinic{
    struct edge{
        int x,y;// 
        int c;// 
        int f;// 
        edge *next,*back;// 
        edge(int x,int y,int c,edge* next):x(x),y(y),c(c),f(0),next(next),back(0){}
        void* operator new(size_t, void *p){return p;}
    }*E[MAXN],*data;//E[i]i
    char storage[2*MAXM*sizeof(edge)];
    int S,T;//
    
    int Q[MAXN];//DFSqueue
    int D[MAXN];//-1
    void DFS(){
        memset(D,-1,sizeof(D));
        int head=0,tail=0;
        Q[tail++]=S;
        D[S]=0;
        for(;;){
            int i=Q[head++];
            for(edge* e=E[i];e;e=e->next){
                if(e->c==0)continue;
                int j=e->y;
                if(D[j]==-1){
                    D[j]=D[i]+1;
                    Q[tail++]=j;
                    if(j==T)return;
                }
            }
            if(head==tail)break;
        }
    }
    edge* cur[MAXN];//
    edge* path[MAXN];//
    int flow(){
        int res=0;// 
        int path_n;//path
        for(;;){
            DFS();
            if(D[T]==-1)break;
            memcpy(cur,E,sizeof(E));
            path_n=0;
            int i=S;
            for(;;){
                if(i==T){// 
                    int mink=0;
                    int delta=INT_MAX;
                    for(int k=0;k<path_n;++k){
                        if(path[k]->c < delta){
                            delta = path[k]->c;
                            mink=k;
                        }
                    }
                    for(int k=0;k<path_n;++k){
                        path[k]->c -= delta;
                        path[k]->back->c += delta;
                    }
                    path_n=mink;// 
                    i=path[path_n]->x;
                    res+=delta;
                }
                edge* e;
                for(e=cur[i];e;e=e->next){
                    if(e->c==0)continue;
                    int j=e->y;
                    if(D[i]+1==D[j])break;// 
                }
                cur[i]=e;//
                if(e){
                    path[path_n++]=e;
                    i=e->y;
                }
                else{// 
                    D[i]=-1;
                    if(path_n==0)break;
                    path_n--;
                    i=path[path_n]->x;
                }
            }
        }
        return res;
    }
    int cut(int* s){
        int rst=0;
        for(int i=0;i<MAXN;++i)
            if(D[i]==-1&&E[i])
                s[rst++]=i;
        return rst;
    }
    void init(int _S,int _T){
        S=_S,T=_T;
        data=(edge*)storage; 
        memset(E,0,sizeof(E));
    }
    void add_edge(int x,int y,int w){//xyw0<=x,y<MAXN0<w<=INT_MAX 
        E[x]=new((void*)data++) edge(x,y,w,E[x]);
        E[y]=new((void*)data++) edge(y,x,0,E[y]);
        E[x]->back = E[y];
        E[y]->back = E[x];
    }
};

const int INF = 1e7;
Dinic dinic;
typedef long long ll;
typedef pair<int, int> PII;
PII a[20010];

int main(){
	int n, b, q;
	cin>>n>>b>>q;
	for(int i = 1; i <= q; i++){
		scanf("%d%d", &(a[i].first), &(a[i].second));
	}
	sort(a + 1, a + q + 1);
	a[q+1] = (PII){b, n};
	a[0] = (PII){0, 0};
	q++;
	dinic.init(0, 6 * q + 6);
	int flag = 1;
//	ll Nd = 0;
	for(int i = 1; i <= q; i++){
		if (a[i].second - a[i-1].second < 0){
			puts("unfair");
			return 0;
		}
		else
			dinic.add_edge(0, i, a[i].second - a[i-1].second);
	}
	for(int i = 1; i <= q; i++){
		for(int j = 0; j < 5; j++){
			dinic.add_edge(i, q + (i - 1) * 5 + j + 1, (a[i].first - j + 5) / 5 - (a[i - 1].first - j + 5) / 5);
			dinic.add_edge(q + (i - 1) * 5 + j + 1, 6 * q + 1 + j, (a[i].first - j + 5) / 5 - (a[i - 1].first - j + 5) / 5);
		}
	}
	for(int j = 0; j < 5; j++)
		dinic.add_edge(6 * q + 1 + j, 6 * q + 6, n / 5);
	if (dinic.flow() == n)
		puts("fair");
	else
		puts("unfair");
	return 0;
}
	

/*
int main(){
	int T;scanf("%d", &T);
	while(T--){
		int P, D, H, N;
		scanf("%d%d%d%d", &P, &D, &H, &N);
		for(int i = 1; i <= P; i++)
			scanf("%d", &L[i]);
		int Lbegin, Lend;
		scanf("%d%d", &Lbegin, &Lend);
		int tot = 0;
		for(int i = 1; i <= D; i++)
			for(int j = 1; j <= H; j++)
				scanf("%d", &R[i][j]), tot += R[i][j];
		for(int k = 1; k <= P; k++)
			for(int i = 1; i <= D; i++)
				for(int j = 1; j <= H; j++)
					scanf("%d", &F[k][i][j]);
		dinic.init(0, D*(H+3*P)+P+1);
		for(int i = 1; i <= D; i++)
			for(int j = 1; j <= H; j++)
				dinic.add_edge(0, (i-1)*H+j, R[i][j]);
		for(int i = 1; i <= D; i++)
			for(int j = 1; j <= H; j++)
				for(int k = 1; k <= P; k++)
					if (F[k][i][j]){
						if (j >= Lbegin && j <= Lend)
							dinic.add_edge((i-1)*H+j, D*H+(i-1)*P+k, 1);				
						else
							dinic.add_edge((i-1)*H+j, D*(H+P)+(i-1)*P+k, 1);
					}
		int flag = 1;
		for(int i = 1; i <= D; i++)
			for(int k = 1; k <= P; k++){
				int tmp = 0;
				for(int j = Lbegin; j <= Lend; j++)
					tmp += (1 - F[k][i][j]);
				dinic.add_edge(D*H+(i-1)*P+k, D*(H+2*P)+(i-1)*P+k, Lend-Lbegin-tmp);
				flag &= (Lend-Lbegin-tmp >= 0);
				dinic.add_edge(D*(H+P)+(i-1)*P+k, D*(H+2*P)+(i-1)*P+k, INF);
			}
		for(int k = 1; k <= P; k++){
			for(int i = 1; i <= D; i++){
				int tmp = N;
				for(int j = 1; j <= H; j++)
					tmp -= (1 - F[k][i][j]);
				dinic.add_edge(D*(H+2*P)+(i-1)*P+k, D*(H+3*P)+k, tmp);
				flag &= (tmp >= 0);
			}
			dinic.add_edge(D*(H+3*P)+k, D*(H+3*P)+P+1, L[k]);
		}
		if (flag && dinic.flow() == tot)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}*/