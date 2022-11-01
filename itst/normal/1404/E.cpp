#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;

const int MAXN = 2e5 + 7 , MAXM = 2e6 + 7;
struct Edge{
	int end , upEd , f;
}Ed[MAXM];
int head[MAXN] , cur[MAXN] , dep[MAXN] , N , M , S , T , cntEd = 1;
queue < int > q;

inline void addEd(int a , int b , int c){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	Ed[cntEd].f = c;
	head[a] = cntEd;
}
void addE(int a , int b , int c){addEd(a , b , c); addEd(b , a , 0);}

inline bool bfs(){
	while(!q.empty())
		q.pop();
	q.push(S);
	memset(dep , 0 , sizeof(int) * (T + 1));
	dep[S] = 1;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i = head[t] ; i ; i = Ed[i].upEd)
			if(Ed[i].f && !dep[Ed[i].end]){
				dep[Ed[i].end] = dep[t] + 1;
				if(Ed[i].end == T){
					memcpy(cur , head , sizeof(head));
					return 1;
				}
				q.push(Ed[i].end);
			}
	}
	return 0;
}

inline int dfs(int x , int mF){
	if(x == T)
		return mF;
	int sum = 0;
	for(int &i = cur[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].f && dep[Ed[i].end] == dep[x] + 1){
			int t = dfs(Ed[i].end , min(mF - sum , Ed[i].f));
			if(t){
				Ed[i].f -= t;
				Ed[i ^ 1].f += t;
				sum += t;
				if(sum == mF)
					break;
			}
		}
	return sum;
}

char str[203][203];

#define id(i,j) (((i) - 1) * M + (j))

int main(){
	cin >> N >> M; for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= M ; ++j) cin >> str[i][j];
	int cnt = N * M , num = 0 , pr = 0; T = 4 * N * M + 1;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= M ; ++j){
			num += str[i][j] == '#';
			if(str[i][j] == '#' && str[i][j + 1] == '#'){
				++pr; ++cnt; addE(S , cnt , 1); addE(cnt , id(i , j) , 1); addE(cnt , id(i , j + 1) , 1);
			}
			if(str[i][j] == '#' && str[i + 1][j] == '#'){
				++pr; ++cnt; addE(cnt , T , 1); addE(id(i , j) , cnt , 1); addE(id(i + 1 , j) , cnt , 1);
			}
		}
	while(bfs()) pr -= dfs(S , 1e9);
	cout << num - pr << endl; return 0;
}