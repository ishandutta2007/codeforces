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

ll a[1111][10];

ll dot(int x, int j, int k){
	ll ret = 0;
	for (int i = 1; i <= 5; i++)
		ret += (a[j][i] - a[x][i]) * (a[k][i] - a[x][i]);
	return ret;
}

int check(int x){
	for (int j = 1; j <= n; j++) if (j != x)
		for (int k = j + 1; k <= n; k++) if (k != x){
			if (dot(x, j, k) > 0)
				return 0;
		}
	return 1;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 5; j++)
			scanf("%lld", &a[i][j]);
	}
	vector<int> ans;
	for (int i = 1; i <= n; i++){
		if (check(i))
			ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
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