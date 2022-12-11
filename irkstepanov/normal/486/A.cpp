#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 100500;
const int inf = 1000000000;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ll n;
    cin >> n;

    if (n % 2 == 0) cout << n / 2 << "\n";
    else cout << -(n / 2 + 1) << "\n";

}