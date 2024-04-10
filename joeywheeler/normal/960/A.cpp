#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int c[3];

int main() {
    char s[5005];
    scanf("%s", s);
    int n = strlen(s);
    fo(i,0,n-1) {
        if (s[i] > s[i+1]) {
            printf("NO\n");
            return 0;
        }
        c[s[i]-'a']++;
    }
    c[s[n-1]-'a']++;
    if (c[0] && c[1] && (c[2] == c[0] || c[2] == c[1])) {
        printf("YES\n");
    } else {
        printf("NO\n");
        return 0;
    }
}