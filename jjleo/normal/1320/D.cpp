#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;
const int b = 233;

int n, q;
char s[maxn];

int h[2][maxn], sum[maxn], zero[maxn];

inline int Hash(int l, int r){
	return (h[l & 1][r] - 1ll * h[l & 1][l - 1] * sum[zero[r] - zero[l - 1]] % p + p) % p;
}

int x, y, len;

int main(){
	scanf("%d%s", &n, s + 1);
	sum[0] = 1;
	for(int i = 1;i <= n;i++){
		sum[i] = 1ll * sum[i - 1] * b % p, zero[i] = zero[i - 1];
		if(s[i] == '0'){
			++zero[i];
			//debug: 10 0 
			h[0][i] = (1ll * h[0][i - 1] * b + 1 + (i & 1 ^ 1)) % p, h[1][i] = (1ll * h[1][i - 1] * b + 1 + (i & 1)) % p;
		}else{
			h[0][i] = h[0][i - 1], h[1][i] = h[1][i - 1];
		}
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d%d%d", &x, &y, &len);
		printf(Hash(x, x + len - 1) == Hash(y, y + len - 1) ? "Yes" : "No");puts("");
	}
	
}