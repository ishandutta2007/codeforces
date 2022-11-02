#include<bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, a[N], inv[N];
vector<pair<int,int> > ans;

void sw (int A, int B) {
	ans.push_back({A, B});
	swap(inv[a[A]], inv[a[B]]);
	swap(a[A], a[B]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		inv[a[i]] = i;
	}
	for(int i=1;i<=n;i++) {
		if(inv[i] == i) continue;
		if(i > n/2) {
			if(inv[i] > n/2) {
				int A = i, B = inv[i];
				sw(1, B);
				sw(1, A);
				sw(1, B);
			}
			else if(i == n || inv[i] == 1) {
				sw(i, inv[i]);
			}
			else {
				int A = i, B = inv[i];
				sw(1, A);
				sw(B, n);
				sw(1, n);
				sw(1, A);
				sw(B, n);
			}
		}
		else {
			if(inv[i] <= n/2) {
				int A = inv[i], B = i;
				sw(n, B);
				sw(n, A);
				sw(n, B);
			}
			else if(i == 1 || inv[i] == n) {
				sw(i, inv[i]);
			}
			else {
				int A = inv[i], B = i;
				sw(1, A);
				sw(B, n);
				sw(1, n);
				sw(1, A);
				sw(B, n);
			}
		}
	}
	printf("%d\n", ans.size());
	for(auto &T : ans){
		printf("%d %d\n", T.first, T.second);
	}
}