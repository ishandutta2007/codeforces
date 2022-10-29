#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 1e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int vis[MAXN];
vector<int> E[MAXN];
vector<PII> F[MAXN];
int ret[MAXN], ret2[MAXN];
int st;

int l[MAXN], r[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%d%d", &n, &m, &st);
	for (int i = 1; i <= n; i++)
		E[i].clear(), F[i].clear();
	int mm = 0;
	for (int i = 1; i <= m; i++){
		int tp, x, y;
		scanf("%d%d%d", &tp, &x, &y);
		if (tp == 1){
			E[x].push_back(y);
		}
		else{
			mm++;
			l[mm] = x;
			r[mm] = y;
			F[x].push_back(PII(y, mm));
			F[y].push_back(PII(x, mm));
		}
	}
	queue<int> Q;
	Q.push(st);
	vis[st] = 1;
	while(!Q.empty()){
		int x = Q.front();
		Q.pop();
		for (auto &y : E[x]){
			if (!vis[y]){
				vis[y] = 1;
				Q.push(y);
			}
		}
	}
	int ans2 = 0, ans1 = 0;
	for (int i = 1; i <= n; i++)
		ans2 += vis[i];
	for (int i = 1; i <= mm; i++){
		if (vis[l[i]] == vis[r[i]]){
			ret2[i] = 1;
		}
		else{
			if (vis[l[i]])
				ret2[i] = -1;
			else
				ret2[i] = 1;
		}
	}
	queue<int> P;
	for (int i = 1; i <= n; i++){
		if (vis[i])
			P.push(i);
	}
	while(!P.empty()){
		while(!P.empty()){
			int x = P.front();
			P.pop();
			for (auto &y : F[x]){
				if (!vis[y.first]){
					ret[y.second] = (l[y.second] == x ? 1 : -1);
					vis[y.first] = 1;
					Q.push(y.first);
				}
			}
		}
		while(!Q.empty()){		
			int x = Q.front();
			Q.pop();
			P.push(x);
			for (auto &y : E[x]){
				if (!vis[y]){
					vis[y] = 1;
					Q.push(y);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		ans1 += vis[i];
	for (int i = 1; i <= mm; i++){
		if (ret[i] == 0){
			ret[i] = 1;
		}
	}
	printf("%d\n", ans1);
	for (int i = 1; i <= mm; i++)
		printf("%c", ret[i] > 0 ? '+' : '-');
	puts("");
	printf("%d\n", ans2);
	for (int i = 1; i <= mm; i++)
		printf("%c", ret2[i] > 0 ? '+' : '-');
	puts("");
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