#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int nmax = 300500;

int main()
{

    int n, k;
    scanf("%d%d", &n, &k);
    char s[nmax];
    scanf("%s", s);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += max('z' - s[i], s[i] - 'a');
    }
    if (sum < k) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; k; ++i) {
        if ('z' - s[i] >= s[i] - 'a') {
            while (s[i] != 'z' && k) {
                ++s[i];
                --k;
            }
        } else {
            while (s[i] != 'a' && k) {
                --s[i];
                --k;
            }
        }
    }

    printf("%s\n", s);

}