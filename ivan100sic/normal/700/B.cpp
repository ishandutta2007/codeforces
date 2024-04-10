#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> E[200005];
int C[200005], T[200005];
int N, M, P;

void dfs(int x, int od){
	T[x] = C[x];
	for (int y : E[x]) if (y != od){
		dfs(y, x);
		T[x] += T[y];
	}
}

int main(){
	cin >> N >> P;
	for (int i=1; i<=P; i++){
		int a, b;
		cin >> a >> b;
		C[a]++;
		C[b]++;
	}
	for (int i=1; i<N; i++){
		int a, b;
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	dfs(1, 1);
	long long s = 0;
	for (int i=2; i<=N; i++){
		s += min(2*P - T[i], T[i]);
	}
	cout << s << endl;
	return 0;
}