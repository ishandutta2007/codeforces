#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[100002];
map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    int x;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    if(x == 0){
        for(auto pr: mp){
            ans += (pr.second * 1LL * (pr.second - 1));
        }
    }else{
        for(auto pr: mp){
            ans += (pr.second * 1LL * (mp[x ^ pr.first]));
        }
    }
    cout << ans / 2 << endl;
    return 0;
}