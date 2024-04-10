#include<bits/stdc++.h>
using namespace std;

const int   N   = 2e5 + 5;

int main()  {
    int n;      
    cin >> n;
    string S;  
    cin >> S;

    int Sum = 0;
    int ans = 0;

    for(char c : S) {
        if (c == '(')   Sum++;
        if (c == ')')   Sum--;

        if (Sum < 0)
            ans++;
        if (Sum == -1 && c == ')')
            ans++;
    }
    if (Sum)    {
        cout << -1;
        return  0;
    }
    cout << ans << endl;
}