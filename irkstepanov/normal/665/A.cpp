#include <iostream>
#include <map>
#include <vector>
#include <fstream>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool intersect(pii& a, pii& b)
{
    if (a.second <= b.first) {
        return false;
    }
    if (a.first >= b.second) {
        return false;
    }
    return true;
}

int main()
{

    //ifstream cin("input.txt");

    int a, ta, b, tb;
    cin >> a >> ta >> b >> tb;

    string s;
    cin >> s;

    int t = (s[0] - '0') * 10 + (s[1] - '0');
    t *= 60;
    t += (s[3] - '0') * 10 + (s[4] - '0');

    int ans = 0;
    for (int st = 5 * 60; st < 24 * 60; st += b) {
        pii p1 = mp(t, t + ta);
        pii p2 = mp(st, st + tb);
        if (intersect(p1, p2)) {
            ++ans;
        }
    }

    cout << ans << "\n";

}