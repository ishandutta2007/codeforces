#include <bits/stdc++.h>
using namespace std;

int k;
int cur;
vector<int> result;

void make_smaller(int x, int y) {
    if (x <= y) 
        result.push_back(x);
    else {
        for (long long i = 0; i < (1LL << (x - y)); i++) {
            result.push_back(y);
            if ((int)result.size() > k)
                break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    cin >> k;
    
    int y = 0;
    if (n >= k) {
        for (int i = 0; i < 61; i++) {
            if ((1LL << i) * k >= n) {
                y = i;
                break;
            }
        }
    } else {
        for (int i = 1; i < 61; i++) {
            if ((1LL << i) * n > k) {
                y = -(i - 1);
                break;
            }
        }
    }

    vector<int> res;
    priority_queue<int> pq;
    for (int i = 0; i < 60; i++) {
        if (n & (1LL << i)) {
            res.push_back(i);
            pq.push(i);
        }
    }

    while ((int)pq.size() < k) {
        int x = pq.top();
        pq.pop();
        pq.push(x - 1);
        pq.push(x - 1);
    }
    y = pq.top();


    reverse(res.begin(), res.end());
    for (int i : res)
        make_smaller(i, y);
    
    if (k < (int)result.size()) {
        cout << "No" << '\n';
        return 0;
    }

    while (k > (int)result.size()) {
        result.back()--;
        result.push_back(result.back());
    }

    cout << "Yes" << '\n';
    
    for (auto x : result) {
        cout << x << ' ';
    }
    cout << '\n';
}