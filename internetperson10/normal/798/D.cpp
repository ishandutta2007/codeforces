#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<ll> a, b;
vector<pair<long double, int>> f;
vector<int> picks;
vector<pair<int, ll>> extra;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n*2);
    b.resize(n*2);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll sum_a, curr_a, sum_b, curr_b;
    sum_a = curr_a = sum_b = curr_b = 0;
    for(int i = 0; i < n; i++) {
        sum_a += a[i];
        sum_b += b[i];
        if(i < (n+1)/2) {
            curr_a += a[i];
            curr_b += b[i]; 
        }
        a[n+i] = a[i];
        b[n+i] = b[i];
    }
    if(2*curr_a > sum_a && 2*curr_b > sum_b) {
        cout << (n+1)/2 << '\n';
        for(int i = 0; i < (n+1)/2; i++) cout << i+1 << ' ';
        return 0;
    }
    if(2*curr_a <= sum_a && 2*curr_b <= sum_b) {
        cout << n - (n+1)/2 << '\n';
        for(int i = (n+1)/2; i < n; i++) cout << i+1 << ' ';
        return 0;
    }
    if(2*curr_b <= sum_b) { // ensure a is too small
        swap(a, b);
        swap(sum_a, sum_b);
        swap(curr_a, curr_b);
    }
    for(int i = 0; i < n; i++) {
        curr_a -= a[i];
        curr_b -= b[i];
        curr_a += a[i + (n+1)/2];
        curr_b += b[i + (n+1)/2];
        if(2*curr_a > sum_a && 2*curr_b > sum_b) {
            cout << (n+1)/2 << '\n';
            for(int j = 0; j < (n+1)/2; j++) cout << (i+j+2 > n ? i+j+2-n : i+j+2) << ' ';
            return 0;
        }
        if(2*curr_a <= sum_a && 2*curr_b <= sum_b) {
            cout << n - (n+1)/2 << '\n';
            for(int j = (n+1)/2; j < n; j++) cout << (i+j+2 > n ? i+j+2-n : i+j+2) << ' ';
            return 0;
        }
        if(2*curr_b <= sum_b) {
            cout << n - (n+1)/2 + 1 << '\n';
            for(int j = 0; j < n - (n+1)/2 + 1; j++) cout << (i+j+(n+1)/2+1 > n ? i+j+(n+1)/2+1-n : i+j+(n+1)/2+1) << ' ';
            return 0;
        }
    }
}