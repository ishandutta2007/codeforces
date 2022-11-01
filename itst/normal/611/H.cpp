#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

#define INF 1e9
namespace flow{
    const int MAXN = 1e5 + 7 , MAXM = 1e6 + 7;
    struct Edge{
        int end , upEd , f;
    }Ed[MAXM];
    int head[MAXN] , dep[MAXN] , cur[MAXN] , S , T , cntEd = 1;
    queue < int > q;

    inline void addEd(int a , int b , int c){
        Ed[++cntEd] = (Edge){b , head[a] , c};
        head[a] = cntEd;
        Ed[++cntEd] = (Edge){a , head[b] , 0};
        head[b] = cntEd;
    }
    
    bool bfs(){
        memset(dep , 0 , sizeof(int) * (T + 1));
        dep[S] = 1;
        while(!q.empty()) q.pop();
        q.push(S);
        while(!q.empty()){
            int t = q.front(); q.pop();
            for(int i = head[t] ; i ; i = Ed[i].upEd)
                if(!dep[Ed[i].end] && Ed[i].f){
                    dep[Ed[i].end] = dep[t] + 1;
                    if(Ed[i].end == T){
                        memcpy(cur , head , sizeof(int) * (T + 1));
                        return 1;
                    }
                    q.push(Ed[i].end);
                }
        }
        return 0;
    }
    
    int dfs(int x , int minN){
        if(x == T) return minN;
        int sum = 0;
        for(int &i = cur[x] ; i ; i = Ed[i].upEd)
            if(Ed[i].f && dep[Ed[i].end] == dep[x] + 1){
                int t = dfs(Ed[i].end , min(Ed[i].f , minN - sum));
                sum += t;
                Ed[i].f -= t;
                Ed[i ^ 1].f += t;
                if(sum == minN) break;
            }
        return sum;
    }

    int Dinic(){
        int sum = 0;
        while(bfs())
            sum += dfs(S , INF);
        return sum;
    }

	void clear(){
		memset(head , 0 , sizeof(int) * (T + 1));
		cntEd = 1;
	}
}

int cnt[7][7] , edge[7][2] , N , Cnt = 1 , cur = -1 , tmp;

inline int poww(int a , int b){
    int times = 1;
    while(b){
        if(b & 1) times *= a;
        a *= a;
        b >>= 1;
    }
    return times;
}

int getStr(){
    char c = getchar();
    int cnt = 0;
    while(c != '?') c = getchar();
    while(c == '?'){++cnt; c = getchar();}
    return cnt;
}

#define PII pair < int , int >
#define st first
#define nd second
vector < PII > Edge;

void clear(){
	for(int i = 1 ; i < Cnt ; ++i)
		++cnt[edge[i][0]][edge[i][1]];
	Edge.clear();
}

int fa[7];

int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

bool next_tree(){
	while(++cur < (1 << (Cnt * (Cnt - 1) / 2))){
		int tmp = 0 , cnt = 0; bool f = 1;
		for(int i = 1 ; i <= Cnt ; ++i) fa[i] = i;
		for(int i = 1 ; i <= Cnt ; ++i)
			for(int j = i + 1 ; j <= Cnt ; ++j){
				if(cur & (1 << tmp))
					if(find(i) != find(j)){
						fa[find(i)] = find(j);
						edge[++cnt][0] = i;
						edge[cnt][1] = j;
					}
					else f = 0;
				++tmp;
			}
		if(f && cnt == Cnt - 1) return 1;
	}
	return 0;
}

int main(){
    scanf("%d" , &N);
    for(int i = 1 ; i < N ; ++i){
        int a = getStr() , b = getStr();
        if(a > b) swap(a , b);
        ++cnt[a][b];
    }
	Cnt = log10(N) + 1;
    flow::T = Cnt * (Cnt + 1) / 2 + 1;
	for(int i = 1 ; i <= Cnt ; ++i){
		cnt[i][i] += poww(10 , i - 1);
		if(cnt[i][i] > min(poww(10 , i) - 1 , N)){
			puts("-1"); return 0;
		}
	}
	while(next_tree()){
		bool f = 1;
		for(int i = 1 ; i < Cnt ; ++i)
			if(!cnt[edge[i][0]][edge[i][1]])
				f = 0;
		if(!f) continue;
		flow::clear();
		for(int i = 1 ; i < Cnt ; ++i){
			Edge.push_back(PII(poww(10 , edge[i][0] - 1) , poww(10 , edge[i][1] - 1)));
			--cnt[edge[i][0]][edge[i][1]];
		}
		tmp = Cnt;
		for(int i = 1 ; i <= Cnt ; ++i){
			flow::addEd(i , flow::T , min(poww(10 , i) - 1 , N) - cnt[i][i]);
			for(int j = poww(10 , i - 1) ; j < cnt[i][i] ; ++j)
				Edge.push_back(PII(j , j + 1));
		}
		for(int i = 1 ; i <= Cnt ; ++i)
			for(int j = i + 1 ; j <= Cnt ; ++j){
				flow::addEd(0 , ++tmp , cnt[i][j]);
				flow::addEd(tmp , i , INF);
				flow::addEd(tmp , j , INF);
			}
		if(flow::Dinic() + Edge.size() < N - 1) {clear(); continue;}
		tmp = Cnt;
		for(int i = 1 ; i <= Cnt ; ++i)
			for(int j = i + 1 ; j <= Cnt ; ++j){
				++tmp;
				for(int k = flow::head[tmp] ; k ; k = flow::Ed[k].upEd)
					if(flow::Ed[k].end == i)
						for(int l = 1 ; l <= flow::Ed[k ^ 1].f ; ++l)
							Edge.push_back(PII(poww(10 , j - 1) , ++cnt[i][i]));
					else
						if(flow::Ed[k].end == j)
							for(int l = 1 ; l <= flow::Ed[k ^ 1].f ; ++l)
								Edge.push_back(PII(poww(10 , i - 1) , ++cnt[j][j]));
			}
		for(auto t : Edge)
			printf("%d %d\n" , t.st , t.nd);
		exit(0);
	}
	puts("-1");
    return 0;
}