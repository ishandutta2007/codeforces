#include <bits/stdc++.h>

using namespace std;

vector<int> coins;

int main() {
    int n, c, ts=0, s=0;
    cin >> n;
    while(n--) {
        cin >> c;
        ts+=c;
        coins.push_back(c);
    }
    sort(coins.begin(), coins.end());
    reverse(coins.begin(), coins.end());
    for(int a=0; a<coins.size(); a++) {
        s+=coins[a];
        if(s>ts/2) {
            cout << a+1 << '\n';
            break;
        }
    }
}