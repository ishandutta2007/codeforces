#include <bits/stdc++.h>
using namespace std;

struct BinaryCountTrie {
    BinaryCountTrie() {
        for (int i = 0; i < 2; i++) {
            ch[i] = nullptr;
        }
        count = 0;
    }

    void add(int val, int idx=30) {
        count++;
        if (idx >= 0) {
            int c = (val & (1 << idx)) ? 1 : 0;
            if (!ch[c])
                ch[c] = new BinaryCountTrie();
            ch[c]->add(val, idx - 1);
        }
    }

    void remove(int val, int idx=30) {
        count--;
        if (idx >= 0) {
            int c = (val & (1 << idx)) ? 1 : 0;
            if (ch[c])
                ch[c]->remove(val, idx - 1);
        }
    }

    int encrypt(int val, int idx=30) {
        count--;
        int ret = 0;
        if (idx >= 0) {
            int c = (val & (1 << idx)) ? 1 : 0;
            if (ch[c] && ch[c]->count > 0) {
                ret += ch[c]->encrypt(val, idx - 1);
            } else {
                ret += (1 << idx);
                ret += ch[1-c]->encrypt(val, idx - 1);
            }
        }
        return ret;
    }

    int count;
    BinaryCountTrie* ch[2];
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> P(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }

    BinaryCountTrie bt;
    for (int x : P)
        bt.add(x);

    for (int x : A) {
        cout << bt.encrypt(x) << " ";
    }
    cout << endl;
}