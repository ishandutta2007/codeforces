#include <bits/stdc++.h>
using namespace std;

const int MAXDIGITS = 20;

struct BinaryTrie {
    BinaryTrie() {
        ch[0] = ch[1] = nullptr;
        count = 0;
        todo = 0;

    }

    void add(int val, int idx=MAXDIGITS) {
        count++;
        if (idx >= 0) {
            int c = (val & (1 << idx)) ? 1 : 0;
            if (!ch[c])
                ch[c] = new BinaryTrie();
            ch[c]->add(val, idx - 1);
        }
    }

    int find_mex(int cur=0, int idx=MAXDIGITS) {
        if (idx == -1)
            return cur;

        if (count == 0)
            return cur;

        push_down(idx);

        if (ch[0]->has_missing(idx-1))
            return ch[0]->find_mex(cur, idx-1);
        else
            return ch[1]->find_mex(cur + (1 << idx), idx-1);
    }

    void push_down(int idx) {
        // if (count == 0 || todo == 0)
        //     return;
        for (int i = 0; i < 2; i++) {
            if (ch[i] == nullptr)
                ch[i] = new BinaryTrie();
            ch[i]->todo ^= todo;
        }
        if (todo & (1 << idx))
            swap(ch[0], ch[1]);
        todo = 0;
    }

    bool has_missing(int idx) {
        return count < (1 << (idx + 1));
    }

    int count;
    BinaryTrie* ch[2];
    int todo;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    auto s = set<int>(v.begin(), v.end());

    auto bt = BinaryTrie();
    for (auto& x : s)
        bt.add(x);
    
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        bt.todo ^= x;
        cout << bt.find_mex() << '\n';
    }
}