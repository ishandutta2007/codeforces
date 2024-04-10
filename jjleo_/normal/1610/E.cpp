#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int t, n;
int a[maxn];

int main(){
	t = read();
	while(t--){
		n = read();
		for(int i = 1;i <= n;i++) a[i] = read();
		int ans = 0;
		for(int i = 2;i <= n;i++){
			if(ans > n - i + 2) break;
			int x = a[i] - a[i - 1], cnt = 2, last = i;
			while(1){
				int pos1 = lower_bound(a + last + 1, a + n + 1, a[last] + a[last] - a[i - 1]) - a;
				if(pos1 > n) break;
				int pos2 = upper_bound(a + last + 1, a + n + 1, a[pos1]) - a - 1;
				if(a[pos1] == a[last]) cnt += pos2 - pos1 + 1;
				else cnt++;
				last = pos2;
			}
			ans = max(ans, cnt);
		}
		printf("%d\n", n - ans);
	}
}