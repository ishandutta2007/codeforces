#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m, q, x;
string s[maxn], t[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++) cin >> s[i];
	for(int i = 0;i < m;i++) cin >> t[i];
	scanf("%d", &q);
	while(q--){
		scanf("%d", &x), x--;
		printf("%s\n", (s[x % n] + t[x % m]).c_str());
	}
}