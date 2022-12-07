#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
vector<int> v;
int a[maxn];

inline void rev(int i){
	reverse(a + 1, a + 1 + i);
	v.push_back(i);
}

void solve(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++) if(abs(i - a[i]) & 1){
		puts("-1");
		return;
	}
	v.clear();
	for(int i = n;i > 1;i -= 2){
		if(a[i] == i && a[i - 1] == i - 1) continue;
		for(int j = 1;j <= i;j++){
			if(a[j] == i){
				rev(j);
				break;
			}
		}
		if(a[2] != i - 1){
			for(int j = 1;j <= i;j++){
				if(a[j] == i - 1){
					rev(j - 1), rev(j + 1), rev(3);
					break;
				}
			}
		}
		rev(i);
	}
	printf("%d\n", v.size());
	for(int i = 0;i < v.size();i++) printf("%d ", v[i]);puts("");
	for(int i = 1;i <= n;i++) assert(a[i] == i);
}

int main(){
	scanf("%d", &t);
	while(t--) solve();
}

/*
1
7
1 6 3 2 7 4 5
*/