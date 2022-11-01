#include <bits/stdc++.h>
#define maxn 300

using namespace std;

int n, m, T;
char s[maxn];
int a[maxn], b[maxn];
char t[maxn];

inline bool cmp(int x, int y){
	return a[x] < a[y];
}

queue<char> q;

int main(){
	scanf("%d", &T);
	while(T--){
		memset(t, 0, sizeof(t)), memset(b, 0, sizeof(b));
		scanf("%s%d", s + 1, &m);
		for(int i = 1;i <= m;i++) scanf("%d", &a[i]);
		n = strlen(s + 1);
		for(int i = 1;i <= n;i++) b[s[i]]++;
		for(int i = 'z';i >= 'a';i--){
			int sum = 0;
			for(int j = 1;j <= m;j++) sum += a[j] == 0 && !t[j];
			//printf("%c %d %d--\n", i, sum, b[i]);
			if(sum <= b[i]){
				for(int j = 1;j <= m;j++){
					if(a[j] == 0 && !t[j]) t[j] = i;
				}
				for(int j = 1;j <= m;j++){
					if(t[j] == i){
						for(int k = 1;k <= m;k++){
							if(!t[k]) a[k] -= abs(k - j);
						}
					}
				}
			}
		}
		
		
		
		/*sort(s + 1, s + 1 + n);
		reverse(s + 1, s + 1 + n);
		for(int i = 1;i <= m;i++){
			scanf("%d", &a[i]), b[i] = i;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(t[j]) continue;
				int sum = 0;
				for(int k = 1;k <= m;k++){
					if(t[k] > s[i]) sum += abs(k - j);
				}
				if(sum == a[j]){
					t[j] = s[i];
					break;
				}
			}
		}*/
		/*sort(b + 1, b + 1 + m, cmp);
		for(int i = 1;i <= m;i++) q.push(b[i]); 
		int cnt = 0;
		while(!q.empty()){
			int x = q.front();q.pop();
			
			int sum = 0;
			for(int j = 1;j <= m;j++){
				if(t[j] && t[j] > s[cnt + 1]) sum += abs(j - x);
			}printf("%d %d--\n", sum, a[x]);
			if(sum ^ a[x]){
				q.push(x);
			}else{
				t[x] = s[++cnt];
			}
		}*/
		for(int i = 1;i <= m;i++) printf("%c", t[i]);puts("");
	}
}