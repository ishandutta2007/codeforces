#include <iostream>
#define int long long

using namespace std;

bool u[100001];
pair<bool, int> m[100001];

main() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    for (int i = 0; i < n; i++){
        if (a[i] == '<'){
            m[i].first = true;
        }
        else{
            m[i].first = false;
        }
    }
    for (int i = 0; i < n; i++){
        cin >> m[i].second;
    }
    int pos = 0;
    bool prav = false;
    bool kon = false;
    while (!prav && !kon){
        u[pos] = true;
        if (m[pos].first){
            if (pos - m[pos].second >= 0){
                if (!u[pos - m[pos].second])
                    pos = pos - m[pos].second;
                else{
                    kon = true;
                }
            }
            else{
                prav = true;
            }
        }
        else{
            if (pos + m[pos].second < n){
                if (!u[pos + m[pos].second])
                    pos = pos + m[pos].second;
                else{
                    kon = true;
                }
            }
            else{
                prav = true;
            }
        }
    }
    if (!prav){
        cout << "INFINITE";
    }
    else{
        cout << "FINITE";
    }
}