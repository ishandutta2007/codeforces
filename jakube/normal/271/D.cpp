#include <bits/stdc++.h>
using namespace std;

int k;
int n;
vector<int> data;
vector<bool> good(26);

class Node {
public:
    vector<Node*> nodes;
    Node() {
        nodes = vector<Node*>(26, nullptr);
    }

    void add(int idx) {
        if (idx < n) {
            if (nodes[data[idx]] == nullptr) {
                nodes[data[idx]] = new Node{};
            }
            nodes[data[idx]]->add(idx+1);
        }
    }

    int count(int K) {
        if (K > k) return 0;

        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (nodes[i] != nullptr)
                total += nodes[i]->count(K + (!good[i]));
        }
        return total + 1;
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    data.reserve(s.size());
    for (char c : s)
        data.push_back(c - 'a');
    string g;
    cin >> g;

    for (int i = 0; i < 26; i++)
        good[i] = (g[i] == '1');

    n = s.size();
    cin >> k;
    
    Node head;
    for (int i = 0; i < n; i++) {
        head.add(i);
    }

    cout << head.count(0) - 1 << endl;
}