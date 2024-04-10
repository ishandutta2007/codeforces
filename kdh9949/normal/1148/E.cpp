#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair<ll, int>;
#define x first
#define y second

const int N = 300005;

int n;
pli a[N];
ll b[N], d[N], ds[N];
stack<int> st;
vector<int> va, vb;
vector<ll> vc;

void put(int x, int y, ll z){
	d[x] -= z;
	d[y] += z;
	va.push_back(a[x].y); vb.push_back(a[y].y);
	vc.push_back(z);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i].x);
		a[i].y = i;
	}
	for(int i = 1; i <= n; i++) scanf("%lld", b + i);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i++){
		d[i] = b[i] - a[i].x;
		ds[i] = d[i] + ds[i - 1];
		if(ds[i] < 0){ puts("NO"); return 0; }
		if(i == n && ds[i]){ puts("NO"); return 0; }
	}
	for(int i = 1; i <= n; i++){
		if(d[i] > 0) st.push(i);
		else{
			while(d[i] < 0){
				put(st.top(), i, min(d[st.top()], -d[i]));
				if(!d[st.top()]) st.pop();
			}
		}
	}
	puts("YES");
	printf("%d\n", va.size());
	for(int i = 0; i < va.size(); i++) printf("%d %d %lld\n", va[i], vb[i], vc[i]);
}