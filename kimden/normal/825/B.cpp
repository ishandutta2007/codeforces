#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    vector<string> v(10);
    for(int i = 0; i < 10; ++i){
        cin >> v[i];
    }
    int cnt = 0;
    bool gut = true;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j <= 5; ++j){
            gut = true;
            cnt = 0;
            for(int k = 0; k < 5; ++k){
                switch(v[i][j + k]){
                    case 'O': gut = false; break;
                    case 'X': ++cnt; break;
                    default: break;
                }
                if(!gut){
                    break;
                }
            }
            if(cnt == 4 && gut){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    for(int j = 0; j < 10; ++j){
        for(int i = 0; i <= 5; ++i){
            gut = true;
            cnt = 0;
            for(int k = 0; k < 5; ++k){
                switch(v[i + k][j]){
                    case 'O': gut = false; break;
                    case 'X': ++cnt; break;
                    default: break;
                }
                if(!gut){
                    break;
                }
            }
            if(cnt == 4 && gut){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    for(int i = 4; i < 10; ++i){
        for(int j = 0; j <= 5; ++j){
            gut = true;
            cnt = 0;
            for(int k = 0; k < 5; ++k){
                switch(v[i - k][j + k]){
                    case 'O': gut = false; break;
                    case 'X': ++cnt; break;
                    default: break;
                }
                if(!gut){
                    break;
                }
            }
            if(cnt == 4 && gut){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j <= 5; ++j){
            gut = true;
            cnt = 0;
            for(int k = 0; k < 5; ++k){
                switch(v[i + k][j + k]){
                    case 'O': gut = false; break;
                    case 'X': ++cnt; break;
                    default: break;
                }
                if(!gut){
                    break;
                }
            }
            if(cnt == 4 && gut){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}