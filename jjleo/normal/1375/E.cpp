#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
pair<int, int> A[maxn]; 
int a[maxn], p[maxn];
vector<pair<int, int> > ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &A[i].first), A[i].second = i;
	sort(A + 1, A + 1 + n);
	for(int i = 1;i <= n;i++) a[A[i].second] = i;
	for(int i = 1;i <= n;i++) p[a[i]] = i;
	for(int i = n;i;i--){
		for(int j = a[i] + 1;j <= n;j++) if(p[j] < i) ans.push_back({p[j], i});
	}
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);
	//while(!ans.empty()) printf("%d %d\n", ans.back().first, ans.back().second), swap(a[ans.back().first], a[ans.back().second]), ans.pop_back();
	//for(int i = 1;i <= n;i++) printf("%d ", a[i]);
}