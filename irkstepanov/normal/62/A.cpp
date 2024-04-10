#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

bool f(int a, int b) {
	return a <= b + 1 && b <= 2 * (a + 1);
}

int main()
{
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a1, a2;
    int b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    bool ans = f(a1, b2) || f(a2, b1);
    cout << (ans ? "YES\n" : "NO\n");

}