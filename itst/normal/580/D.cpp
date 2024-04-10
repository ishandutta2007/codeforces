#include<bits/stdc++.h>
#define ll long long
#define MAXN 1 << 18
using namespace std;

ll ans[MAXN][18] , ext[18][18] , pri[18] , cnt[MAXN];

int main(){
	ll N , M , K , all = 0;
	cin >> N >> M >> K;
	for(int i = 0 ; i < N ; i++)
		cin >> pri[i];
	for(int i = 0 ; i < K ; i++){
		int a , b , c;
		cin >> a >> b >> c;
		ext[a - 1][b - 1] = c;
	}
	if(M == 1){
		for(int i = 0 ; i < N ; i++)
			all = max(all , pri[i]);
		cout << all;
		return 0;
	}
	for(int i = 0 ; i < N ; i++)
		ans[1 << i][i] = pri[i];
	for(int i = 1 ; i < (1 << N) ; i++)
		if((cnt[i] = cnt[i - (i & -i)] + 1) <= M && cnt[i] > 1)
			for(int j = 0 ; j < N ; j++)
				if(i & (1 << j)){
					for(int k = 0 ; k < N ; k++)
						if(j != k && (i & (1 << k)))
							ans[i][j] = max(ans[i][j] , ans[i ^ (1 << j)][k] + ext[k][j] + pri[j]);
					if(cnt[i] == M)
						all = max(all , ans[i][j]);	
				}
	cout << all;
	return 0;
}