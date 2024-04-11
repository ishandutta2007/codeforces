#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    int INDEX = -1;
    int sum = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') sum++;
        else sum--;
        if(sum < 0) {
            if(INDEX == -1) INDEX = i;
        }
    }
    if(sum != 0) {
        cout << "No" << endl;
        return 0;
    }
    if(INDEX == -1) {
        cout << "Yes" << endl;
        return 0;
    }
    s.erase(s.begin() + INDEX);
    s.push_back(')');
    sum = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') sum++;
        else sum--;
        if(sum < 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}