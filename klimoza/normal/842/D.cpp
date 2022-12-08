#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;


struct Node {
	Node* alph[2];
	bool isEnd;
	int XOR;
	int sz;
	Node() {
		sz = 0;
		XOR = 0;
		alph[0] = alph[1] = NULL;
		isEnd = false;
	}
};

Node* add(Node* root, string& st, int ind) {
	//cout << st << " " << ind << endl;
	root->sz++;
	if (ind == -1) {	
		return root;
	}
	if (root->alph[st[st.size() - ind - 1] - '0'] != NULL) {
		root->alph[st[st.size() - ind - 1] - '0'] = add(root->alph[st[st.size() - ind - 1] - '0'], st, ind - 1);
		return root;
	}
	root->alph[st[st.size() - 1 - ind] - '0'] = add(new Node(), st, ind - 1);
	return root;
}

string kex(Node* root, int ind, string c) {
	if (root->isEnd) return c;
	//cout << root->sz << " " << root->XOR << " " << root->alph[0]->sz << " " << ind << endl;
	if ((root->XOR) & (1 << ind)) swap(root->alph[0], root->alph[1]);
	root->alph[0]->XOR ^= root->XOR;
	root->alph[1]->XOR ^= root->XOR;
	root->XOR = 0;
	if (root->alph[0]->sz < (1 << ind)) return c + kex(root->alph[0], ind - 1, "0");
	return c + kex(root->alph[1], ind - 1, "1");
}

Node* build_trie(Node* root, int ind) {
	if (ind == -1) {
		root->isEnd = true;
		return root;
	}
	root->alph[0] = build_trie(new Node(), ind - 1);
	root->alph[1] = build_trie(new Node(), ind - 1);
	return root;
}

string toStr(int k) {
	int cur_p = (1 << 19);
	string ans = "";
	while (cur_p != 0) {
		if (k >= cur_p) {
			ans += "1";
			k -= cur_p;
		}
		else {
			ans += "0";
		}
		cur_p /= 2;
	}
	return ans;
}

int toInt(string k) {
	int cur_p = (1 << 19);
	int ans = 0;
	for (char c : k) {
		if (c == '1') ans += cur_p;
		cur_p /= 2;
	}
	return ans;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	//cout << "one\n";
	string st;
	Node* root = build_trie(new Node(), 19);
	//cout << "two\n";
	int n, m;
	cin >> n >> m;
	int t;
	set<int> check;
	while (n--) {
		cin >> t;
		st = toStr(t);
		//cout << st << endl;
		if (check.find(t) == check.end()) {
			root = add(root, st, 19);
			check.insert(t);
		}
	}
	while (m--) {
		cin >> t;
		root->XOR ^= t;
		cout << toInt(kex(root, 19, "")) << endl;
	}
	//cout << cnt << endl;
	return 0;
}