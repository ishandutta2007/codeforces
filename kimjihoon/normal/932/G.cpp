#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct node
{
	int len, diff, dp[2];
	node *sfl, *srl;
	map<char, node*> nt;
	node() : len(0), diff(0), dp(), sfl(nullptr), srl(nullptr), nt(map<char, node*>()) {
		dp[0] = dp[1] = 0;
	};
};

const int md = 1000000007;
int ans[1000009];
vector<node*> ert, mxsuf;
string ers;

void init()
{
	ert.push_back(new node());
	ert[0]->len = -1; ert[0]->sfl = ert[0]; ert[0]->srl = ert[0];
	ert.push_back(new node());
	ert[1]->len = 0; ert[1]->sfl = ert[0]; ert[1]->srl = ert[0];
	ers += ".";
	mxsuf.push_back(ert[1]);
	ans[0] = 1;
}

void add(char c)
{
	int pi = (int)ers.length() - 1;
	ers += c;
	node *q = mxsuf[pi];
	while (q->len != -1 && ers[pi - q->len] != c)
		q = q->sfl;
	if (q->nt.find(c) != q->nt.end()) {
		mxsuf.push_back(q->nt[c]);
		return;
	}
	node* nn = new node();
	q->nt[c] = nn;
	nn->len = q->len + 2;
	q = q->sfl;
	while (q->len != -1 && ers[pi - q->len] != c)
		q = q->sfl;
	if (nn->len == 1) nn->sfl = ert[1];
	else nn->sfl = q->nt[c];
	nn->diff = nn->len - nn->sfl->len;
	if (nn->diff != nn->sfl->diff) nn->srl = nn->sfl;
	else nn->srl = nn->sfl->srl;
	ert.push_back(nn);
	mxsuf.push_back(nn);
}

int dp(int n, node *v)
{
	v->dp[0] = v->dp[1] = 0;
	v->dp[(v->srl->len + v->diff) % 2] = ans[n - (v->srl->len + v->diff)];
	if (v->diff == v->sfl->diff) {
		v->dp[0] = (v->dp[0] + v->sfl->dp[(v->diff) % 2]) % md;
		v->dp[1] = (v->dp[1] + v->sfl->dp[(v->diff + 1) % 2]) % md;
	}
	return v->dp[0];
}

void ps(int n)
{
	ans[n] = 0;
	for (node *v = mxsuf[n]; v->len > 0; v = v->srl)
		ans[n] = (ans[n] + dp(n, v)) % md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string ts; cin >> ts;
	string s = "";
	for (int i = 0; i < (int)ts.length() / 2; i++) {
		s += ts[i];
		s += ts[(int)ts.length() - i - 1];
	}
	init();
	for (int i = 0; i < s.length(); i++) {
		add(s[i]);
		ps(i + 1);
	}
	cout << ans[(int)s.size()] << '\n';
	return 0;
}