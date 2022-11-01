#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
char s[maxn], t[maxn];
vector<int> v;
int sum;
int ans;
int f[2];

int main(){
	scanf("%d%s%s", &n, s + 1, t + 1);
	for(int i = 1;i <= n;i++){
		if(s[i] ^ t[i]) v.push_back(s[i] > t[i]), sum += s[i] - t[i];
	}
	if(sum) return printf("-1"), 0;
	for(int i = 0;i < v.size();i++){
		int x = v[i];
		if(!f[x ^ 1]) ans++;
		else f[x ^ 1]--;
		f[x]++;
	}
	printf("%d", ans);
}