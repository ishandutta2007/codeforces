#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
struct Node {
	int minx = 0;
	int maxx = 0;
	int miny = 0;
	int maxy = 0;
	int x = 0;
	int y = 0;
};

Node go(Node a, char c) {
	if(c == 'W') {
		++a.x;
	} else if(c == 'S') {
		--a.x;
	} else if(c == 'D') {
		++a.y;
	} else {
		--a.y;
	}
	a.minx = min(a.minx, a.x);
	a.maxx = max(a.maxx, a.x); 
	a.miny = min(a.miny, a.y);
	a.maxy = max(a.maxy, a.y);
	return a;
}
ll get_ans(Node a) {
	int h = a.maxx - a.minx + 1;
	int w = a.maxy - a.miny + 1;
	return (ll)h * w;
}
char inversed(char c) {
	if(c == 'W') {
		return 'S';
	}
	if(c == 'S') {
		return 'W';
	}
	if(c == 'A') {
		return 'D';
	}
	return 'A';
}
ll get_ans(Node a, Node b) {
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	b.x += dx;
	b.y += dy;
	b.minx += dx;
	b.maxx += dx;
	b.miny += dy;
	b.maxy += dy;
	int h = max(a.maxx, b.maxx) - min(a.minx, b.minx) + 1;
	int w = max(a.maxy, b.maxy) - min(a.miny, b.miny) + 1;
	return (ll)h * w;
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
    int t;
    cin >> t;
    while(t--) {
    	string s1;
    	cin >> s1;
    	int n = s1.size();
    	vector<Node> p(n), s(n);
    	Node now;
    	for(int i = 0; i < n; i++) {
    		now = go(now, s1[i]);
    		p[i] = now;
    	}
    	ll ans = get_ans(now);
    	Node now1;
    	for(int i = n - 1; i >= 0; i--) {
    		now1 = go(now1, inversed(s1[i]));
    		s[i] = now1;
    	}
    	vector<char> v = {'W', 'S', 'A', 'D'};
    	for(int i = 0; i < n - 1; i++) {
    		for(auto& c : v) {
    			ans = min(ans, get_ans(go(p[i], c), s[i + 1]));
    		}
    	}
    	cout << ans << '\n';
    }
}