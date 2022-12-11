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

int main()
{

    //ifstream cin("input.txt");

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> p(k);
    for (int i = 0; i < k; ++i) {
        cin >> p[i];
        --p[i];
    }

    int t = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            --a;
            int pos;
            for (pos = 0; p[pos] != a; ++pos) ;
            t += pos + 1;
            for (int x = pos; x; --x) {
                p[x] = p[x - 1];
            }
            p[0] = a;
        }
    }


    cout << t << "\n";

}