#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector <pair<int, pair<int, int> > > v;
    int n, m, a[100], h[100], nr;
    char A[22], H[22], cc, c;
int main()
{

    //freopen("in.txt", "r", stdin);

    cin>>H;
    cin>>A;

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int ok=0;
        cin>>m>>c>>nr>>cc;
        if(cc=='y')
            ok=1;
        else ok=2;

        if(c=='h')
        {
            if(h[nr]<2)
            {
                h[nr]+=ok;
                if(h[nr]>=2)
                    v.push_back(make_pair(0, make_pair(nr, m)));
            }
        }

        if(c=='a')
        {
            if(a[nr]<2)
            {
                a[nr]+=ok;
                if(a[nr]>=2)
                    v.push_back(make_pair(1, make_pair(nr, m)));
            }
        }
    }

    for(int i=0; i<v.size(); i++)
    {
        if(v[i].first==0)
            cout<<H;
        else cout<<A;
        cout<<' '<<v[i].second.first<<' '<<v[i].second.second<<'\n';
    }


    return 0;

}