#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;

void solve() {
    string S;
    cin >> S;
    string T;
    T.push_back(S[0]);
    for(int i = 1; i < S.size(); i++) {
        T.push_back('#');
        T.push_back(S[i]);
    }
    vector<ll> R(T.size());
    {
        int i = 0, j = 0;
while (i < T.size()) {
  while (i-j >= 0 && i+j < T.size() && T[i-j] == T[i+j]) ++j;
  R[i] = j;
  int k = 1;
  while (i-k >= 0 && i+k < T.size() && k+R[i-k] < j) R[i+k] = R[i-k], ++k;
  i += k; j -= k;
}
    }
    //cerr << "T: " << T << endl;
    /*
    for(int i = 0; i < R.size(); i++) {
        cerr << R[i] << " ";
    }
    cerr << endl;
    */
    ll maxi = 0;
    while(maxi < T.size()) {
        if(T[maxi] != T[T.size()-1-maxi]) break;
        if((maxi + 1) * 2 > T.size()) break;
        maxi++;
    }
    ll ansval = 0;
    ll anslen = 0;
    ll ansR = 0;
    ll ansc = 0;
    for(int i = 0; i < T.size(); i++) {
        ll tmp = 0;
        if(T[i] == '#') {
            tmp = R[i]/2*2;
        } else {
            tmp = (R[i]+1)/2*2-1;
        }
        ll tmp2 = 1e9;
        if(i - R[i] < maxi) {
            chmin(tmp2, i - R[i] + 1);
        }
        if(i + R[i] > T.size() - 1 - maxi) {
            chmin(tmp2, (ll)T.size() - i - R[i]);
        }
        //cerr << i << " " << R[i] << " " << tmp << " " << tmp2 << endl;
        if(tmp2 == 1e9) continue;
        tmp += (tmp2 + 1) / 2 * 2;
        if(chmax(ansval, tmp)) {
            ansc = i;
            ansR = R[i];
            anslen = tmp2;
        }
    }
    string ans;
    //cerr << anslen << " " << ansc << 
    for(int i = 0; i < anslen; i++) {
        if(T[i] != '#') ans.push_back(T[i]);
    }
    for(int i = ansc - ansR + 1; i <= ansc + ansR - 1; i++) {
        if(T[i] != '#') ans.push_back(T[i]);
    }
    for(int i = anslen-1; i >= 0; i--) {
        if(T[T.size() - 1 - i] != '#') ans.push_back(T[T.size()-1-i]);
    }
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}