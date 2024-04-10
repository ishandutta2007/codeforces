#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        int n = sz(a);
        int memo[n];
        // cost of even ending at index i
        memo[0] = 1; // remove the first char
        
        int prevind[26];
        for (int i = 0; i < 26; i++) prevind[i] = -1;
        prevind[a[0]-'a'] = 0;

        for (int i = 1; i < n; i++) {
            memo[i] = n;
            if (prevind[a[i]-'a'] != -1) {
                int distprev = i - prevind[a[i]-'a'] - 1;
                if (prevind[a[i] - 'a'] != 0) memo[i] = min(memo[i], memo[prevind[a[i]-'a']-1] + distprev);
                else memo[i] = min(memo[i], distprev);
            }

            memo[i] = min(memo[i], memo[i-1]+1);


            prevind[a[i]-'a'] = i;
        }

        cout << memo[n-1] << '\n';
    }
}