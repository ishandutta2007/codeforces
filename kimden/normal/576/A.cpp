#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n;
    cin >> n;
    vector<int> p;
    vector<int> is(1003, 1);
    is[0] = is[1] = 0;
    for(int i = 2; i < 1003; ++i){
        if(is[i]){
            p.push_back(i);
            for(int j = i * i; j < 1003; j += i){
                is[j] = 0;
            }
        }
    }
    vector<int> ans;
    for(int i = 0; i < p.size(); ++i){
        ll cur = p[i];
        while(cur <= n){
            ans.push_back(cur);
            cur *= p[i];
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        if(i){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;



}