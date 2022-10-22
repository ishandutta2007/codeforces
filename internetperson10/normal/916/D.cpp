#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int MAX = 29;

struct Trie;
struct TrieString;
Trie* trieRoot[100001];
TrieString* trieStringRoot[100001];

struct TrieString {
    int prio = 0;
    TrieString* child[26];
    TrieString(int i) {
        prio = i;
        for(int j = 0; j < 26; j++) child[j] = nullptr;
    }
    TrieString* newOcc(string s, int k, int i = 0) {
//        cout << s << ' ' << k << ' ' << i << '\n';
        int x = -1;
        TrieString* TS;
        if(i == s.size()) TS = new TrieString(k);
        else {
            x = (s.at(i) - 'a');
            TS = new TrieString(prio);
        }
        for(int j = 0; j < 26; j++) {
            if(j == x) {
                if(child[j] == nullptr) {
                    TS->child[j] = trieStringRoot[0]->newOcc(s, k, i+1);
                }
                else TS->child[j] = child[j]->newOcc(s, k, i+1);
            }
            else TS->child[j] = child[j];
        }
        return TS;
    }
    int inTrie(string s, int i = 0) {
        if(i == s.size()) return prio;
        int x = s.at(i) - 'a';
        if(child[x] == nullptr) return 0;
        return child[x]->inTrie(s, i+1);
    }
};

struct Trie {
    int occ = 0, tot = 0;
    Trie* child[2];
    Trie(int i) {
        occ += i;
        tot += i;
        child[0] = child[1] = nullptr;
    }
    Trie* newOcc(int n, int k, int i = MAX) {
        if(n == 0) return this;
        int x = -1;
        Trie* T;
        if(i == -1) T = new Trie(occ + k);
        else {
            x = ((n & (1 << i)) >> i);
            T = new Trie(occ);
        }
        for(int j = 0; j < 2; j++) {
            if(j == x) {
                if(child[j] == nullptr) {
                    T->child[j] = trieRoot[0]->newOcc(n, k, i-1);
                }
                else T->child[j] = child[j]->newOcc(n, k, i-1);
                if(T->child[j] != nullptr) T->tot += T->child[j]->tot;
            }
            else {
                T->child[j] = child[j];
                if(T->child[j] != nullptr) T->tot += T->child[j]->tot;
            }
        }
        if(T->tot == 0 && i != MAX) {
            delete T;
            return nullptr;
        }
        return T;
    }
    int smaller(int n, int i = MAX) {
        if(n == 0) return -1;
        if(i == -1) return 0;
        int x = ((n & (1 << i)) >> i);
        int ans = 0;
        if(x == 1) {
            if(child[0] != nullptr) ans += child[0]->tot;
        }
        return ans + (child[x]->smaller(n, i-1));
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    trieRoot[0] = new Trie(0);
    trieStringRoot[0] = new TrieString(0);
    for(int i = 1; i <= q; i++) {
        string que, nam;
        int n = 0, x;
        cin >> que;//
        if(que == "set" || que == "remove") {
            cin >> nam;
            if(que == "set") cin >> n;
            x = trieStringRoot[i-1]->inTrie(nam);
            trieRoot[i] = trieRoot[i-1]->newOcc(x, -1);
            trieStringRoot[i] = trieStringRoot[i-1]->newOcc(nam, n);
            trieRoot[i] = trieRoot[i]->newOcc(n, 1);
        }
        if(que == "query") {
            cin >> nam;
            trieRoot[i] = trieRoot[i-1];
            trieStringRoot[i] = trieStringRoot[i-1];
            cout << trieRoot[i]->smaller(trieStringRoot[i]->inTrie(nam)) << endl;
        }
        if(que == "undo") {
            cin >> n;
            trieRoot[i] = trieRoot[i - 1 - n];
            trieStringRoot[i] = trieStringRoot[i - 1 - n];
        }
    }
    return 0;
}