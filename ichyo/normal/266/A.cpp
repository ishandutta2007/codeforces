#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef long long ll;

const int    INF = 1000000000;
const int    MOD = 1000000007;
const double EPS = 1e-8;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i + 1 < s.size(); i++){
        if(s[i] == s[i + 1]){
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}