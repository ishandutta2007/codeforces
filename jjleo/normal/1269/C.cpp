#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, k;
char s[maxn];
int a[maxn];
int b[maxn];

int main(){
	scanf("%d%d%s", &n, &k, s + 1);
	bool tag = false;
	for(int i = k + 1;i <= n;i++){
		if(i % k == 0){
			if(s[i] > s[k]){
				tag = true;
				break;
			}else if(s[i] < s[k]){
				break;
			}
		}else{
			if(s[i] > s[i % k]){
				tag = true;
				break;
			}else if(s[i] < s[i % k]){
				break;
			}
		}
	}
	if(tag){
		for(int i = k;i;i--){
			if(s[i] ^ '9'){
				s[i]++;
				for(int j = i + 1;j <= k;j++) s[j] = '0';
				break;
			}
		}
	}
	printf("%d\n", n);
	for(int i = 1;i <= n;i++){
		if(i % k == 0) printf("%c", s[k]);
		else printf("%c", s[i % k]);
	}
	/*for(int i = 1;i <= n;i++) a[i] = s[i] - '0';
	for(int i = k;i;i--){
		for(int j = 1;j)
	}
	bool tag = false;
	for(int i = 1;i <= n;i++){
		if(i <= k) b[i % k] = a[i];
		else{
			if(tag || b[i % k] >= a[i]) continue;
			int x = i % k - 1;
			if(x < 0) x = k - 1;
			bool suc = false;
			while(x != i % k){
				if(b[x] < 9){
					b[x]++, suc = true;
					break;
				}
				x--;
				if(x < 0) x = k - 1;
			}
			if(!suc) b[i % k] = a[i];
			tag = true;
		}
	}
	printf("%d\n", n);
	for(int i = 1;i <= n;i++) printf("%d", b[i % k]);*/
}