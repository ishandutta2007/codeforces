#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define FOR(a,b,c) for (int c = (a), _for = (b); c < _for; ++c)
#define REP(n) for (int _rep = 0, _for = (n); _rep < _for; ++_rep)
#define pb push_back
#define x first
#define y second
#define ll long long
#define pii pair < int, int >
#define all(x) (x).begin(), (x).end()

using namespace std;

const int oo = 1000000000;

int n, m;
vector < int > E[3005];

int s1, t1, l1;
int s2, t2, l2;

vector < int > BFS(int st){
	vector < int > R(n + 1, oo);
	R[st] = 0;
	queue < int > Q;
	Q.push(st);
	while (!Q.empty()){
		st = Q.front(); Q.pop();
		for (auto x : E[st])
			if (R[x] > R[st] + 1){
				R[x] = R[st] + 1;
				Q.push(x);
			}
	}
	return R;
}

int main(){
	scanf("%d%d", &n, &m);
	REP(m){
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].pb(b), E[b].pb(a);
	}
	scanf("%d%d%d", &s1, &t1, &l1);
	scanf("%d%d%d", &s2, &t2, &l2);
	vector < int > vs1 = BFS(s1), vs2 = BFS(s2), vt1 = BFS(t1), vt2 = BFS(t2);
	if (vs1[t1] > l1 || vs2[t2] > l2){printf("-1\n"); return 0;}
	
	int R = m - vs1[t1] - vs2[t2];
	
	FOR(1, n + 1, A){
		vector < int > va = BFS(A);
		FOR(1, n + 1, B){
			if (va[s1] + va[B] + vt1[B] <= l1 && va[s2] + va[B] + vt2[B] <= l2)
				R = max(R, m - (va[s1] + va[B] + vt1[B] + va[s2] + vt2[B]));
			if (va[s1] + va[B] + vt1[B] <= l1 && va[t2] + va[B] + vs2[B] <= l2)
				R = max(R, m - (va[s1] + va[B] + vt1[B] + va[t2] + vs2[B]));
			
		}
	}
	
	printf("%d\n", R);
	
	return 0;
}