#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[25][25];

int main()
{
    vector<int> v;
    map<pii, int> mp;
    int m,n;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        v.clear();
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    vector<int> vv(m);
    for(int i = 0; i < m;i++){
        vv[i] = i;
    }
    bool ans = false;
    bool cur;
    int cnt;
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            vv[i] = j;
            vv[j] = i;
            cur = true;
            for(int k = 0; k < n; k++){
                cnt = 0;
                for(int l = 0; l < m; l++){
                    if(a[k][l] != vv[l] + 1){
                        cnt++;
                    }
                }
                if(cnt >= 3){
                    cur = false;
                    break;
                }
            }
            vv[i] = i;
            vv[j] = j;
            if(cur){
                ans = true;
                cout << "YES";
                return 0;
            }
        }
    }
    cur = true;
    for(int k = 0; k < n; k++){
        cnt = 0;
        for(int l = 0; l < m; l++){
            if(a[k][l] != vv[l] + 1){
                cnt++;
            }
        }
        if(cnt >= 3){
            cur = false;
            break;
        }
    }
    if(cur){
        ans = true;
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}