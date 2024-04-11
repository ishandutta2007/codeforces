#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> ans[200100];
    string s;
    cin>>s;
    int nmax=1;
    int zero=1;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='0')
        {
            if (zero!=1)
            {
                ans[zero-1].push_back(i+1);
                zero--;
            }
            else
            {
                ans[nmax].push_back(i+1);
                nmax++;
            }
        }
        else
        {
            if (zero==nmax)
            {
                cout<<"-1\n";
                exit(0);
            }
            ans[zero].push_back(i+1);
            zero++;
        }
    }
    if (zero!=1)
    {
        cout<<"-1\n";
        exit(0);
    }
    cout<<nmax-1<<"\n";
    for (int i=1; i<nmax; i++)
    {
        cout<<ans[i].size();
        for (int j=0; j<ans[i].size(); j++)
            cout<<" "<<ans[i][j];
        cout<<"\n";
    }
    return 0;
}