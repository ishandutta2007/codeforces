#include <bits/stdc++.h>
#define maxn 1000005 
#define maxm 500086
#define eps 1e-8
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const double pi = acos(-1);

using namespace std;
inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int t, n, len;
int mn[1005], mx[1005];
int MN[1005], MX[1005];
void build(int tot, int l, int r){
	if(l == r){
		MN[tot] = mn[l], MX[tot] = mx[l];
		return ;
	}
	int mid = l + r >> 1;
	build(tot << 1, l, mid), build(tot << 1 | 1, mid + 1, r);
	printf("? %d %d\n", MN[tot << 1], MN[tot << 1 | 1]);
	fflush(stdout);
	char s[2];
	scanf("%s" ,s);
	if(s[0] == '>') MN[tot] = MN[tot << 1 | 1];
	if(s[0] == '<') MN[tot] = MN[tot << 1];
	if(s[0] == '=') MN[tot] = MN[tot << 1];
	printf("? %d %d\n", MX[tot << 1], MX[tot << 1 | 1]);
	fflush(stdout);
	scanf("%s" ,s);
	if(s[0] == '>') MX[tot] = MX[tot << 1];
	if(s[0] == '<') MX[tot] = MX[tot << 1 | 1];
	if(s[0] == '=') MX[tot] = MX[tot << 1 | 1];
	
}
int main(){
	int i, j;
	t = read();
	while(t--){
		n = read();
		len = 0;
		for(i = 1;i <= n / 2;i ++){
			printf("? %d %d\n", 2 * i - 1, 2 * i);
			fflush(stdout);
			char s[2];
			scanf("%s" ,s);
			if(s[0] == '>') mx[i] = 2 * i - 1, mn[i] = 2 * i;
			if(s[0] == '<') mx[i] = 2 * i, mn[i] = 2 * i - 1;
			if(s[0] == '=') mx[i] = mn[i] = 2 * i;
		}
		len = n / 2;
		if(n & 1) mn[n / 2 + 1] = mx[n / 2 + 1] = n, len ++;
		build(1, 1, len);
		printf("! %d %d\n",MN[1], MX[1]);
		fflush(stdout);
	}
}