#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int deg(int x)
{
    int ans = 0;
    while (x % 5 == 0) {
        x /= 5;
        ++ans;
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");

    int m;
    cin >> m;

    int cnt = 0;

    for (int n = 5; ; n += 5) {
        cnt += deg(n);
        if (cnt == m) {
            cout << "5\n";
            for (int i = n; i < n + 5; ++i) {
                cout << i << " ";
            }
            return 0;
        }
        if (cnt > m) {
            cout << "0\n";
            return 0;
        }
    }

}