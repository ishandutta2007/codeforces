#include<bits/stdc++.h>
using namespace std;

int ans , N , A[200003] , cnt[103] , pre[400003];

signed main(){
	ios::sync_with_stdio(0); cin >> N;
	for(int i = 1 ; i <= N ; ++i){cin >> A[i]; ++cnt[A[i]];}
	int mx = 0; for(int i = 1 ; i <= 100 ; ++i) if(cnt[mx] < cnt[i]) mx = i;
	for(int i = 1 ; i <= 100 ; ++i)
		if(i != mx){
			memset(pre , -1 , sizeof(pre)); pre[N] = 0; int sum = N;
			for(int j = 1 ; j <= N ; ++j){
				sum += (A[j] == mx ? 1 : (A[j] == i ? -1 : 0));
				if(pre[sum] != -1) ans = max(ans , j - pre[sum]);
				else pre[sum] = j;
			}
		}
	cout << ans; return 0;
}