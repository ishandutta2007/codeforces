#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const ll mod = 1000000007;
const int inf = 1000000000;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }

    if (sum % 5 == 0 && sum) cout << sum / 5 << "\n";
    else cout << "-1\n";

}