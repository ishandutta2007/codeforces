#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<int, ll> data;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    cin >> n;

    int x = 0, y = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            ++x;
        } else if (a < b) {
            ++y;
        }
    }

    if (x > y) {
        cout << "Mishka\n";
    } else if (x < y) {
        cout << "Chris\n";
    } else {
        cout << "Friendship is magic!^^\n";
    }

}