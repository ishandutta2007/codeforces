#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
string s;
int n, q;
struct Node {
	int ama;
	int amb;
	int amc;
	int a, b, c, ab, bc, abc;
};
Node t[400007];

void update(int now, int l, int r) {
	if(l == r) {
		t[now].ama = 0;
		t[now].amb = 0;
		t[now].amc = 0;
		t[now].ab = 0;
		t[now].bc = 0;
		t[now].abc = 0;
		if(s[l] == 'a') {
			t[now].ama = 1;
		} else if(s[l] == 'b') {
			t[now].amb = 1;
		} else {
			t[now].amc = 1;
		}
		t[now].a = t[now].ama;
		t[now].b = t[now].amb;
		t[now].c = t[now].amc;
		return;
	}
	t[now].ama = t[now * 2].ama + t[now * 2 + 1].ama;
	t[now].amb = t[now * 2].amb + t[now * 2 + 1].amb;
	t[now].amc = t[now * 2].amc + t[now * 2 + 1].amc;
	t[now].a = t[now].ama;
	t[now].b = t[now].amb;
	t[now].c = t[now].amc;
	t[now].ab = min(t[now * 2].a + t[now * 2 + 1].ab, t[now * 2].ab + t[now * 2 + 1].b);
	t[now].bc = min(t[now * 2].b + t[now * 2 + 1].bc, t[now * 2].bc + t[now * 2 + 1].c);
	t[now].abc = min(t[now * 2].a + t[now * 2 + 1].abc, t[now * 2].ab + t[now * 2 + 1].bc);
	t[now].abc = min(t[now].abc, t[now * 2].abc + t[now * 2 + 1].c);
}


void build_tree(int now, int l, int r) {
	if(l == r) {
		update(now, l, r);
		return;
	}
	int mid = (l + r) / 2;
	build_tree(now * 2, l, mid);
	build_tree(now * 2 + 1, mid + 1, r);
	update(now, l, r);
}

void update1(int now, int l, int r, int pos) {
	if(l == r) {
		update(now, l, r);
		return;
	}
	int mid = (l + r) / 2;
	if(mid >= pos) {
		update1(now * 2, l, mid, pos);
	} else {
		update1(now * 2 + 1, mid + 1, r, pos);
	}
	update(now, l, r);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n >> q;
    cin >> s;
    build_tree(1, 0, n - 1);
    for(int i = 0; i < q; i++) {
    	int x;
    	char c;
    	cin >> x >> c;
    	s[x - 1] = c;
    	update1(1, 0, n - 1, x - 1);
    	cout << t[1].abc << '\n';
    }
}