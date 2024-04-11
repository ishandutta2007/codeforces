#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 5e5+100;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _ = 0; _ < ___; _++)
    {
        string s;
        cin>>s>>s;
        char pr = '-';
        for (char c: s)
        {
            if (c=='1' and pr!='2')
                cout<<'1',
                pr='2';
            else if (pr!='1')
            {
                if (c=='0') cout<<'1';
                else cout<<'0';
                pr='1';
            }
            else
            {
                cout<<'0';
                pr='0';
            }

        }
        cout<<"\n";
    }
	return 0;
}