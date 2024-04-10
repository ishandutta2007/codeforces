#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
string s;
int main() {
    ll n;
    ll cnt = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '8')
            cnt++;
    }
    cout << min(n / 11, cnt);
}