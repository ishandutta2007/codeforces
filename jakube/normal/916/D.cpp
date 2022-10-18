#include <bits/stdc++.h>
using namespace std;

struct StringTrieNode {
    StringTrieNode() {
        for (int i = 0; i < 26; i++) {
            ch[i] = nullptr;
        }
        data = -1;
    }

    StringTrieNode(StringTrieNode* old) {
        for (int i = 0; i < 26; i++) {
            ch[i] = old->ch[i];
        }
        data = old->data;
    }

    StringTrieNode* add(string const& s, int priority, int idx=0) {
        auto neww = new StringTrieNode(this);
        if (idx == (int)s.size()) {
            neww->data = priority;
        } else {
            int c = s[idx] - 'a';
            if (!ch[c])
                neww->ch[c] = new StringTrieNode();
            neww->ch[c] = neww->ch[c]->add(s, priority, idx + 1);
        }
        return neww;
    }

    StringTrieNode* remove(string const& s, int idx=0) {
        auto neww = new StringTrieNode(this);
        if (idx == (int)s.size()) {
            neww->data = -1;
        } else {
            int c = s[idx] - 'a';
            if (neww->ch[c])
                neww->ch[c] = neww->ch[c]->remove(s, idx + 1);
        }
        return neww;
    }

    int getData(string const& s, int idx=0) {
        if (idx == (int)s.size()) {
            return data;
        } else {
            int c = s[idx] - 'a';
            if (ch[c] == nullptr)
                return -1;
            else 
                return ch[c]->getData(s, idx+1);
        }
    }

    int data;
    StringTrieNode* ch[26];
};

struct BinaryTrie {
    BinaryTrie() {
        for (int i = 0; i < 2; i++) {
            ch[i] = nullptr;
        }
        data = 0;
    }

    BinaryTrie(BinaryTrie* old) {
        for (int i = 0; i < 2; i++) {
            ch[i] = old->ch[i];
        }
        data = old->data;
    }

    BinaryTrie* add(int val, int idx=30) {
        auto neww = new BinaryTrie(this);
        neww->data++;
        if (idx >= 0) {
            int c = (val & (1 << idx)) ? 1 : 0;
            if (!neww->ch[c])
                neww->ch[c] = new BinaryTrie();
            neww->ch[c] = neww->ch[c]->add(val, idx - 1);
        }
        return neww;
    }

    BinaryTrie* remove(int val, int idx=30) {
        auto neww = new BinaryTrie(this);
        neww->data--;
        if (idx >= 0) {
            int c = (val & (1 << idx)) ? 1 : 0;
            if (neww->ch[c])
                neww->ch[c] = neww->ch[c]->remove(val, idx - 1);
        }
        return neww;
    }

    int countSmaller(int val, int idx=30) {
        int cnt = 0;
        if (idx >= 0) {
            int c = (val & (1 << idx)) ? 1 : 0;
            for (int i = 0; i < c; i++) {
                if (ch[i])
                    cnt += ch[i]->data;
            }
            if (ch[c])
                cnt += ch[c]->countSmaller(val, idx-1);
        }
        return cnt;
    }

    int data;
    BinaryTrie* ch[2];
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<StringTrieNode*> str_start(n + 1);
    vector<BinaryTrie*> bin_start(n + 1);
    str_start[0] = new StringTrieNode();
    bin_start[0] = new BinaryTrie();

    for (int i = 1; i <= n; i++) {
        string t, name;
        cin >> t;
        if (t == "set") {
            cin >> name;
            int pri;
            cin >> pri;
            int old = str_start[i-1]->getData(name);
            if (old >= 0) {
                bin_start[i] = bin_start[i-1]->remove(old);
                bin_start[i] = bin_start[i]->add(pri);
                str_start[i] = str_start[i-1]->add(name, pri);
            } else {
                bin_start[i] = bin_start[i-1]->add(pri);
                str_start[i] = str_start[i-1]->add(name, pri);
            }
        } else if (t == "query") {
            cin >> name;
            bin_start[i] = bin_start[i-1];
            str_start[i] = str_start[i-1];
            int pri = str_start[i]->getData(name);
            if (pri < 0) {
                cout << -1 << endl;
            } else {
                cout << bin_start[i]->countSmaller(pri) << endl;
            }
        } else if (t == "remove") {
            cin >> name;
            int pri = str_start[i-1]->getData(name);
            if (pri >= 0) {
                bin_start[i] = bin_start[i-1]->remove(pri);
                str_start[i] = str_start[i-1]->remove(name);
            } else {
                bin_start[i] = bin_start[i-1];
                str_start[i] = str_start[i-1];
            }
        } else if (t == "undo") {
            int d;
            cin >> d;
            str_start[i] = str_start[max(0, i - d - 1)];
            bin_start[i] = bin_start[max(0, i - d - 1)];
        }
    }
}