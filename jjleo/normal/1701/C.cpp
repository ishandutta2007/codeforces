#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, m;
int a[maxn], b[maxn];

bool check(int mid){
	for(int i = 1;i <= n;i++) b[i] = 0;
	int sum = 0;
	for(int i = 1;i <= m;i++){
		if(b[a[i]] < mid) b[a[i]]++;
		else sum += 2;
	}
	long long val = 0;
	for(int i = 1;i <= n;i++) val += (mid - b[i]) / 2 * 2;
	return val >= sum;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++) scanf("%d", &a[i]);
		int l = 1, r = m, mid;
		while(l < r){
			mid = l + r >> 1;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
}