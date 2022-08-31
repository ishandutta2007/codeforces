#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 1000005;

int n, k;
char str[MAXN];
int sb[MAXN], sw[MAXN];
lint dl[MAXN], dr[MAXN]; 
lint sl[MAXN], sr[MAXN];

int main(){
	scanf("%d %d",&n,&k);
	scanf("%s", str + 1);
	for(int i=1; i<=n; i++){
		sb[i] = sb[i-1] + (str[i] == 'B');
		sw[i] = sw[i-1] + (str[i] == 'W');
	}
	dl[0] = 1;
	sl[0] = 1;
	int lst = 0;
	for(int i=1; i<=n; i++){
		lst = max(lst, i - k);
		dl[i] = sl[i-1] - (lst ? sl[lst - 1] : 0) + mod;
		dl[i] %= mod;
		if(str[i] == 'B') dl[i] = 0;
		if(str[i] == 'W') lst = i;
		dl[i] %= mod;
		sl[i] = (sl[i-1] + dl[i]) % mod;
	}
	dr[n+1] = 1;
	sr[n+1] = 1;
	lst = n+1;
	for(int i=n; i>=1; i--){
		lst = min(lst, i + k);
		dr[i] = sr[i+1] - sr[lst + 1] + mod;
		dr[i] %= mod;
		if(str[i] == 'W') dr[i] = 0;
		if(str[i] == 'B') lst = i;
		sr[i] = (sr[i+1] + dr[i]) % mod;
	}
	lint csum = 0, ret = 0;
	for(int i=k; i<=n-k; i++){
		if(str[i] == 'X') csum = (csum * 2) % mod;
		if(sw[i] == sw[i-k]){
			csum += dl[i-k];
			csum %= mod;
		}
		if(sb[i] == sb[i+k]) ret += csum * dr[i+k+1] % mod;
	}
	ret %= mod;
	cout << ret;
}