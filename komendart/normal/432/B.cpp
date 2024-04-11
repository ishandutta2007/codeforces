#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int guest[n];
    map <int, int> d;
    
    for(int i = 0; i < n; i += 1)
    {
        int x, y;
        cin >> x >> y;
        guest[i] = y;
        if(d.find(x) == d.end())
        {
            d.insert(make_pair(x, 0));
        }
        d[x] += 1;
    }
    for(int i = 0; i < n; i += 1)
    {
        cout << n - 1 + d[guest[i]] << ' ' << n - 1 - d[guest[i]] << endl;
    }
    
    return 0;
}