#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Line{
    ll a, b;
};

double cross(Line x, Line y){ return (double)(x.b - y.b) / (y.a - x.a); }

const int MAXN = 100010;
int n, fr;
ll a[MAXN], b[MAXN], dp[MAXN];
vector<Line> st;

void ins(ll x, ll y){
	Line cur = {x, y};
    while(st.size() > 1 && cross(cur, st[st.size() - 1]) < cross(st[st.size() - 2], st[st.size() - 1])) st.pop_back();
    st.push_back(cur);
}

ll get_monotone(ll x){
	while(fr + 1 < st.size() && cross(st[fr], st[fr + 1]) <= x) fr++;
    return st[fr].a * x + st[fr].b;
}

ll get_not_monotone(ll x){
	int s = 0, e = st.size() - 1;
    while(s <= e){
		int m = (s + e) / 2;
		if(m == 0 || x > cross(st[m], st[m - 1])) s = m + 1;
		else e = m - 1;
    }
    return st[e].a * x + st[e].b;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	for(int i = 1; i <= n; i++) scanf("%lld", b + i);
	dp[1] = 0;
	ins(b[1], dp[1]);
	for(int i = 2; i <= n; i++){
		dp[i] = get_not_monotone(a[i]);
		ins(b[i], dp[i]);
	}
	printf("%lld\n", dp[n]);
}