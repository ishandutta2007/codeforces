#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int a, b;

int p[MAXN], q[MAXN];

int gao(int p, int q, int x, int y){
	if ((p + q) <= a && x <= b && y <= b)
		return 1;
	if ((p + q) <= b && x <= a && y <= a)
		return 1;
	return 0;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
		cin >> p[i] >> q[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++){
			if (gao(p[i], p[j], q[i], q[j])
				|| gao(p[i], q[j], q[i], p[j])
				|| gao(q[i], p[j], p[i], q[j])
				|| gao(q[i], q[j], p[i], p[j]))
				ans = max(ans, p[i] * q[i] + p[j] * q[j]);
		}
	cout << ans << endl;
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