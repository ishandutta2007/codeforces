#include <bits/stdc++.h>
#define int long long

using namespace std;

const int nmax=1100;



main()
{

    string s;
    cin>>s;
    int j=1;
    for (int i=0; i<s.length(); i++)
    {
        if ((s[i]-'a'+1)<=j)
        {
            s[i]=('a'+j-1);
            j++;
        }
        if (j==27)
        {
            cout<<s;
            exit(0);
        }
    }
    cout<<"-1\n";
    return 0;

}