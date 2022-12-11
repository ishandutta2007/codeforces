#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

int main()
{

    int x, y;
    cin >> x >> y;
    int ans = 0;
    
    while (x > 0 && y > 0) {
        if (x < y) {
            ++x, y -= 2;
        } else {
            ++y, x -= 2;
        }
        if (x >= 0 && y >= 0) {
            ++ans;
        }
    }
    
    cout << ans << "\n";

}