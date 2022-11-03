#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool len(string& a, string& b){
    return a.length() < b.length();
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n;
    map<ll, pii> mp;
    for(int i = 0; i < n; ++i){
        cin >> k;
        vector<int> v(k);
        ll sum = 0;
        for(int j = 0; j < k; ++j){
            cin >> v[j];
            sum += v[j];
        }
        for(int j = 0; j < k; ++j){
            auto it = mp.find(sum - v[j]);
            if(it != mp.end() && it->second.first < i){
                cout << "YES" << endl;
                cout << it->second.first + 1 << " " << it->second.second + 1 << endl;
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
            mp[sum - v[j]] = {i, j};
        }
    }
    cout << "NO" << endl;

}