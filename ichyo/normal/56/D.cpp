#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int dp[1001][1001];
string s;
string t;
void calc(int ci, int cj, deque<string>& opes) {
    if(ci == 0 && cj == 0) {
        return;
    }
    stringstream ss;
    if(ci > 0 && dp[ci][cj] ==  dp[ci - 1][cj] + 1) {
        ss << "DELETE ";
        ss << ci;
        opes.push_back(ss.str());
        calc(ci - 1, cj, opes);
    } else if(cj > 0 && dp[ci][cj] == dp[ci][cj - 1] + 1) {
        ss << "INSERT ";
        ss << cj << " " << t[cj - 1];
        calc(ci, cj - 1, opes);
        opes.push_back(ss.str());
    } else if(ci > 0 && cj > 0 && dp[ci][cj] == dp[ci - 1][cj - 1]){
        calc(ci - 1, cj - 1, opes);
    } else if(ci > 0 && cj > 0 && dp[ci][cj] == dp[ci - 1][cj - 1] + 1){
        ss << "REPLACE ";
        ss << cj << " " << t[cj - 1];
        calc(ci - 1, cj - 1, opes);
        opes.push_back(ss.str());
    }else {
        assert(false);
    }
}

int main(){
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    REP(i, n + 1) dp[i][0] = i;
    REP(j, m + 1) dp[0][j] = j;
    REP(i, n) REP(j, m) {
        dp[i + 1][j + 1] = min({
                dp[i + 1][j] + 1,
                dp[i][j + 1] + 1,
                dp[i][j] + (s[i] == t[j] ? 0 : 1)
                });

    }
    deque<string> opes;
    calc(n, m, opes);
    cout << opes.size() << endl;
    for(string s : opes) {
        cout << s << endl;
    }
    return 0;
}