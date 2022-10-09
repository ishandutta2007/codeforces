#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

/*
3 1
abc
aec
ac
a?c

5 2
aa
aaa
aaa
aaaa
aaaaa

???
?????


*/

int redni_broj;

struct node {
	node* next[5];
	int br;
	int rb;

	node() : br(0) {
		for (int i = 0; i < 5; i++) {
			next[i] = nullptr;
		}
		rb = ++redni_broj;
	}
};

void insert(node* root, char* str) {
	for (int i = 0; str[i]; i++) {
		int x = str[i] - 'a';
		if (root->next[x]) {
			root = root->next[x];
		}
		else {
			root->next[x] = new node;
			root = root->next[x];
		}
	}
	root->br++;
}

vector<node*> nadjeni;

void match(node* root, char* patt) {
	if (!root) {
		return;
	}

	if (patt[0] == 0) {
		nadjeni.push_back(root);
		return;
	}

	if (patt[0] != '?') {
		match(root->next[patt[0] - 'a'], patt + 1);
	}
	else {
		match(root, patt + 1);
		for (int i = 0; i < 5; i++) {
			match(root->next[i], patt + 1);
		}
	}
}

int n, m, l;
char buff[105];

int main() {
	scanf("%d%d", &n, &m);
	node* root = new node;

	for (int i = 1; i <= n; i++) {
		scanf("%s", buff);
		insert(root, buff);
	}

	for (int i = 1; i <= m; i++) {
		scanf("%s", buff);
		match(root, buff);
		sort(nadjeni.begin(), nadjeni.end());
		int x = unique(nadjeni.begin(), nadjeni.end()) - nadjeni.begin();
		int y = 0;
		for (int i = 0; i < x; i++) {
			y += nadjeni[i]->br;
			// fprintf(stderr, ">%d\n", nadjeni[i]->rb);
		}
		nadjeni.clear();
		printf("%d\n", y);
	}

	
	{
		int _;
		scanf("%d", &_);
	}
	
}