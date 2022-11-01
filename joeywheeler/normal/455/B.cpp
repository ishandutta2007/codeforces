#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct node {
    node *nd[26];

    bool fwin, flose;

    node() {
        FO(i,0,26) nd[i] = 0;
        fwin = flose = false;
    }
} *root;

void add(char *s, node *nd) {
    if (*s != 0) {
        if (nd->nd[*s-'a'] == 0) nd->nd[*s-'a'] = new node;
        add(s+1, nd->nd[*s-'a']);
    }
}

void dp(node *nd) {
    bool leaf = true;
    FO(i,0,26) if (nd->nd[i]) dp(nd->nd[i]), leaf = false;
    if (leaf) {
        nd->fwin = false;
        nd->flose = true;
    } else {
        nd->fwin = false;
        nd->flose = false;
        FO(i,0,26) if (nd->nd[i] && !nd->nd[i]->fwin) nd->fwin = true;
        FO(i,0,26) if (nd->nd[i] && !nd->nd[i]->flose) nd->flose = true;
    }
}

char buf[100005];
int main() {
    root = new node;
    int n, k;
    scanf("%d %d", &n, &k);
    FO(i,0,n) {
        scanf(" %s ", buf);
        add(buf, root);
    }
    dp(root);
    bool w = root->fwin;
    bool l = root->flose;
    if (w && l) printf("First\n");
    else if (!w && !l) printf("Second\n");
    else if (l) printf("Second\n");
    else if (k%2) printf("First\n");
    else printf("Second\n");
}