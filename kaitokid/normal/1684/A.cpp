#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<100)
        {
            cout<<(n%10)<<endl;
            continue;
        }
        int mn=10;
        while(n>0)
        {
            mn=min(mn,n%10);
            n/=10;
        }

        cout<<mn<<endl;
    }
    return 0;

}