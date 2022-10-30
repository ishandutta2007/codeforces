#include<bits/stdc++.h>
using namespace std;

int fa[1003] , bp[2][1003] , b[1003] , w[1003] , N , M , W;
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

int main(){
	cin >> N >> M >> W;
	for(int i = 1 ; i <= N ; ++i) cin >> w[i];
	for(int i = 1 ; i <= N ; ++i) cin >> b[i];
	for(int i = 1 ; i <= N ; ++i) fa[i] = i;
	for(int i = 1 ; i <= M ; ++i){int a , b; cin >> a >> b; fa[find(a)] = find(b);}
	int pos = 0;
	for(int i = 1 ; i <= N ; ++i)
		if(find(i) == i){
			pos ^= 1; int w1 = 0 , b1 = 0;
			memcpy(bp[pos] , bp[pos ^ 1] , sizeof(bp[pos]));
			for(int j = 1 ; j <= N ; ++j)
				if(find(j) == i){
					w1 += w[j]; b1 += b[j];
					for(int k = w[j] ; k <= W ; ++k)
						bp[pos][k] = max(bp[pos][k] , bp[pos ^ 1][k - w[j]] + b[j]);
				}
			for(int j = w1 ; j <= W ; ++j)
				bp[pos][j] = max(bp[pos][j] , bp[pos ^ 1][j - w1] + b1);
		}
	cout << bp[pos][W];
	return 0;
}