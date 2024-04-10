#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int mod = 1000000007;
int basis[30];
int d = 30;
int sz = 0;
int p[200000];

void add(int mask) {
    for (int i = 0; i < d; i++) {
        if ((mask & 1 << i) == 0) continue;

        if (!basis[i]) {
            basis[i] = mask;
            ++sz;
            return;
        }

        mask ^= basis[i];
    }
}

bool check(int mask) {
    for (int i = 0; i < d; i++) {
        if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

        if (!basis[i]) return false;

        mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
    }
    return true;
}


int main()
{
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum ^= a;
        add(a);
    }
    if(sum == 0) {
        cout << -1;
    } else {
        cout << sz;
    }

}