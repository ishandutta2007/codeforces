#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

const int N = 3005;
bitset<N> con[N];
vector<pii> vec;

inline int sq(int t){return t * t;}

int D[N][N];
int x[N], y[N];
int n; 

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(x[i]), sd(y[i]);
		for(int j = 1; j < i; j++){
			D[i][j] = D[j][i] = sq(x[i] - x[j]) + sq(y[i] - y[j]);
			vec.push_back({i, j});
		}
	}
	sort(vec.begin(), vec.end(), [](const pii & A, const pii & B){return D[A.F][A.S] > D[B.F][B.S];});
	for(auto it : vec){
		int i = it.F, j = it.S;
		if((con[i] & con[j]).count()){
			printf("%.10lf\n", sqrt(D[i][j]) / 2.);
			return 0;
		}
		con[i][j] = con[j][i] = 1;
	}
}