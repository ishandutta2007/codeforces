#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, best=0, wins=0, done=0;
    long long int k;
    cin >> n >> k >> m;
    best=m;
    while(wins<k && done<n) {
        cin >> m;
        if(m>best) {
            wins=1;
            best=m;
        }
        else wins++;
        done++;
    }
    cout << best;
}