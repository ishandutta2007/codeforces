#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e3 + 10;
const int MAXM = 2e6 + 10;

struct Pt{
	long long x, y;
};

struct Cir{
	Pt c;
	long long r;
};

bool operator < (const Pt & a, const Pt & b){
	if (a.x == b.x)
		return a.y < b.y;
	else
		return a.x < b.x;
}

bool operator == (const Pt & a, const Pt & b){
	return a.x == b.x && a.y == b.y;
}

inline long long operator * (const Pt & a, const Pt & b){
	return a.x * b.y - a.y * b.x;
}

inline long long operator % (const Pt & a, const Pt & b){
	return a.x * b.x + a.y * b.y;
}

inline Pt operator - (const Pt & a, const Pt & b){
	return (Pt){a.x - b.x, a.y - b.y};
}

inline Pt operator + (const Pt & a, const Pt & b){
	return (Pt){a.x + b.x, a.y + b.y};
}

ll sqr(long long x){
	return x * x;
}

inline ll len(const Pt & a){
	return sqr(a.x) + sqr(a.y);
}

void read(){

}

vector<Cir> a;
vector<int> E[MAXN];
vector<int> F[MAXN];
int fa[MAXN];

double ans;

double dfs(int u, int flag){
	double ret = a[u].r * a[u].r;
	double sum = 0;
	for(int v, i = 0; i < E[u].size(); i++){
		v = E[u][i];
		dfs(v, 1 - flag);
		sum += a[v].r * a[v].r;
	}
	if (flag)
		ans += ret - sum;
}

void solve(){
	int n;
	scanf("%d", &n);
	a.resize(n + 1);
	for(int i = 1; i <= n; i++)
		scanf("%lld%lld%lld", &a[i].c.x, &a[i].c.y, &a[i].r);
	a[0].c.x = a[0].c.y = 0, a[0].r = 1e7;
	for(int i = 0; i <= n; i++)
		for(int j = i + 1; j <= n; j++){
			if (len(a[i].c - a[j].c) < sqr(a[i].r + a[j].r)){
				if (a[i].r > a[j].r){
					F[j].push_back(i);
					//E[i].push_back(j);
				}
				else{
					F[i].push_back(j);
					//E[j].push_back(i);
				}
			}
		}
	for(int i = 1; i <= n; i++){
		sort(F[i].begin(), F[i].end(), [&](const int & p, const int & q){
			return a[p].r < a[q].r;
		});
		fa[i] = F[i][0];
		//E[F[i][0]].push_back(i);
	}
	for(int i = 0; i <= n; i++){
	//	cout << E[i].size() << endl;
	//	for(int j = 0; j < E[i].size(); j++)
	//		cout << E[i][j] << ' ' ; cout << endl;
	}
	for(int i = 1; i <= n; i++){
		if (fa[fa[i]] == 0){
			E[fa[fa[i]]].push_back(i);
		}
		else{
			E[fa[i]].push_back(i);
		}
	}
	ans = 0;
	dfs(0, 0);
	printf("%.15f\n", acos(-1) * ans);
}

void printans(){

}

int main(){
	int T = 1;
//	cin >> T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}