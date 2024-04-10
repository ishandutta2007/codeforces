#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> V, K, X;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'V') V.push_back(i);
        else if (s[i] == 'K') K.push_back(i);
        else X.push_back(i);
    }
    
    vector<vector<vector<vector<int>>>> dp(V.size() + 1, vector<vector<vector<int>>>(K.size() + 1, vector<vector<int>>(X.size() + 1, vector<int>(2, 1e9))));

    dp[0][0][0][0] = 0;

    auto index = [](auto& list, auto idx){
        return idx ? list[idx-1] : -1;
    };

    auto mini = [](auto& a, auto b) {
        if (b < a) a = b;
    };

    for (int v = 0; v <= V.size(); v++) {
        for (int k = 0; k <= K.size(); k++) {
            for (int x = 0; x <= X.size(); x++) {
                for (int t = 0; t < 2; t++) {
                    auto costs = [&](auto& list, int idx) {
                        int a = index(V, v);
                        int b = index(K, k);
                        int c = index(X, x);
                        int last = index(list, idx);
                        int upto = index(list, idx+1);
                        int cost = 0;
                        for (int i = 0; i < upto; i++) {
                            if (s[i] == 'V')
                                cost += i > a;
                            else if (s[i] == 'K') 
                                cost += i > b;
                            else 
                                cost += i > c;
                        }
                        return cost;
                    };

                    if (v < V.size())
                        mini(dp[v+1][k][x][1], dp[v][k][x][t] + costs(V, v));
                    if (k < K.size() && t != 1)
                        mini(dp[v][k+1][x][0], dp[v][k][x][t] + costs(K, k));
                    if (x < X.size())
                        mini(dp[v][k][x+1][0], dp[v][k][x][t] + costs(X, x));
                }
            }
        }
    }

    auto res = dp.back().back().back();
    cout << *min_element(res.begin(), res.end()) << endl;
}