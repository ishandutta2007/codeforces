#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
unordered_set<int> Y[N];
set<int> X;
vector<int> pts[N];

const int MAGIC = 505;

int A[N], B[N];
int main(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		Y[x].insert(y);
		pts[x].push_back(y);
		X.insert(x);
	}
	int cnt = 0;
	long long ans = 0;
	for(int x : X){
		sort(pts[x].begin(), pts[x].end());
		if(Y[x].size() < MAGIC){
			for(int i = 0; i < pts[x].size(); i++){
				for(int j = 0; j < i; j++){
					int y1 = pts[x][j], y2 = pts[x][i];
					int len = y2 - y1;
					if(x >= len && Y[x - len].count(y1) && Y[x - len].count(y2))
						ans++;
				}
			}
		}
		else{
			for(int i = 0; i < cnt; i++){
				int x1 = A[i], y1 = B[i];
				int len = x - x1;
				if(Y[x].count(y1) && Y[x1].count(y1 - len) && Y[x].count(y1 - len)){
					ans++;
				}
			}
		}
		for(int y : pts[x]){
			A[cnt++] = x;
			B[cnt - 1] = y;
		}

	}
	printf("%lld\n", ans);
}