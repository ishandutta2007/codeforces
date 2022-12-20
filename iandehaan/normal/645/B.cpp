#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

void bad() {
    cout << "YES" << endl;
    exit(0);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, k;
    cin >> n >> k;
    ll amt = n-1;
    ll out = 0;
    for (int i = 0; i < k; i++) {
        out += max((ll)0, amt);
        amt--;
        out += max((ll)0, amt);
        amt--;
    }
    cout << out << endl;
}