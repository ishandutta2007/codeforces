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

int n, r[105]; 
int st[105], tp, cnt;
string ans[10005],zer;
int main(){
	int i, j;
	n = read();
	for(i = 1;i <= n;i++) r[i] = read();
	for(i = 1;i <= n;i++) zer += '0';
	while(1){
		int mx = -1, smx = -1, wei = 0;
		for(i = 1;i <= n;i++){
			if(r[i] > mx) mx = r[i], st[tp = 1] = i;
			else if(r[i] == mx) st[++tp] = i;
		}
		if(tp == n) break;
		cnt++;
		ans[cnt] = zer;
		if(tp > 1){
			if(tp & 1)
				for(i = 1;i <= 3;i++)  ans[cnt][st[i] - 1] = '1', r[st[i]] = max(r[st[i]] - 1, 0);
			else
				for(i = 1;i <= 2;i++)  ans[cnt][st[i] - 1] = '1', r[st[i]] = max(r[st[i]] - 1, 0);
		}
		else{
			for(i = 1;i <= n;i++){
				if(r[i] == mx) continue;
				if(r[i] > smx) smx = r[i], wei = i;
			}
			ans[cnt][st[1] - 1] = '1', r[st[1]] = max(r[st[1]] - 1, 0);
			ans[cnt][wei - 1] = '1';r[wei] = max(r[wei] - 1, 0);
		}
	}
	printf("%d\n",r[1]);
	printf("%d\n",cnt);
	for(i = 1;i <= cnt;i++) cout<<ans[i]<<endl;
}