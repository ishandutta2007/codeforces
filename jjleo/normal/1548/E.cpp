#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

struct BIT{
	int a[maxn];
	
	inline void add(int x, int y){
		for(;x < maxn;x += x & -x) a[x] += y;
	}
	
	inline int query(int x){
		x = min(x, maxn - 1), x = max(x, 0);
		int sum = 0;
		for(;x;x -= x & -x) sum += a[x];
		return sum; 
	}
}bit[2];

int n, m, x;
int a[maxn], b[maxn], A[maxn], B[maxn];
int sk[maxn], top, mx[maxn];

vector<tuple<int, int, int> > v; 

int main(){
	scanf("%d%d%d", &n, &m, &x);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= m;i++) scanf("%d", &b[i]); 
	top = 0;
	for(int i = 1;i <= n;i++){
		while(top && a[sk[top]] > a[i]) mx[top - 1] = max(mx[top - 1], mx[top]), top--;
		if(top) A[i] = mx[top];
		else A[i] = 2e5;
		sk[++top] = i, mx[top] = a[i];
	}
	top = 0; 
	for(int i = n;i;i--){
		while(top && a[sk[top]] >= a[i]) mx[top - 1] = max(mx[top - 1], mx[top]), top--;
		if(top) A[i] = min(A[i], mx[top]);
		sk[++top] = i, mx[top] = a[i];
		A[i] = max(A[i], a[i]);
	}
	top = 0;
	for(int i = 1;i <= m;i++){
		while(top && b[sk[top]] > b[i]) mx[top - 1] = max(mx[top - 1], mx[top]), top--;
		if(top) B[i] = mx[top];
		else B[i] = 2e5;
		sk[++top] = i, mx[top] = b[i];
	}
	top = 0; 
	for(int i = m;i;i--){
		while(top && b[sk[top]] >= b[i]) mx[top - 1] = max(mx[top - 1], mx[top]), top--;
		if(top) B[i] = min(B[i], mx[top]);
		sk[++top] = i, mx[top] = b[i];
		B[i] = max(B[i], b[i]);
	}
	for(int i = 1;i <= n;i++) v.push_back(make_tuple(A[i] - a[i], a[i], 0));
	for(int i = 1;i <= m;i++) v.push_back(make_tuple(B[i] - b[i], b[i], 1));
	sort(v.begin(), v.end(), greater<tuple<int, int, int> >());
	long long ans = 0;
	//for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(a[i] + b[j] <= x && a[i] + B[j] > x && A[i] + b[j] > x) printf("%d %d\n", i, j);
	for(int i = 0;i < v.size();i++){
		int val1 = get<0>(v[i]), val2 = get<1>(v[i]), id = get<2>(v[i]);
		ans += bit[id ^ 1].query(x - val2) - bit[id ^ 1].query(x - (val1 + val2));
		bit[id].add(val2, 1);
	}
	printf("%lld", ans);
}