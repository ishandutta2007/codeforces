#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 1e9 + 7;

int n, m;
set<int> st;
int a[maxn];
int f[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), st.insert(a[i]);
	f[0] = f[1] = 1;
	for(int i = 2;i <= m;i++) f[i] = (f[i - 1] + f[i - 2]) % p;
	for(int i = 1;i <= m;i++) f[i] = (f[i] + f[i - 1]) % p;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int x = a[i];
		int last = 0;
		bool tag = false;
		st.erase(a[i]);
		while(x){
			if(!last && st.find(x) != st.end()){
				tag = true;
				break;
			}
			if(!last && !(x & 1) && (x & 2)) break;
			if(x & 1) last = 0;
			else last ^= 1;
			x >>= 1;
		}
		st.insert(a[i]);
		if(tag) continue;
		x = a[i];
		int cnt = 0;
		while(x){
			cnt++;
			x >>= 1;
		}
		if(m - cnt >= 0) ans = (ans + f[m - cnt]) % p;
	}
	printf("%d", ans);
}