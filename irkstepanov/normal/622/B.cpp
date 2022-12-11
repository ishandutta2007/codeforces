#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int h = 0, m = 0;
    int t;
    char c;

    cin >> c;
    h = 10 * (c - '0');
    cin >> c;
    h += (c - '0');
    cin >> c;

    cin >> c;
    m = 10 * (c - '0');
    cin >> c;
    m += (c - '0');
    cin >> t;

    while (t--) {
        ++m;
        if (m == 60) {
            ++h;
            m = 0;
            if (h == 24) {
                h = 0;
            }
        }
    }

    if (h < 10) {
        cout << "0";
    }
    cout << h << ":";
    if (m < 10) {
        cout << "0";
    }
    cout << m << "\n";

}