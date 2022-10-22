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
        if(n%7==0){cout<<n<<endl;continue;}
        n-=(n%10);
        n+=7-(n%7);
        cout<<n<<endl;

    }
    return 0;
}