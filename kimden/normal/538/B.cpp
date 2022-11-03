#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll a[100002], pref[100002], suff[100002];
ll sum;
ll ans;
vector<int> pr, sf;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    char ch;
    for(int i = 0; i < s.length(); ++i){
        ch = (char)max((int)ch, (int)s[i]);
    }
    cout << ch << endl;
    int k = ch - '0';
    bool started;
    for(int i = 0; i < k; ++i){
        started = false;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == '0'){
                if(started){
                    cout << '0';
                }
            } else {
                started = true;
                cout << '1';
                s[j]--;
            }
        }
        if(k - 1 - i){
            cout << ' ';
        }
    }
    return 0;
}