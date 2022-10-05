#include <bits/stdc++.h>
using namespace std;

int n, a[100010], c[100010], num[100010], cnt;
set<int> ss;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", a + i);
		ss.insert(a[i]);
		if(a[i] == i){ c[i] = ++cnt; }
	}
	if(cnt != ss.size()){
		puts("-1");
		return 0;
	}
    for(int i = 1; i <= n; i++) if(c[i]) num[a[i]] = c[i];
    printf("%d\n", cnt);
    for(int i = 1; i <= n; i++) printf("%d ", num[a[i]]); puts("");
    for(auto &i : ss) printf("%d ", i); puts("");
}