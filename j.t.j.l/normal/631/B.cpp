#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 10;

PII R[MAXN], C[MAXN];

int main(){
	int n, m, K;
	cin>>n>>m>>K;
	for(int i = 1; i <= n; i++)
		R[i] = PII(0, 0);
	for(int j = 1; j <= m; j++)
		C[j] = PII(0, 0);
	for(int i = 1; i <= K; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y , &z);
	//	cout<<x<<' '<<y<<' '<<z<<endl;
		if (x == 1){
			R[y] = PII(i, z);
		}
		else
			C[y] = PII(i, z);
	}
//	for(int i = 1; i <= n; i++){
//		cout<<R[i].first<<' '<<R[i].second<<endl;
//	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			printf("%d%c", ((R[i].first > C[j].first) ? R[i].second : C[j].second), " \n"[j == m]);
	}
	return 0;
}