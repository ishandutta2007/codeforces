#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

int a[100][100];

void read(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	}
}

int solve(){
			int flag = 1;
			for(int i = 1; i <= n; i++){
				int cnt = 0;
				for(int l = 1; l <= m; l++)
					cnt += a[i][l] != l;
				if (cnt > 2){
					flag = 0;
					break;
				}
			}
			if (flag){
				return 1;
			}
	
	for(int j = 1; j <= m; j++)
		for(int k = j + 1; k <= m; k++){
			int flag = 1;
			for(int i = 1; i <= n; i++){
				swap(a[i][j], a[i][k]);
			}	
			for(int i = 1; i <= n; i++){
				int cnt = 0;
				for(int l = 1; l <= m; l++)
					cnt += a[i][l] != l;
				if (cnt > 2){
					flag = 0;
					break;
				}
			}
			if (flag){
				return 1;
			}
			for(int i = 1; i <= n; i++)
				swap(a[i][j], a[i][k]);
		}
	return 0;
}

void printans(int flag){
	puts(flag ? "YES" : "NO");
}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		printans(solve());
	}
	return 0;
}