#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    int day = 1, timer = 0, cnt = 0;
    string s;
    getline(cin, s);

    while (n--) {
        getline(cin, s);
        int t = (s[1] - '0') * 10 + (s[2] - '0');
        t *= 60;
        t += (s[4] - '0') * 10 + (s[5] - '0');
        if (s[7] == 'p') {
            t += 12 * 60;
        }
        if (s[7] == 'a' && s[1] == '1' && s[2] == '2') {
            t = (s[4] - '0') * 10 + (s[5] - '0');
        }
        if (s[7] == 'p' && s[1] == '1' && s[2] == '2') {
            t = 12 * 60 + (s[4] - '0') * 10 + (s[5] - '0');
        }
        if (timer == t) {
            if (cnt == 10) {
                ++day;
                cnt = 1;
            } else {
                ++cnt;
            }
        } else if (t > timer) {
            timer = t;
            cnt = 1;
        } else {
            ++day;
            timer = t;
            cnt = 1;
        }
    }

    cout << day << "\n";

}