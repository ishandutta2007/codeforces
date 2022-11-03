#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<string>> s(n, vector<string>(m));
    vector<vector<string>> t(n, vector<string>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> s[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> t[i][j];
        }
    }
    vector<vector<int>> ans;

    vector<int> zeros(m, 0), ones(m, 0), z(m, 0), o(m, 0);

    for(int i = 1; i < n - 1; ++i){
        for(int j = 0; j < m; ++j){
            for(int u = (int)s[i][j].length() - 1; u >= 0; --u){
                if(s[i][j][u] == '0'){
                    ans.push_back({i, j, 0, j});
                    ++zeros[j];
                }else{
                    ans.push_back({i, j, n - 1, j});
                    ++ones[j];
                }
            }
        }
    }
    for(int j = 0; j < m; ++j){
        for(int u = (int)s[0][j].length() - 1; u >= 0; --u){
            if(s[0][j][u] == '0'){
                ans.push_back({0, j, 0, (j + 1) % m});
                ++zeros[(j + 1) % m];
            }else{
                ans.push_back({0, j, n - 1, j});
                ++ones[j];
            }
        }
    }
    for(int j = 0; j < m; ++j){
        for(int u = (int)s[n - 1][j].length() - 1; u >= 0; --u){
            if(s[n - 1][j][u] == '0'){
                ans.push_back({n - 1, j, 0, j});
                ++zeros[j];
            }else{
                ans.push_back({n - 1, j, n - 1, (j + 1) % m});
                ++ones[(j + 1) % m];
            }
        }
    }
    /*for(int i = 0; i < ans.size(); ++i){
        cerr << ans[i][0] + 1 << " " << ans[i][1] + 1 << " " << ans[i][2] + 1 << " " << ans[i][3] + 1 << "\n";
    }*/
    for(int i = 1; i < n - 1; ++i){
        for(int j = 0; j < m; ++j){
            for(int u = 0; u < (int)t[i][j].length(); ++u){
                if(t[i][j][u] == '0'){
                    ++z[j];
                }else{
                    ++o[j];
                }
            }
        }
    }
    for(int j = 0; j < m; ++j){
        for(int u = 0; u < (int)t[0][j].length(); ++u){
            if(t[0][j][u] == '0'){
                ++z[(j + 1) % m];
            }else{
                ++o[j];
            }
        }
    }
    for(int j = 0; j < m; ++j){
        for(int u = 0; u < (int)t[n - 1][j].length(); ++u){
            if(t[n - 1][j][u] == '0'){
                ++z[j];
            }else{
                ++o[(j + 1) % m];
            }
        }
    }
 /*   for(int i = 0; i < m; ++i){
        cerr << zeros[i] << " " << ones[i] << " " << z[i] << " " << o[i] << endl;
    }*/
    vector<int> zp0, zp1, op0, op1;
    for(int j = 0; j < m; ++j){
        for(int i = 0; i < zeros[j]; ++i){
            zp0.push_back(j);
        }
        for(int i = 0; i < ones[j]; ++i){
            op0.push_back(j);
        }
        for(int i = 0; i < z[j]; ++i){
            zp1.push_back(j);
        }
        for(int i = 0; i < o[j]; ++i){
            op1.push_back(j);
        }
    }
   // cerr << "====" << endl;
    for(int i = 0; i < zp0.size(); ++i){
         //   cerr << zp0[i] << "->" << zp1[i] << endl;
        if(zp0[i] != zp1[i]){
            ans.push_back({0, zp0[i], 0, zp1[i]});
        }
    }
    for(int i = 0; i < op0.size(); ++i){
            //cerr << op0[i] << "->" << op1[i] << endl;
        if(op0[i] != op1[i]){
            ans.push_back({n - 1, op0[i], n - 1, op1[i]});
        }
    }
   /* cerr << "====" << endl;
    cerr << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        cerr << ans[i][0] + 1 << " " << ans[i][1] + 1 << " " << ans[i][2] + 1 << " " << ans[i][3] + 1 << "\n";
    }
    cerr << "====" << endl;*/
    for(int i = 1; i < n - 1; ++i){
        for(int j = 0; j < m; ++j){
            for(int u = (int)t[i][j].length() - 1; u >= 0; --u){
                if(t[i][j][u] == '0'){
                    ans.push_back({0, j, i, j});
                }else{
                    ans.push_back({n - 1, j, i, j});
                }
            }
        }
    }
    for(int j = 0; j < m; ++j){
        for(int u = (int)t[0][j].length() - 1; u >= 0; --u){
            if(t[0][j][u] == '0'){
                ans.push_back({0, (j + 1) % m, 0, j});
            }else{
                ans.push_back({n - 1, j, 0, j});
            }
        }
    }
    for(int j = 0; j < m; ++j){
        for(int u = (int)t[n - 1][j].length() - 1; u >= 0; --u){
            if(t[n - 1][j][u] == '1'){
                ans.push_back({n - 1, (j + 1) % m, n - 1, j});
            }else{
                ans.push_back({0, j, n - 1, j});
            }
        }
    }


    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << " " << ans[i][2] + 1 << " " << ans[i][3] + 1 << "\n";
    }


}