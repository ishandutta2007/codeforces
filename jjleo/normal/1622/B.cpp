#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];
char s[maxn];
int b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		scanf("%s", s + 1);
		vector<pair<int, int> > v, w;
		for(int i = 1;i <= n;i++){
			if(s[i] == '0') v.push_back({a[i], i});
			else w.push_back({a[i], i});
		}
		sort(v.begin(), v.end());
		for(int i = 0;i < v.size();i++) b[v[i].second] = i + 1;
		sort(w.begin(), w.end());
		for(int i = 0;i < w.size();i++) b[w[i].second] = v.size() + i + 1;
		for(int i = 1;i <= n;i++) printf("%d ", b[i]);puts("");
	}
}