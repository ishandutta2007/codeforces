#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

string s[200005];
int n;

int main() {
    cin >> n;
    FO(i,0,n) cin >> s[n-1-i];
    set<string> a;
    FO(i,0,n) if (!a.count(s[i])) {
        cout << s[i] << "\n";
        a.insert(s[i]);
    }
}