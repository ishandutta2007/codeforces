#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int INF = 1000000007;

int n;
int br[5*MAXN];
string s;
vector <int> v;

int obradi () {
    int len = s.size();
    int cnt = 0;
    for (int i=0; i<len; i++) {
        if (s[i] == '(') cnt++;
        if (s[i] == ')') cnt--;
        if (cnt < 0) break;
    }
    if (cnt >= 0) return cnt;
    cnt = 0;
    for (int i=len-1; i>=0; i--) {
        if (s[i] == ')') cnt++;
        if (s[i] == '(') cnt--;
        if (cnt < 0) break;
    }
    if (cnt >= 0) return -cnt;
    return INF;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int nula = 0;
    for (int i=0; i<n; i++) {
        cin >> s;
        int t = obradi();
        if (t == INF) continue;
        if (t > 0) {
            br[t]++;
        } else if (t < 0) {
            v.push_back(t);
        } else {
            nula++;
        }
    }
    int sol = 0;
    for (int i=0; i<v.size(); i++) {
        int val = -v[i];
        if (br[val] > 0) {
            sol++;
            br[val]--;
        }
    }
    cout << sol + nula/2;
    return 0;
}