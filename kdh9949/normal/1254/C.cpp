#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair<ll, int>;
#define x first
#define y second

const int N = 1005;

int n, P, Q, R;
ll a[N];
vector<pli> lv, rv;

ll area(int i, int j, int k){
	printf("1 %d %d %d\n", i, j, k);
	fflush(stdout);
	ll r;
	scanf("%lld", &r);
	return r;
}

int ccw(int i, int j, int k){
	printf("2 %d %d %d\n", i, j, k);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	return (r == 1);
}

int main(){
	scanf("%d", &n);
	P = 2;
	for(int i = 3; i <= n; i++) if(ccw(1, i, P)) P = i;
	for(int i = 2; i <= n; i++) if(i != P) a[i] = area(1, P, i);
	ll mx = *max_element(a + 2, a + n + 1);
	for(int i = 2; i <= n; i++){
		if(mx == a[i]){
			if(!Q) Q = i;
			else R = i;
		}
	}
	if(R){
		if(ccw(1, R, Q)) swap(Q, R);
	}
	for(int i = 2; i <= n; i++){
		if(i != P && i != Q && i != R){
			if(ccw(1, i, Q)) lv.emplace_back(a[i], i);
			else rv.emplace_back(a[i], i);
		}
	}
	sort(lv.begin(), lv.end());
	sort(rv.begin(), rv.end());
	reverse(rv.begin(), rv.end());
	printf("0 1 %d ", P);
	for(pli i : lv) printf("%d ", i.y);
	printf("%d ", Q);
	if(R) printf("%d ", R);
	for(pli i : rv) printf("%d ", i.y);
	puts("");
	fflush(stdout);
}