#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int sigma = 4;

int getNumber(char c) {
	if (c == 'A') {
		return 0;
	} else if (c == 'C') {
		return 1;
	} else if (c == 'G') {
		return 2;
	} else {
		return 3;
	}
}

struct node {
	int link;
	int to[sigma];
	bool term;
	int compressed;
	int depth;
	node() {
		link = -1;
		term = false;
		memset(to, -1, sizeof(to));
		compressed = -1;
		depth = 0;
	}
};

vector<node> t;

void add(const string& s) {
	int v = 0;
	for (int i = 0; i < sz(s); ++i) {
		int c = getNumber(s[i]);
		if (t[v].to[c] == -1) {
			t[v].to[c] = sz(t);
			t.pb(node());
		}
		v = t[v].to[c];
	}
	t[v].term = true;
}

void build() {
	t[0].link = 0;
	for (int i = 0; i < sigma; ++i) {
		if (t[0].to[i] == -1) {
			t[0].to[i] = 0;
		}
	}
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		//cout << "!" << v << endl;
		q.pop();
		for (int c = 0; c < sigma; ++c) {
			int u = t[v].to[c];
			if (t[u].link != -1) {
				continue;
			}
			t[u].link = (v == 0 ? 0 : t[t[v].link].to[c]);
			t[u].depth = t[v].depth + 1;
			if (t[t[u].link].term) {
				t[u].compressed = t[u].link;
			} else {
				t[u].compressed = t[t[u].link].compressed;
			}
			for (int d = 0; d < sigma; ++d) {
				if (t[u].to[d] != -1) {
					continue;
				}
				t[u].to[d] = t[t[u].link].to[d];
			}
			q.push(u);
		}
	}
}

const int mod = 1e9 + 9;

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

int main()
{
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
                                               
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    t.pb(node());

    for (int i = 0; i < k; ++i) {
    	string s;
    	cin >> s;
    	add(s);
    }

    build();
    int maxNotCovered = 9;

    vector<vector<vector<int> > > dp(2, vector<vector<int> >(sz(t), vector<int>(maxNotCovered + 1)));
    dp[0][0][0] = 1;
    int ptr = 0;

    while (n--) {
    	dp[ptr ^ 1] = vector<vector<int> >(sz(t), vector<int>(maxNotCovered + 1, 0));
    	for (int v = 0; v < sz(t); ++v) {
    		for (int notCovered = 0; notCovered <= maxNotCovered; ++notCovered) {
    			for (int c = 0; c < sigma; ++c) {
    				int nc = notCovered + 1;
    				int len = 0;
    				int to = t[v].to[c];
    				if (t[to].term) {
    					len = t[to].depth;
    				} else if (t[to].compressed != -1) {
    					len = t[t[to].compressed].depth;
    				}
    				if (len >= nc) {
    					nc = 0;
    				}
    				if (nc > maxNotCovered) {
    					continue;
    				}
    				add(dp[ptr ^ 1][to][nc], dp[ptr][v][notCovered]);
    			}
    		}
    	}
    	ptr ^= 1;
    }

    int ans = 0;
    for (int v = 0; v < sz(t); ++v) {
    	add(ans, dp[ptr][v][0]);
    }
    cout << ans << "\n";

}