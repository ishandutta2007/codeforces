#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
using lint = long long;
using pi = pair<int, int>;

int n;
lint l, a[5 * MAXN], b[5 * MAXN];
int arg1[2 * MAXN], arg2[2 * MAXN];

bool trial(int x){
	int ptr1 = 0, ptr2 = 0;
	for(int i=0; i<2*n; i++){
		while(ptr1 < 4 * n && b[ptr1] <= a[i] - x - 1) ptr1++;
		while(ptr2 < 4 * n && b[ptr2] <= a[i] + x) ptr2++;
		arg1[i] = (i-1) - ptr1;
		arg2[i] = i - ptr2;
	}
	int maxv = 1e9;
	for(int i=0; i<2*n; i++){
		maxv = min(maxv, arg1[i]);
		if(maxv < arg2[i]) return false;
	}
	return true;
}

int main(){
	scanf("%d %lld",&n,&l);
	for(int i=0; i<n; i++) scanf("%lld",&a[i]);
	for(int i=0; i<n; i++) scanf("%lld",&b[i]);
	for(int i=0; i<n; i++){
		b[i + n] = b[i] - l;
		b[i + n + n] = b[i] + l;
		b[i + n + n + n] = b[i] + l + l;
		a[i + n] = a[i] + l;
	}
	sort(a, a+2*n);
	sort(b, b+4*n);
	int s = 0, e = l / 2;
	while(s != e){
		int m = (s+e)/2;
		if(trial(m)) e = m;
		else s = m+1;
	}
	cout << s << endl;
}