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

    int n, a, b;
    cin >> n >> a >> b;
    --a;

    a += b;
    while (a < 0) {
        a += n;
    }
    while (a >= n) {
        a -= n;
    }

    cout << a + 1 << "\n";

}