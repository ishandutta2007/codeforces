#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <cmath>
#include <memory.h>
#include <queue>
#include <set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;
typedef long long ll;
typedef long double ld;

const ld PI = acosl(-1.);

int n, k;
const int N = 100111;
struct cell {
    int go[26];
} tree[N];
int root = 1;
int kv = 1;
char w[N];
bool canwin[N], canlose[N];

void dfs(int x) {
    bool got = false;
    for (int i = 0; i < 26; ++i)
        if (tree[x].go[i]) {
            dfs(tree[x].go[i]);
            got = true;
        }

    if (!got) {
        canwin[x] = false;
        canlose[x] = true;
        return;
    }

    for (int i = 0; i < 26; ++i)
        if (tree[x].go[i]) {
            int y = tree[x].go[i];
            if (!canwin[y]) canwin[x] = true;
            if (!canlose[y]) canlose[x] = true;
        }
}

int main() {
    scanf("%d%d\n", &n, &k);
    while (n--) {
        gets(w);
        int cur = root;
        for (int i = 0; w[i]; ++i) {
            w[i] -= 'a';
            if (!tree[cur].go[ w[i] ]) {
                tree[cur].go[ w[i] ] = ++kv;
            }
            cur = tree[cur].go[ w[i] ];
        }
    }

    dfs(root);

    bool a = canwin[root];
    bool b = canlose[root];

    if (a && b) {
        cout << "First" << endl;
        return 0;
    }
    if (!a && !b) {
        cout << "Second" << endl;
        return 0;
    }
    if (a) {
        if (k & 1) cout << "First" << endl;
        else cout << "Second" << endl;
        return 0;
    }
    cout << "Second" << endl;

    return 0;
}