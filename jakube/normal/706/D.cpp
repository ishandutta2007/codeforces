#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node *left = nullptr, *right = nullptr;
    int cnt = 0;

    void add(int number, int idx, int additional_cnt) {
        if (idx == 0) {
            cnt += additional_cnt;
            return;
        }

        if (number & (1 << (idx - 1))) {
            if (right == nullptr)
                right = new Node;
            right->add(number, idx - 1, additional_cnt);
        } else {
            if (left == nullptr) 
                left = new Node;
            left->add(number, idx - 1, additional_cnt);
        }

        cnt = (left != nullptr ? left->cnt : 0) + (right != nullptr ? right->cnt : 0);
    }

    int find_best(int idx, int number) {
        if (idx == 0)
            return 0;

        if (left == nullptr || left->cnt == 0 || (right != nullptr && right->cnt > 0 && (number & (1 << (idx - 1))) == 0))
            return (1 << (idx - 1)) + right->find_best(idx - 1, number);
        else 
            return left->find_best(idx - 1, number);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    Node* root = new Node;
    root->add(0, 32, 300000);

    for (int i = 0; i < n; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+') 
            root->add(x, 32, 1);
        if (c == '-')
            root->add(x, 32, -1);
        if (c == '?') 
            cout << (root->find_best(32, x) ^ x) << '\n';
    }
}