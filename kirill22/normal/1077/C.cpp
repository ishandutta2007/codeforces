#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T>
istream &operator >> (istream &in, vector<T> &v) {
    for (auto &i : v) {
        in >> i;
    }
    return in;
}

template<class T>
ostream &operator << (ostream &out, const vector<T> &v) {
    for (auto &i : v) {
        out << i << ' ';
    }
    return out;
}
const long long MOD=1e9+7;
int main() {
    ll n;
    cin >> n;
    ll  a[n];
    ll s=0;

    vector<ll> used(1000001);

    for(int i=0;i<n;i++){
        cin >> a[i];
        s+=a[i];
        used[a[i]]++;
    }

    ll ans=0;
    vector<ll> ansi;
    for(int i=0;i<n;i++){
        used[a[i]]--;
        if ( (s-a[i])/2<=1e6 && used[(s-a[i])/2]>0 && (s-a[i])%2==0 && (s-a[i])/2>0 ){
            ans++;
            ansi.push_back(i+1);
        }
        used[a[i]]++;
    }
    cout << ans << endl;
    cout << ansi;




    return 0;
}