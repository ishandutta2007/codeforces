#include <bits/stdc++.h>

#define sz(a) static_cast<int>(a.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int gcd(int a, int b)
{
    if (a < b) {
        swap(a, b);
    }
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{

    //ifstream cin("input.txt");

    int a, b, c;
    cin >> a >> b >> c;

    int d = gcd(a, b);
    if (c % d) {
        cout << "No\n";
    } else {
        for (int x = 0; a * x <= c; ++x) {
            if ((c - a * x) % b == 0) {
                cout << "Yes\n";
                return 0;
            }
        }
        cout << "No\n";
    }

}