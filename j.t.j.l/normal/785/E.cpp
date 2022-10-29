#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 2e6 + 10;

int eli = 12;
int nozomi;
int n, Q;

int L[MAXN], R[MAXN], a[MAXN], b[MAXN];

ll change(int x, int u, int v){
	int p = x >> eli;
	ll ret = 0;
	for(int i = 0; i <= nozomi; i++){
		if (i < p){
			int pos = lower_bound(b + L[i], b + R[i] + 1, u) - b;
			ret -= R[i] + 1 - pos;
			pos = lower_bound(b + L[i], b + R[i] + 1, v) - b;
			ret += R[i] + 1 - pos;
		}
		else if (i > p){
			int pos = upper_bound(b + L[i], b + R[i] + 1, u) - b;
			ret -= pos - L[i];
			pos = upper_bound(b + L[i], b + R[i] + 1, v) - b;
			ret += pos - L[i];
		}
		else{
			for(int i = L[p]; i <= R[p]; i++)
				if (i < x){
					ret -= a[i] > u;
					ret += a[i] > v;
				}
				else if (i > x){
					ret -= a[i] < u;
					ret += a[i] < v;
				}
		}
	}
	a[x] = v;
	int j = L[p];
	for(; b[j] != u; j++);
	b[j] = v;
	while(j > L[p] && b[j-1] > b[j]){
		swap(b[j-1], b[j]);
		j--;
	}
	while(j < R[p] && b[j+1] < b[j]){
		swap(b[j+1], b[j]);
		j++;
	}
	/*
	for(int i = L[p]; i <= R[p]; i++)
		b[i] = a[i];
	sort(b + L[p], b + R[p] + 1);*/
	return ret;
}

int main(){
	scanf("%d%d", &n, &Q);
	nozomi = n >> eli;
	for(int i = 0; i <= (n >> eli); i++)
		L[i] = n + 1, R[i] = 0;
	for(int i = 1; i <= n; i++){
		a[i] = b[i] = i;
		L[i>>eli] = min(L[i>>eli], i);
		R[i>>eli] = max(R[i>>eli], i);
	}
	ll ans = 0;
	for(int i = 1; i <= Q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int xx = a[x], yy = a[y];
		ans += change(x, xx, yy);
		ans += change(y, yy, xx);
		printf("%lld\n", ans);
	}
	return 0;
}