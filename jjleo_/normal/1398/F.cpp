#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
char s[maxn];
int l[maxn], r[maxn];
int a[maxn], id[maxn], cnt;

int main(){
	scanf("%d%s", &n, s + 1);
	memset(l, -1, sizeof(l)), memset(r, -1, sizeof(r));
	int x = -1;
	for(int i = 1;i <= n;i++){
		if(s[i] != '?') x = s[i] - '0';
		l[i] = x;
	}
	x = -1;
	for(int i = n;i;i--){
		if(s[i] != '?') x = s[i] - '0';
		r[i] = x;
	}
	for(int i = 1;i <= n;i++){
		if(s[i] != '?') continue;
		if(l[i] == -1 && r[i] == -1) s[i] = '1';
		else if(l[i] == -1) s[i] = r[i] + '0';
		else if(r[i] == -1) s[i] = l[i] + '0';
		else if(l[i] == r[i]) s[i] = l[i] + '0';
	}
	for(int i = 1;i <= n;i++){
		if(s[i] != s[i - 1]) a[i] = i, id[i] = ++cnt;
		else a[i] = a[i - 1], id[i] = id[i - 1];
	}
	for(int i = 1;i <= n;i++){
		int ans = 0;
		for(int j = i;j <= n;j += i){
			if(id[j] == id[j - i + 1]){
				ans++;
			}else if(s[j] == '?'){
				if((id[j] - id[j - i + 1] == 2 && s[j - i + 1] == '?') || id[j] - id[j - i + 1] == 1) ans++;
				else if(a[a[j] - 1] - 1 && s[a[a[j] - 1] - 1] == '?') j = a[a[a[j] - 1] - 1] - 1;
				else j = a[a[j] - 1] - 1;
			}else{
				if(id[j] - id[j - i + 1] <= 1 && s[j - i + 1] == '?') ans++;
				else if(s[a[j] - 1] == '?') j = a[a[j] - 1] - 1;
				else j = a[j] - 1;
			}
		}
		printf("%d ", ans);
	}
}