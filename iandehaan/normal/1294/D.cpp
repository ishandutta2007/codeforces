#include <iostream>
#include <queue>
using namespace std;

int main() {
    int queries, x;
    cin >> queries >> x;
    int rem[x];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < x; i++) {
        rem[i] = 0;
        q.emplace(0, i);
    }
    
    while (queries--) {
        int y;
        cin >> y;
        rem[y%x]++;
        q.emplace(rem[y%x], y%x);
        while (true) {
            pair<int, int> top = q.top();
            //cout << top.first << ' ' << top.second << endl;
            if (rem[top.second] != top.first) {
                q.pop();
                continue;
            }
            cout << rem[top.second]*x + top.second << endl;
            break;
        }
    }
}