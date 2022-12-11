#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ll mod = 1000000007;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n, k;
    cin >> n >> k;

    cout << (6 * (n - 1) + 5) * k << "\n";

    for (int i = 0; i < n; i++)
    {
        int a = 6 * i + 1, b = 6 * i + 2, c = 6 * i + 3, d = 6 * i + 5;
        cout << a * k << " " << b * k << " " << c * k << " " << d * k << "\n";
    }

}