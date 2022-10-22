#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int MAX = 30;

struct Trie {
    int occ, val;
    Trie *t[2];
    Trie(int x) {
        occ = 0;
        val = x;
        t[0] = t[1] = nullptr;
    }
    void newOcc(int n, int k = 0, int i = MAX) { // k is 1 if new, -1 if remove
        if(i == 0) {
            occ += k;
            return;
        }
        int x = ((n & (1 << (i-1))) >> (i-1));
        if(t[x] == nullptr) t[x] = new Trie(x);
        t[x]->newOcc(n, k, i-1);
        return;
    }
    int findBest(int n, int i = MAX) {
        if(i == 0) return (occ ? val : -1);
        int x = 1 - (((n & (1 << (i-1))) >> (i-1)));
        if(t[x] == nullptr) {
            if(t[1-x] == nullptr) return -1;
            int g = t[1-x]->findBest(n, i-1);
            if(g == -1) return -1;
            return val * (1 << i) + g;
        }
        int g = t[x]->findBest(n, i-1);
        if(g == -1) {
            if(t[1-x] == nullptr) return -1;
            g = t[1-x]->findBest(n, i-1);
            if(g == -1) return -1;
            return val * (1 << i) + g;
        }
        return val * (1 << i) + g;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Trie *root = new Trie(0);
    root->newOcc(0, 1);
    int q;
    cin >> q;
    while(q--) {
        char c; int n;
        cin >> c >> n;
        if(c == '+') {
            root->newOcc(n, 1);
        }
        if(c == '-') {
            root->newOcc(n, -1);
        }
        if(c == '?') {
            cout << (n ^ root->findBest(n)) << '\n';
        }
    }
}