#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> next(vector<ll>& v) {
    ll n = v.size();
    ll i = n - 1;
    while (v[i] == 1) i--;
    ll countLastOnes = n - 1 - i;
    while (v[i] == 0) i--;
    vector<ll> res(v);
    res[i] = 0;
    for (ll j = i + 1; j <= i + 1 + countLastOnes; j++) res[j] = 1;
    for (ll j = i + 2 + countLastOnes; j < n; j++) res[j] = 0;
    return res;
}

int main(void) {
    ll n;
    cin >> n;
    vector<vector<ll>> setmasks;
    vector<ll> firstSetmask(13, 0);
    for (ll i = 0; i < 7; i++) firstSetmask[i] = 1;
    setmasks.push_back(firstSetmask);
    while (setmasks.size() < n) {
        setmasks.push_back(next(setmasks[setmasks.size() - 1]));
    }

    vector<ll> setBitwiseOr(13);    
    for (ll i = 0; i < 13; i++) {
        ll count = 0;
        for (ll j = 0; j < n; j++) {
            if (setmasks[j][i] == 1) count++;
        }
        if (count != 0) {
            cout << "? " << count << " ";
            for (ll j = 0; j < n; j++) {
                if (setmasks[j][i] == 1) cout << j + 1 << " ";
            }
            cout << "\n";
            cout.flush();
            cin >> setBitwiseOr[i];
        } else {
            setBitwiseOr[i] = 0;
        }
    }

    cout << "! ";
    for (ll i = 0; i < n; i++) {
        ll password = 0;
        for (ll j = 0; j < 13; j++) {
            if (setmasks[i][j] == 0) password |= setBitwiseOr[j];
        }
        cout << password << " ";
    }
    cout << "\n";
}