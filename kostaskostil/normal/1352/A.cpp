#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
#define int long long

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        string s;
        cin>>s;
        int c=0;
        for (int i=0; i<s.size(); i++)
            if (s[i]!='0')
                c++;

                cout<<c<<"\n";
        for (int i=0; i<s.size(); i++)
            if (s[i]!='0')
                {
                    cout<<s[i];
                    for (int j=i+1; j<s.size(); j++)
                        cout<<'0';
                    cout<<" ";
                }
                cout<<"\n";

    }

    return 0;
}