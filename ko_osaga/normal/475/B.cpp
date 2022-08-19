#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, m;
char a[22], b[22];
int get(int x, int y){ return x * m + y;}
int adj[405][405];

int main(){
	cin >> n >> m >> a >> b;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<m; j++){
			if(b[j] == '^') adj[get(i+1, j)][get(i, j)] = 1;
			else adj[get(i, j)][get(i+1, j)] = 1;
		}
	}
	for(int i=0; i<m-1; i++){
		for(int j=0; j<n; j++){
			if(a[j] == '<') adj[get(j, i+1)][get(j, i)] = 1;
			else adj[get(j, i)][get(j, i+1)] = 1;
		}
	}
	for(int i=0; i<n*m; i++) adj[i][i] = 1;
	for(int i=0; i<n*m; i++){
		for(int j=0; j<n*m; j++){
			for(int k=0; k<n*m; k++){
				adj[j][k] |= (adj[j][i] & adj[i][k]);
			}
		}
	}
	for(int i=0; i<n*m; i++){
		for(int j=0; j<n*m; j++){
			if(!adj[i][j]){
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
}