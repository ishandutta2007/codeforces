#include<bits/stdc++.h>
using namespace std;
#define M 100
#define C 10000
typedef pair < int , int > ii;
ii f[M + 5][C + 5];
int a[M + 5] , b[M + 5] , n , sa;
bool better(ii X,ii Y){
	if(X.first == Y.first) return X.second > Y.second;
	return X.first < Y.first;	
}
main(){
	//freopen("test.inp","r",stdin);
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++)	scanf("%d",&a[i]) , sa += a[i];
	for(int i = 1 ; i <= n ; i++)	scanf("%d",&b[i]);
	for(int i = 0 ; i <= n ; i++)	
		for(int j = 0 ; j <= C ; j++)	f[i][j] = ii(1e9 , -1e9);
	f[0][0] = ii(0 , 0);
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j <= C ; j++){
			if(f[i][j].first > i || f[i][j].second < 0)	continue;
			if(better(f[i][j] , f[i + 1][j]))	f[i + 1][j] = f[i][j];
			if(better(ii(f[i][j].first + 1 , f[i][j].second + a[i + 1]), f[i + 1][j + b[i + 1]])) f[i + 1][j + b[i + 1]] = ii(f[i][j].first + 1 , f[i][j].second + a[i + 1]);
		}
	ii ans = ii(1e9 , -1e9);
	for(int i = 0 ; i <= C ; i++)
		if(i >= sa && better(f[n][i] , ans)) ans = f[n][i];
	printf("%d %d",ans.first,sa - ans.second);
}