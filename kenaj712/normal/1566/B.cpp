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
        string a;
        cin>>a;
        char last = '2';
        int licz = 0;
        for(auto x:a)
        {
            if(x != last)
            {
                if(last == '0')
                {
                    last = x;
                    licz++;
                }
                else if(last)
                    last = x;
            }
        }
        if(last == '0')
            licz++;
        cout<<min(licz,2)<<'\n';
    }
    return 0;
}