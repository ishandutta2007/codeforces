#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int nmax = 100500;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    int v[nmax];
    int pos = 0;

    for (int i = 0; i < n; ++i) {
        v[pos++] = 1;
        while (pos > 1 && v[pos - 1] == v[pos - 2]) {
            ++v[pos - 2];
            --pos;
        }
    }

    for (int i = 0; i < pos; ++i) {
        printf("%d ", v[i]);
    }

}