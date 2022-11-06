#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char buf[5];

int main()
{
    int n;
    cin >> n;
    
    string last;
    cin >> last;
    
    int ans = 1;
    
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%s", buf);
        if (buf[0] == last[1]) ans++;
        last = string(buf);
    }
    
    cout << ans << endl;
    
    return 0;
}