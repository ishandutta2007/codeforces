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
    ll a, b;
    cin >> a >> b;
    ll k = 0;
    ll sum = 0;
    while(sum + k + 1 <= a + b) {
        ++k;
        sum += k;
    }
    vector<int> x(k + 1, 0);
    ll prv = 2000000000;
    while(a){
        ll o = min(k, min(prv - 1, a));
        if (o <= 0) break;
        a -= o;
        x[o] = 1;
        prv = o;
    }
    vector<int> q, w;
    for(int i = 1; i <= k; ++i){
        if(x[i]){
            q.push_back(i);
        }else{
            w.push_back(i);
        }
    }
    cout << q.size() << endl;
    for(auto u: q){
        cout << u << " ";
    }
    cout << endl;
    cout << w.size() << endl;
    for(auto u: w){
        cout << u << " ";
    }
    cout << endl;




}