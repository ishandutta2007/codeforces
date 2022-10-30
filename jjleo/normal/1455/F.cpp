#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int t;
int n, k;
char s[maxn];
int a[maxn];
string f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%s", &n, &k, s + 1);
		for(int i = 1;i <= n;i++) a[i] = s[i] - 'a';
		for(int i = 1;i <= n;i++) f[i] = 'a' + k;
		for(int i = 0;i < n;i++){
			f[i + 1] = min(f[i + 1], f[i] + (char)(min(a[i + 1], min((a[i + 1] + 1) % k, (a[i + 1] + k - 1) % k)) + 'a'));
			if(i) f[i + 1] = min(f[i + 1], f[i].substr(0, i - 1) + (char)(a[i + 1] + 'a') + f[i].back());
			if(i + 2 <= n){
				f[i + 2] = min(f[i + 2], f[i] + (char)(min(a[i + 2], min((a[i + 2] + 1) % k, (a[i + 2] + k - 1) % k)) + 'a') + (char)(a[i + 1] + 'a'));
				if(i) f[i + 2] = min(f[i + 2], f[i].substr(0, i - 1) + (char)(a[i + 2] + 'a') + f[i].back() + (char)(a[i + 1] + 'a'));
			}
		}
		printf("%s\n", f[n].c_str());
	}
}