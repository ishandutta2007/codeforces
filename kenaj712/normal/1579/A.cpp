#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string d;
        cin>>d;
        int licz = 0;
        for(auto x:d)
        {
            if(x == 'B')
                licz++;
            else
                licz--;
        }
        if(licz == 0)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';
    }
    return 0;
}