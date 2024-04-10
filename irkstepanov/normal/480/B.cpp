#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int N = 100500;

int a[N], n;

bool ok (int c)
{
    int l = 0, r = 0;
    while (1)
    {
        ++r;
        if (r >= n) return false;
        while (a[r] - a[l] > c) ++l;
        if (a[r] - a[l] == c) return true;
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int l;
    cin >> n >> l;

    int x, y;
    cin >> x >> y;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (ok(x) && ok(y)) {cout << "0\n"; return 0;}
    if (ok(x)) {cout << "1\n" << y << "\n"; return 0;}
    if (ok(y)) {cout << "1\n" << x << "\n"; return 0;}

    set <int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    for (int i = 0; i < n; i++)
    {
        int xpos = x + a[i];
        if (xpos <= l && (s.count(y + xpos) || s.count(xpos - y))) {cout << "1\n" << xpos << "\n"; return 0;}
        xpos = a[i] - x;
        if (xpos >= 0 && (s.count(y + xpos) || s.count(xpos - y))) {cout << "1\n" << xpos << "\n"; return 0;}
    }

    cout << "2\n" << x << " " << y << "\n";

}

//pitri doooooooooor