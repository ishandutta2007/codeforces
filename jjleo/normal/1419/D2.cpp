#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn], b[maxn];
vector<int> v;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int l = 1, r = n;
	for(int i = 1;i <= n;i++){
		if(i & 1) v.push_back(a[r--]);
		else b[i] = a[l++];
	}	
	reverse(v.begin(), v.end());
	int ans = 0;
	for(int i = 0;i < v.size();i++) b[i * 2 + 1] = v[i];
	for(int i = 2;i < n;i++) ans += b[i] < b[i - 1] && b[i] < b[i + 1];
	printf("%d\n", ans);
	for(int i = 1;i <= n;i++) printf("%d ", b[i]);
}