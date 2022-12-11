#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");

    int n;
    cin >> n;
    int k = n / 7;
    int m = n % 7;

    int minn = 2 * k, maxx = 2 * k;
    if (m >= 6) {
        minn += m - 5;
    }
    maxx += min(m, 2);
    cout << minn << " " << maxx << "\n";

}