#include "bits/stdc++.h"
using namespace std;

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v)
        is >> x;
    return is;
}

struct BinaryTrie {
    BinaryTrie() {
        ch[0] = ch[1] = nullptr;
        count = 0;
    }

    void add(int val, int idx=20) {
        count++;
        if (idx >= 0) {
            int c = (val & (1 << idx)) ? 1 : 0;
            if (!ch[c])
                ch[c] = new BinaryTrie();
            ch[c]->add(val, idx - 1);
        }
    }

    bool remove(int val, int idx=20) {
        if (idx >= 0) {
            int c = (val & (1 << idx)) ? 1 : 0;
            bool removed = ch[c] && ch[c]->remove(val, idx - 1);
            count -= removed;
            return removed;
        } else {
            if (count) {
                count--;
                return true;
            } else {
                return false;
            }
        }
    }

    int find_one(int idx=20) {
        if (idx >= 0) {
            if (ch[1] && ch[1]->count) {
                return (1 << idx) + ch[1]->find_one(idx-1);
            } else {
                return ch[0]->find_one(idx-1);
            }
        }
        return 0;
    }

    
    int count;
    BinaryTrie* ch[2];
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;

    vector<BinaryTrie> tries(20);

    auto add = [&tries](int x) {
        for (int i = 0; i < 20; i++)
            if (x & (1 << i))
                tries[i].add(x);
    };
    auto remove = [&tries](int x) {
        for (int i = 0; i < 20; i++)
            if (x & (1 << i))
                tries[i].remove(x);
    };

    for (auto x : v) {
        add(x);
    }

    vector<int> result;
    for (int m = 19; m >= 0; m--) {
        while (tries[m].count) {
            int x = tries[m].find_one();
            remove(x);
            for (int i = 19; i >= 0; i--) {
                if ((x & (1 << i)) == 0 && tries[i].count) {
                    int y = tries[i].find_one();
                    remove(y);
                    int tmp = x & y;
                    x |= y;
                    add(tmp);
                }
            }
            result.push_back(x);
        }
    }

    long long sum = 0;
    for (int x : result) {
        sum += (long long)x * x;
    }
    cout << sum << '\n';
}