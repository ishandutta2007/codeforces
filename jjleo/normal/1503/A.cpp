#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
char s[maxn], a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int sum = 0;
		for(int i = 1;i <= n;i++) sum += s[i] == '0';
		if(sum & 1){
			puts("NO");
			continue;
		}
		int x = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '0'){
				if(!x){
					x = i;
					continue;
				}
				s[x] = 0, s[i] = 1;
				x = 0;
			}
		}
		int cnt = (n - sum) / 2;
		for(int i = 1;i <= n;i++){
			if(s[i] == 0) a[i] = '(';
			else if(s[i] == 1) a[i] = ')';
			else{
				if(cnt) a[i] = '(', cnt--;
				else a[i] = ')';
			}
		}
		cnt = (n - sum) / 2;
		for(int i = 1;i <= n;i++){
			if(s[i] == 1) b[i] = '(';
			else if(s[i] == 0) b[i] = ')';
			else{
				if(cnt) b[i] = '(', cnt--;
				else b[i] = ')';
			}
		}
		bool tag = false;
		cnt = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == '(') cnt++;
			else if(!cnt){
				tag = true;
				break;
			}else cnt--;
		}
		if(cnt) tag = true;
		if(tag){
			puts("NO");
			continue;
		}
		cnt = 0;
		for(int i = 1;i <= n;i++){
			if(b[i] == '(') cnt++;
			else if(!cnt){
				tag = true;
				break;
			}else cnt--;
		}
		if(cnt) tag = true;
		if(tag){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i = 1;i <= n;i++) printf("%c", a[i]);puts("");
		for(int i = 1;i <= n;i++) printf("%c", b[i]);puts("");
	}
}