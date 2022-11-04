#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 2;

int m;
string s;
bool b[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> s;
    if(m == s.length()){
        char mn = 'z';
        for(int i = 0; i < m; i++){
            if(s[i] < mn){
                mn = s[i];
            }
        }
        cout << mn;
        return 0;
    }
    int k;
    char mx = 'a';
    vector<char> v;
    int i;
    for(i = 0; i < (int)s.length() - m; i++){
        k = i;
        for(int j = i + 1; j < i + m; j++){
            if(s[j] <= s[k]){
                k = j;
            }
        }
        b[k] = true;
        v.push_back(s[k]);
        mx = max(s[k], mx);
        i = k;
    }
    for(i = 0; i < s.length(); i++){
        if(s[i] < mx && !b[i]){
            v.push_back(s[i]);
        }
    }
    sort(v.begin(), v.end());
    for(auto ch: v){
        cout << ch;
    }
    return 0;
}