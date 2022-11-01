#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

#define eb emplace_back
#define pb push_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string s;
int n;
string t[105];

int main() {
    cin >> s >> n;
    fo(i,0,n) {
        cin >> t[i];
    }
    string u;
    fo(i,0,n) {
        fo(j,0,n) {
            u += t[i];
            u += t[j];
        }
    }
    fo(i,0,sz(u)-1) {
        if (u[i] == s[0] && u[i+1] == s[1]) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}