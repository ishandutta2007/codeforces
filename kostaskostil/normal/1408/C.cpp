#include "bits/stdc++.h"

#define fi first
#define se second
#define pb push_back

using namespace std;

#define nmax 500500
typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n_;
    cin>>n_;
    for (int _=0; _<n_; _++)
    {
        int n;
        double l;
        cin>>n>>l;
        vector<double> v(n);
        for (double& i:v)
            cin>>i;

        double posl=0;
        double posr=l;
        int il=0;
        int ir=n-1;
        double tl=0;
        double tr=0;
        double vl=1;
        double vr=1;

        while (il<=ir)
        {
            double tlx=tl+(v[il]-posl)/vl;
            double trx=tr+(posr-v[ir])/vr;
            if (tlx<trx)
            {
                tl=tlx;
                posl=v[il];
                vl+=1;
                il++;
            }
            else
            {
                tr=trx;
                posr=v[ir];
                vr+=1;
                ir--;
            }
        }

        if (tl>tr)
        {
            posr-=(tl-tr)*vr;
            tr=tl;
        }
        else
        {
            posl+=(tr-tl)*vl;
            tl=tr;
        }
        cout<<fixed<<setprecision(10);
        cout<<tl+(posr-posl)/(vl+vr)<<"\n";

    }

}