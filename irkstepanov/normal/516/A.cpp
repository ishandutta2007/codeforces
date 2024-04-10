#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

vector <int> m(10, 0);

void go(int c, int d)
{
    if (c == 9) m[3] += d * 2;
    if (c == 8) m[2] += d * 3;
    if (c == 7) m[7] += d;
    if (c == 6) {m[2] += d; m[3] += d;}
    if (c == 5) m[5] += d;
    if (c == 4) m[2] += d * 2;
    if (c == 3) m[3] += d;
    if (c == 2) m[2] += d;
    if (c >= 3) go(c - 1, d);
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    string a;
    cin >> a;

    for (int i = 0; i < n; i++)
        if (a[i] >= '2') go(a[i] - '0', 1);

    for (int i = 9; i >= 2; i--)
        for (int j = 0; j < m[i]; j++)
        {
            cout << i;
            go(i - 1, -1);
        }

    cout << "\n";

}