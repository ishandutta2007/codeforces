#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> type;

int main()
{

    //ifstream cin("input.txt");

    int x;
    cin >> x;

    if (x == 0) {
        cout << "0\n";
        return 0;
    }

    x = abs(x);

    int sum = 0;
    for (int n = 1; ; ++n) {
        sum += n;
        if (x <= sum && x % 2 == sum % 2) {
            cout << n << "\n";
            return 0;
        }
    }

}