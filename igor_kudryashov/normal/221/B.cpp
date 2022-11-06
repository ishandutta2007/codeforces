#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool haveCom (int a, int b)
{
    vector <int> v1, v2;
    while (a > 0) v1.push_back(a % 10), a /= 10;
    while (b > 0) v2.push_back(b % 10), b /= 10;
    for (int i = 0; i < v1.size(); i++)
        for (int j = 0; j < v2.size(); j++)
            if (v1[i] == v2[j])
                return true;
    return false;
}

int main()
{
    int x;
    cin >> x;
    
    int ans = 0;
    
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i != 0) continue;
        
        if (haveCom(x, i)) ans++;
        if (x / i != i && haveCom(x, x / i)) ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}