#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int str[200500];
int moji(char in) {
    return (int)(in - 'a');
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k;
    string s, t;
    cin >> k >> s >> t;
    for(int i = 0; i < k; i++) {
        str[i] = moji(s[i]) + moji(t[i]);
    }
    for(int i = k - 1; i > 0; i--) {
        if(str[i] >= 26) {
            str[i] -= 26;
            str[i - 1]++;
        }
    }
    for(int i = 0; i < k; i++) {
        //cerr << moji(s[i]) << " " << moji(t[i]) << " " << str[i] << endl;
    }
    for(int i = 0; i < k; i++) {
        if(str[i] % 2 == 1) {
            str[i+1] += 26;
        }
        str[i] /= 2;
        //cerr << i << " " << str[i] << endl;
        cout << (char)('a' + str[i]);
    }
    cout << endl;
    return 0;
}