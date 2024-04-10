#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TNode {
	TNode* Children[4];
	TNode* Suffix;
	int IsTerminating;
	int Depth;
	int Id;
};

int getIndex(char ch) {
	switch (ch) {
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'G':
		return 2;
	case 'T':
		return 3;
	default:
		return -1;
	}
}

TNode Joker;
TNode Nodes[10000];

int main(void) {
	Joker.Depth = -1;
	Joker.IsTerminating = 0;
	Joker.Suffix = &Joker;
	TNode Root;
	Root.Id = 0;
	int n, m;
	cin >> n >> m;
	Root.Suffix = &Joker;
	Root.Depth = 0;
	Root.IsTerminating = 0;
	fill_n(Root.Children, 4, (TNode*)NULL);
	fill_n(Joker.Children, 4, &Nodes[0]);
	Nodes[0] = Root;
	int nodeCount = 1;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		TNode* cur = &Nodes[0];
		for (int j = 0; j < (int)str.length(); j++) {
			int ch = getIndex(str[j]);
			if (cur->Children[ch] == NULL) {
				TNode &nval = Nodes[nodeCount];
				nval.Depth = j + 1;
				nval.IsTerminating = 0;
				cur->Children[ch] = &nval;
				nval.Id = nodeCount++;
				fill_n(nval.Children, 4, (TNode*)NULL);
			}
			cur = cur->Children[ch];
		}
		cur->IsTerminating = (int)str.length();
	}
	queue<TNode*> q;
	q.push(&Nodes[0]);
	while (!q.empty()) {
		TNode* cur = q.front();
		q.pop();
		cur->IsTerminating = max(cur->IsTerminating, cur->Suffix->IsTerminating);
		for (int i = 0; i < 4; i++) {
			TNode* chl = cur->Children[i];
			if (!chl) {
				cur->Children[i] = cur->Suffix->Children[i];
			} else {
				cur->Children[i]->Suffix = cur->Suffix->Children[i];
				q.push(cur->Children[i]);
			}
		}
	}
	typedef long long ll;
	const ll MOD = ll(1e9 + 9);
	vector< vector< vector<ll> > > d(n + 1, vector< vector<ll> >(nodeCount, vector<ll>(12, 0)));
	d[0][0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < nodeCount; j++) {
			for (int k = 0; k <= Nodes[j].Depth; k++) {
				d[i][j][k] %= MOD;
				if (i != n)
					for (int k2 = 0; k2 < 4; k2++) {
						int idx = (k <= Nodes[j].IsTerminating) ? 1 : (k + 1);
						d[i + 1][Nodes[j].Children[k2]->Id][idx] += d[i][j][k];
					}
			}
		}
	}
	ll res = 0;
	for (int i = 0; i < nodeCount; i++) {
		if (Nodes[i].IsTerminating) {
			for (int j = 0; j <= Nodes[i].IsTerminating; j++) {
				res += d[n][i][j];
			}
		}
	}
	cout << res % MOD;
	return 0;
}