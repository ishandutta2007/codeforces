#include<bits/stdc++.h>

using namespace std;

long long n, x, sol;
priority_queue <int> pq;

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x; x -= i;
        pq.push(x); pq.push(x);
        sol += pq.top() - x;
        pq.pop();
    }
    cout << sol;
    return 0;
}