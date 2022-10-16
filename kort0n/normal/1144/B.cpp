#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<ll> odd;
    vector<ll> even;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int in;
        cin >> in;
        if(in % 2 == 0) even.push_back(in);
        else odd.push_back(in);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    if(even.size() < odd.size()) swap(odd, even);
    int del = odd.size();
    if(even.size() != odd.size()) del++;
    for(int i = 0; i < del; i++) even.pop_back();
    ll sum = 0;
    for(int i = 0; i < even.size(); i++) sum += even[i];
    cout << sum << endl;
    return 0;
}