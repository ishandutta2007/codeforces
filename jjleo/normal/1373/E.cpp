#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;
int a[maxn], cnt;
string s, ss;

inline bool check(int n, int k){
	if(2 * n % k == 0){
		int x = 2 * n / k;
		if((x - k + 1) % 2 == 0 && (x - k + 1) / 2 >= 0) return true;
	}
	return false;
}

int main(){
	scanf("%d", &t);
	while(t--){
		s = "99999999999999";
		bool tag = false;
		scanf("%d%d", &n, &k);
		if(2 * n % (k + 1) == 0){
			int x = 2 * n / (k + 1);
			if((x - k) % 2 == 0 && (x - k) / 2 >= 0){
				x = (x - k) / 2;
				if(!x){
					puts("0");
					continue;
				}
				cnt = 0;
				if(x > 9 - k){
					a[++cnt] = 9 - k, x -= 9 - k;
				}
				
				while(x){
					if(x > 9) a[++cnt] = 9, x -= 9;
					else a[++cnt] = x, x -= x;
				}
				/*while(cnt) printf("%d", a[cnt--]);
				puts("");
				continue;*/
				s = "";
				while(cnt) s += a[cnt--] + '0';
				tag = true;
			}
		}
		for(int i = 1;i < n;i++){
			for(int j = 1;j < k + 1;j++){
				if(check(i, j) && check(n - i, k + 1 - j)){
					//
					int x = 2 * i / j, y = 2 * (n - i) / (k + 1 - j);
					x = (x - j + 1) / 2 + j - 1, y = (y - (k + 1 - j) + 1) / 2;
					//printf("%d %d %d--\n", x - j + 1, y, j);
					if(x < y) continue;
					//if(x < 9) continue;
					if((x - y + 1) % 9) continue;
					int z = (x - y + 1) / 9;
					cnt = 0;
					while(z--) a[++cnt] = 9, x -= 9;
					if(x < 0) continue;
					if(x > 8) a[++cnt] = 8, x -= 8;
					else if(x) a[++cnt] = x, x -= x;
					while(x){
						if(x > 9) a[++cnt] = 9, x -= 9;
						else a[++cnt] = x, x -= x;
					}
					a[1] -= j - 1;
					ss = "";
					while(cnt) ss += a[cnt--] + '0';
					
					if(ss.length() < s.length()) s = ss; 
					else if(ss.length() == s.length()) s = min(ss, s);
					tag = true;
					//printf("%d %d %d--\n", i, j, y);
					//tag = true;
					//break;
					//printf("%s %d %d--\n", ss.c_str(), s.length(), ss.length());
				} 
			}
		}
		if(!tag) puts("-1");
		else printf("%s\n", s.c_str());
	}
}