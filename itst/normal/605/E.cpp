#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define ld long double
int N; ld dist[1003] , sum[1003] , p[1003][1003] , lft[1003]; bool vis[1003];

int main(){
	N = read(); for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= N ; ++j){p[i][j] = read(); p[i][j] /= 100;}
	for(int i = 1 ; i < N ; ++i){lft[i] = 1; dist[i] = 1e60;}
	while(1){
		int id = 1; for(int i = 2 ; i <= N ; ++i) if(dist[i] < dist[id] && !vis[i]) id = i;
		if(id == 1) break;
		vis[id] = 1;
		for(int j = 1 ; j <= N ; ++j)
			if(!vis[j] && p[j][id] > 1e-10){
				sum[j] += lft[j] * p[j][id] * dist[id]; lft[j] *= (1 - p[j][id]);
				dist[j] = (sum[j] + 1) / (1 - lft[j]);
			}
	}
	cout << fixed << setprecision(10) << dist[1]; return 0;
}