#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n;
        cin>>n;
        for (int i=2; ;i++)
        {
            if (n%((1<<i)-1)==0)
            {
                cout<<n/((1<<i)-1)<<"\n";
                break;
            }
        }
    }
}