#include <iostream>
#include <set>
#include <queue>
#include <functional>
#define DMAX 200020

using namespace std;

long long n, w, h;
set<long long> H,W;
long long hdist[DMAX], wdist[DMAX];
multiset <long long> ph, pw;

int main()
{
    cin>>w>>h>>n;

    W.insert(0);
    W.insert(w);
    H.insert(0);
    H.insert(h);
    long long hmax=h;
    long long wmax=w;
    hdist[0]=h;
    ph.insert(h);
    wdist[0]=w;
    pw.insert(w);

    char c;
    long long a;
    for(long long i=1; i<=n; i++)
    {
        cin>>c>>a;

        if(c=='H')
        {
            set<long long> :: iterator it=H.lower_bound(a);
            it--;
            long long x=hdist[*it];

            set<long long >::iterator rit=ph.find(x);
            ph.erase(rit);

            hdist[*it]=a-*it;
            x=hdist[*it];
            it=H.upper_bound(a);

            H.insert(a);
            set<long long> :: iterator iit=H.find(a);
            hdist[*iit]=*it-a;
            long long y=hdist[*iit];

            ph.insert(x);
            ph.insert(y);

            hmax=*ph.rbegin();
            long long Amax=1LL*hmax*1LL*wmax;
            cout<<Amax<<'\n';
        }
        else
        {

            set<long long> :: iterator it=W.lower_bound(a);
            it--;
            long long x=wdist[*it];

            set<long long >::iterator rit=pw.find(x);
                pw.erase(rit);

            wdist[*it]=a-*it;
            x=wdist[*it];
            it=W.upper_bound(a);
            W.insert(a);
            set<long long> :: iterator iit=W.find(a);

            wdist[*iit]=*it-a;
            long long y=wdist[*iit];
            pw.insert(x);
            pw.insert(y);

            wmax=*pw.rbegin();
            long long Amax=1LL*hmax*1LL*wmax;
            cout<<Amax<<'\n';
        }



    }
    return 0;
}