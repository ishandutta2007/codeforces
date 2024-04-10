#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{

    map <pair <int, int>, int> mapa;
    int n;
    cin >> n;

    while (n--)
    {
        pair <int, int> p;
        cin >> p.first >> p.second;
        ++mapa[p];
    }

    int ans = 0;
    for (map <pair <int, int>, int> :: iterator it = mapa.begin(); it != mapa.end(); it++)
        ans = max (ans, it -> second);

    cout << ans;

}