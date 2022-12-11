#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main() 
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    map<char, int> m1, m2;
    string s;
    getline(cin, s);
    
    for (int i = 0; i < sz(s); ++i) {
        if (isalpha(s[i])) {
            ++m1[s[i]];
        }
    }
    
    getline(cin, s);
    for (int i = 0; i < sz(s); ++i) {
        if (isalpha(s[i])) {
            ++m2[s[i]];
        }
    }
    
    for (auto it : m2) {
        if (m1[it.first] < it.second) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    
}