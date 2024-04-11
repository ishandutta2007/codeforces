#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 1e6+100;

typedef long long ll;
#define int ll

template<typename T>
istream& operator >> (istream& is, vector<T>& v)
{
    for (T& i : v)
        is>>i;
    return is;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    set<pair<int, int> > odd;
    set<pair<int, int> > even;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if ((i+j)%2)
                odd.insert({i, j});
            else
                even.insert({i, j});

    int en = -1;
    for (int i=1; i<=n*n; i++)
    {
        int ban;
        cin>>ban;
        if (en==-1)
        {
            if (ban == 1)
            {
                auto pa = *even.begin();
                even.erase(even.begin());

                cout<<2<<" "<<pa.fi<<" "<<pa.se<<endl;
            }
            else
            {
                auto pa = *odd.begin();
                odd.erase(odd.begin());

                cout<<1<<" "<<pa.fi<<" "<<pa.se<<endl;
            }

            if (odd.empty())
                en = 1;
            if (even.empty())
                en = 2;
        }
        else
        {
            int c = 3;
            pair<int, int> pa;
            if (en == 1)
            {
                pa = *even.begin();
                even.erase(even.begin());
                if (ban == 3)
                    c = 2;
            }
            else
            {
                pa = *odd.begin();
                odd.erase(odd.begin());
                if (ban == 3)
                    c = 1;
            }

            cout<<c<<" "<<pa.fi<<" "<<pa.se<<" "<<endl;
        }
    }
}