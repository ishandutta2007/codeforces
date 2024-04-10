#include <bits/stdc++.h>
using namespace std;
bool b[6];
int a[6];


bool f(int t, int s) {
    if (t == 6) {
        if (s != 3)
            return false;
        int j = 0;
        for (int i = 0; i < 6; ++i)
        if (b[i])
            j += a[i];
        else
            j -= a[i];
        if (j == 0) {
            return true;
        } else
            return false;
    }
    if (s == 3)
        return f(t + 1, s);
    if (f(t + 1, s))
        return true;
    for (int i = 0; i < 6; ++i)
    if (!b[i]) {
        b[i] = true;
        if (f(t + 1, s + 1))
            return true;
        b[i] = false;
    }
    return false;

}

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int i;
    for (i = 0; i < 6; ++i)
        cin >> a[i];
    if (f(0, 0))
        cout << "YES";
    else

        cout << "NO";

}