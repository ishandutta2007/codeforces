#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t, n;
char s[3][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s%s%s", &n, s[0] + 1, s[1] + 1, s[2] + 1);
		vector<int> v[2];
		for(int i = 0;i < 3;i++){
			int sum = 0;
			for(int j = 1;j <= n * 2;j++) sum += s[i][j] == '0';
			v[sum <= n].push_back(i);
		}
		string a, b;
		char c;
		if(v[0].size() >= 2){
			a = s[v[0][0]] + 1, b = s[v[0][1]] + 1;
			c = '0';
		}else{
			a = s[v[1][0]] + 1, b = s[v[1][1]] + 1;
			c = '1';
		}
		string ans;
		int x = 0;
		for(int i = 1;i <= n * 2;i++){
			if(a[i - 1] != c) ans += a[i - 1];
			else{
				if(x == 2 * n) ans += a[i - 1];
				else{
					while(x < 2 * n && b[x + 1 - 1] != c) x++, ans += b[x - 1];
					ans += a[i - 1];
					if(x != 2 * n) x++;	
				}
			}
		}
		while(x < 2 * n) x++, ans += b[x - 1];
		while(ans.length() < 3 * n) ans += '0';
		printf("%s\n", ans.c_str());
	}
}