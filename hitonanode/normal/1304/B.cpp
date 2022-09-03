#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    while (N--) cin >> S[N];
    map<string, int> mp;
    string ret;
    for (auto s : S) {
        string srev = s;
        reverse(ALL(srev));
        if (mp[srev]) {
            mp[srev]--;
            ret += s;
        }
        else {
            mp[s]++;
        }
    }
    string ret_add;
    for (auto p : mp) if (p.second) {
        string s = p.first;
        string srev = s;
        reverse(ALL(srev));
        if (s == srev) ret_add = s;
    }
    string ter = ret;
    reverse(ter.begin(), ter.end());
    ret += ret_add + ter;
    cout << ret.length() << endl;
    cout << ret << endl;
}