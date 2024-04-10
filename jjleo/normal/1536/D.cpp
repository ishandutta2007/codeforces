#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

vector<int> v;

int b[maxn];

inline void add(int x, int y){
	for(;x <= v.size();x += x & -x) b[x] += y;
}

inline int query(int x){
	int sum = 0;
	for(;x;x -= x & -x) sum += b[x];
	return sum;
}

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), v.push_back(a[i]);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i = 1;i <= n;i++) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
		bool tag = false;
		for(int i = n - 1;i;i--){
			if(query(a[i])){
				tag = true;
				break;
			}
			if(abs(a[i] - a[i + 1]) <= 1) continue;
			if(a[i] < a[i + 1]){
				add(a[i] + 1, 1), add(a[i + 1], - 1);
			}else{
				add(a[i + 1] + 1, 1), add(a[i], - 1);
			}
		}
		puts(tag ? "NO" : "YES");
		for(int i = 1;i <= v.size();i++) b[i] = 0;v.clear();
	}
}