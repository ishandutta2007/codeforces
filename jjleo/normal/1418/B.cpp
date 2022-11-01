#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];
vector<int> b, c;
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		b.clear(), c.clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			if(!x) b.push_back(i), c.push_back(a[i]);
		}
		sort(c.begin(), c.end(), greater<int>());
		for(int i = 0;i < b.size();i++) a[b[i]] = c[i];
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);
		puts("");
	}
}