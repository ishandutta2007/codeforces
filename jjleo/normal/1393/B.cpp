#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, q;
int a[maxn];
int x;
int cnt[maxn];
char s[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x), a[x]++;
		cnt[a[x]]++;
	}
	scanf("%d", &q);
	while(q--){
		scanf("%s%d", s, &x);
		if(s[0] == '+'){
			a[x]++;
			cnt[a[x]]++;
		}else{
			cnt[a[x]]--;
			a[x]--;
		}
		bool suc = false;
		if(cnt[8]) suc = true;
		else if(cnt[4] >= 2) suc = true;
		else if(cnt[6] == 1 && cnt[2] >= 2) suc = true;
		else if(cnt[4] == 1 && cnt[2] >= 3) suc = true;
		puts(suc ? "YES" : "NO");
	}
}