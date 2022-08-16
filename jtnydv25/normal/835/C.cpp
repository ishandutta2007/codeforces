#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
const int N = 1e5 + 10, M = 105;
int X[N], Y[N], s[N];
int pref[11][M][M];
int A[M][M], B[M][M];
int main(){
    int t = 1, n, q, c;
    sd(n); sd(q); sd(c);
    for(int i = 1; i <= n; i++){ sd(X[i]); sd(Y[i]); sd(s[i]);}
    for(int t = 0; t <= c; t++){
    	memset(A, 0, sizeof A);
    	for(int i = 1; i <= n; i++)
    		A[X[i]][Y[i]] += (s[i] + t) % (c + 1);
    	for(int i = 1; i < M; i++){
    		for(int j = 1; j < M; j++){
    			B[i][j] = B[i][j - 1] + A[i][j];
    			pref[t][i][j] = pref[t][i - 1][j] + B[i][j];
    		}
    	}
    }
    while(q--){
    	int x1, y1, x2, y2;
    	sd(t); sd(x1); sd(y1); sd(x2); sd(y2);
    	int ind = t % (c + 1);
    	int ans = pref[ind][x2][y2] - pref[ind][x2][y1 - 1] - pref[ind][x1 - 1][y2] + pref[ind][x1 - 1][y1 - 1];
    	printf("%d\n", ans);
    }
}