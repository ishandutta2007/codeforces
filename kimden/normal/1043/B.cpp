#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    for(int i = n - 1; i > 0; --i){
        v[i] -= v[i - 1];
    }
    vector<int> ans;
    for(int i = 1; i <= n; ++i){
        bool good = true;
        for(int j = i; j < n; ++j){
            if(v[j] != v[j - i]){
                good = false;
                break;
            }
        }
        if(good){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        if(i){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << "\n";




}