#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#ifndef LOCAL
// #define cerr if(0)cout
#endif

#define st first
#define nd second

using namespace std;

int n, k;

struct node {
	int cnt;
	node * v[11];

	node() {
		cnt = 0;
		memset(v, 0, sizeof v);
	}

} * root;

void ins1(node * q, const char * s) {
	
	if(q->cnt > 0)
		q->cnt = -2;
	else if(q->cnt == 0)
		q->cnt = -1;
	
	if(s[0] == 0)
		return;

	if(!q->v[s[0] - '0'])
		q->v[s[0] - '0'] = new node();
	ins1(q->v[s[0] - '0'], s + 1);
}

void ins2(node * q, const char * s) {
	
	if(q->cnt < 0)
	q->cnt = -q->cnt;
	
	if(s[0] == 0)
		return;

	if(!q->v[s[0] - '0'])
		q->v[s[0] - '0'] = new node();
	ins2(q->v[s[0] - '0'], s + 1);
}

string s[70010];


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	root = new node();

	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		const char *ss = s[i].c_str();

		for(int j = 0; j < s[i].size(); j++)
			ins1(root, ss + j);
		for(int j = 0; j < s[i].size(); j++)
			ins2(root, ss + j);
	}

	if(n == 1) {
		cout << s[1][0] << '\n';
		return 0;
	}
	// dbg(root->v[3]->cnt);

	// dbg(root->cnt);

	for(int i = 1; i <= n; i++) {
		int ansj, ansk = 1000;
		for(int j = 0; j < s[i].size(); j++) {
			int k = 0;
			node * t = root;
			while(k + j < s[i].size() && t->cnt > 1) 
				t = t->v[s[i][j + k] - '0'], k++;
			if(t->cnt == 1) {
				if(ansk > k)
					ansk = k, ansj = j;
			}
		}
		cout << s[i].substr(ansj, ansk) << '\n';
	}
}