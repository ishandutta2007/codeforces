#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)1e5 + 4;
int T, N, M;
int A[NS], chk[NS];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i <= N; ++i){
			A[i] = 0; chk[i] = 0;
		}
		cin >> M;
		for(int i = 1; i <= M; ++i){
			int a, b; cin >> a >> b;
			A[a] = b;
		}
		int ans = 0;
		for(int i = 1; i <= N; ++i){
			if(A[i] != i && A[i] && !chk[i]){
				chk[i] = 1;
				int cnt = 1, j = A[i];
				while(true){
					if(j == i){
						++cnt;
						break;
					}
					else if(!A[j] || chk[j]){
						chk[j] = 1;
						break;
					}
					else{
						chk[j] = 1;
						++cnt;
						j = A[j];
					}
				}
				ans += cnt;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}