#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <deque>
#include <map>
#include <set>

using namespace std;

typedef long long I64;

const I64 INF = 10000000;

int main()
{
    I64 n, v;
    cin >> n >> v;
    
    vector<I64> result;
    
    for (I64 i = 0; i < n; i += 1)
    {
        I64 q;
        cin >> q;
        I64 a = INF;
        
        for (int j = 0; j < q; j += 1)
        {
            I64 t;
            cin >> t;
            a = min(a, t);
        }
        
        if (a < v)
        {
            result.push_back(i + 1);
        }
    }
    
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i += 1)
    {
        cout << result[i] << ' ';
    }
}