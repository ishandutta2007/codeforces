#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x, y;
    cin >> x >> y;

    double val = x * log(y) - y * log(x);

    if(val > 1e-10)
        cout << "<";
    else if(val < -1e-10)
        cout << ">";
    else
        cout << "=";
    return 0;
}