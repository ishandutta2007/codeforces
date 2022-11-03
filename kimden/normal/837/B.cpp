#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    if(n % 3 != 0 && m % 3 != 0){
        cout << "NO" << endl;
        return 0;
    }
    bool ans = true;
    if(n % 3 != 0){
        for(int u = 0; u < 3; ++u) {
            for (int i = 0; i < (m / 3); ++i) {
                for (int j = 0; j < n; ++j) {
                    if (s[j][i + u * (m / 3)] != s[0][u * (m / 3)]) {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }
        string str = "aqq";
        str[0] = s[0][0];
        str[1] = s[0][m / 3];
        str[2] = s[0][2 * (m / 3)];
        sort(str.begin(), str.end());
        if(str != "BGR"){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
        return 0;
    }
    if(m % 3 != 0){
        for(int u = 0; u < 3; ++u) {
            for (int i = 0; i < (n / 3); ++i) {
                for (int j = 0; j < m; ++j) {
                    if (s[i + u * (n / 3)][j] != s[u * (n / 3)][0]) {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
        }
        string str = "aqq";
        str[0] = s[0][0];
        str[1] = s[n / 3][0];
        str[2] = s[2 * (n / 3)][0];
        sort(str.begin(), str.end());
        if(str != "BGR"){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
        return 0;
    }
    bool tmp = true;
    for(int u = 0; u < 3; ++u) {
        for (int i = 0; i < (m / 3); ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[j][i + u * (m / 3)] != s[0][u * (m / 3)]) {
                    tmp = false;
                    break;
                }
            }
            if(!tmp){
                break;
            }
        }
        if(!tmp){
            break;
        }
    }
    if(tmp) {
        string str = "aqq";
        str[0] = s[0][0];
        str[1] = s[0][m / 3];
        str[2] = s[0][2 * (m / 3)];
        sort(str.begin(), str.end());
        if (str != "BGR") {
            tmp = false;
        } else {
            cout << "YES" << endl;
            return 0;
        }
    }
    for(int u = 0; u < 3; ++u) {
        for (int i = 0; i < (n / 3); ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i + u * (n / 3)][j] != s[u * (n / 3)][0]) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    string str = "aqq";
    str[0] = s[0][0];
    str[1] = s[n / 3][0];
    str[2] = s[2 * (n / 3)][0];
    sort(str.begin(), str.end());
    if(str != "BGR"){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

    return 0;
}