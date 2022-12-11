#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int ans;

void upd (int x)
{
    ans = max(ans, x);
}

int main()
{

    int a, b, c;
    cin >> a >> b >> c;

    ans = a + b + c;

    upd(a + b * c);
    upd(a * b + c);
    upd(a * b * c);
    upd((a + b) * c);
    upd(a * (b + c));

    cout << ans << "\n";

}

//pitri doooooooooor