#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t, l, r;
int x;
vector<int> v;
int sum;

void modify(int l, int r, int ll, int rr, int k){
	if(ll <= l && r <= rr){
		int x = 1;
		while(x < r - l + 1) x <<= 1;
		x = ~(x - 1);
		sum += upper_bound(v.begin(), v.end(), r ^ (k & x)) - upper_bound(v.begin(), v.end(), (l ^ (k & x)) - 1);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= ll) modify(l, mid, ll, rr, k);
	if(mid < rr) modify(mid + 1, r, ll, rr, k);
}

int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &l, &r);
		v.clear();
		for(int i = l;i <= r;i++) scanf("%d", &x), v.push_back(x), a[i] = x;
		sort(v.begin(), v.end());
		for(int i = l;i <= r;i++){
			sum = 0;
			modify(0, (1 << 17) - 1, l, r, r ^ a[i]);
			if(sum == r - l + 1){
				printf("%d\n", r ^ a[i]);
				break;
			}
		}
	}
}