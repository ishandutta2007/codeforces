#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    ll n;
    cin >> n;
    ll len = 1;

    while (n > len) {
        n -= len;
        ++len;
    }

    cout << n << "\n";

}