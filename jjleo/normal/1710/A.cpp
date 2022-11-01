#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m, k;
int a[maxn];

bool check(){
//	if(m == 3){
//		for(int i = 1;i <= k;i++){
//			int x = a[i] / n;
//			if(x >= 3) return true;
//		}
//		return false;
//	}
	int mx = 0;
	long long sum = 0;
	for(int i = 1;i <= k;i++){
		int x = a[i] / n;
		if(x == 1) x = 0;
		sum += x;
		mx = max(mx, x);
	}
	if(mx == 2 && (m & 1)) return false;
	return sum >= m;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1;i <= k;i++) scanf("%d", &a[i]);
		bool tag = false;
		tag |= check();
		swap(n, m);
		tag |= check();
		puts(tag ? "Yes" : "No");
	}
}