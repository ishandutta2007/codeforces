#include<bits/stdc++.h>
#define int long long
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	bool f = 0;
	char c = getchar();
	while(c != EOF && !isdigit(c)){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	while(c != EOF && isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

const int myMod = 1e9 + 9 , seed = 19491001;
int N , M , jiou[251][251] , manacher[511];
long long cnt[251][251] , num[511] , base[27];
char st[251][251];
bool vis[511];

long long Hash(int line , int start , int end){
	int t = jiou[line][end] ^ jiou[line][start - 1];
	if(t && t != (t & -t))
		vis[(line << 1) - 1] = 0;
	return cnt[line][end] - cnt[line][start - 1];
}

signed main(){
	N = read();
	M = read();
	base[0] = 1;
	for(int i = 1 ; i < 26 ; ++i)
		base[i] = base[i - 1] * seed % myMod;
	for(int i = 1 ; i <= N ; i++){
		scanf("%s" , st[i] + 1);
		for(int j = 1 ; j <= M ; j++){
			jiou[i][j] = jiou[i][j - 1] ^ (1 << st[i][j] - 'a');
			cnt[i][j] = cnt[i][j - 1] + base[st[i][j] - 'a'];
		}
	}
	long long ans = 0;
	for(int i = 1 ; i <= M ; i++){
		for(int j = i ; j <= M ; j++){
			memset(vis , 1 , sizeof(vis));
			memset(manacher , 0 , sizeof(manacher));
			for(int k = 1 ; k <= N ; k++)
				num[(k << 1) - 1] = Hash(k , i , j);
			int maxI = 0 , maxD = 0;
			for(int k = 1 ; k <= (N << 1) - 1 ; k++){
				if(maxD > k)
					manacher[k] = min(manacher[maxI * 2 - k] , maxD - k);
				while(k - manacher[k] >= 0 && k + manacher[k] <= (N << 1) && num[k - manacher[k]] == num[k + manacher[k]] && vis[k - manacher[k]] && vis[k + manacher[k]])
					manacher[k]++;
				ans += manacher[k] >> 1;
				if(maxD < manacher[k] + k){
					maxD = manacher[k] + k;
					maxI = k;
				}
			}
		}
	}
	cout << ans;
	return 0;
}