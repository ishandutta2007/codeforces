#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll n, m, k;

int main()
{
    cin >> n >> k;
    ll del = n / k;
    if (del % 2 == 0)
    {
        cout << "NO";
        return 0;
    }
    else
        cout << "YES";
    return 0;
    
}