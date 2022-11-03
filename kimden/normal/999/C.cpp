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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> del(n, 0);
    for(char i = 'a'; i <= 'z'; ++i){
        for(int j = 0; j < n; ++j){
            if(s[j] == i){
                --k;
                del[j] = 1;
            }
            if(k == 0){
                break;
            }
        }
        if(k == 0){
            break;
        }
    }
    for(int i = 0; i < n; ++i){
        if(del[i] == 0){
            cout << s[i];
        }
    }
    cout << endl;



}