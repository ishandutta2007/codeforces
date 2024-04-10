#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<math.h>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define mp make_pair
#define double long double
#define fi first
#define se second

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x
long long modulo=(long long)(1e9+7);


int  main()
{
    ios_base::sync_with_stdio(false);
    vector <pair<int, int> > ad;
    vector <pair<int, int> > accept;

    priority_queue<int> mniejsze;
    priority_queue<int, std::vector<int>, std::greater<int> > wieksze;

    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        string c;
        cin>>c;
        int a;
        cin>>a;
        auto x=mp(a, i);
        if(c.size()==3)
            ad.push_back(x);
        else
            accept.push_back(x);
    }

    int wskaznik_ad=0;
    int wskazni_accept=0;
    long long  odp=1;

    for (int i=0; i<n; i++)
    {
        bool czy_juz_cos=false;
        if(wskazni_accept!=accept.size() &&( wskaznik_ad==ad.size() || ad[wskaznik_ad].se>accept[wskazni_accept].se))
        {
//if(!wieksze.empty())
          //      cout <<wieksze.top();
           // if(!mniejsze.empty())
           //     cout  <<" "<<mniejsze.top();
           // cout <<endl;
           // cout <<"???: "<<accept[wskazni_accept].fi<<endl;
            bool znalezione=false;

            if(!wieksze.empty() && wieksze.top()==accept[wskazni_accept].fi)
            {
                wieksze.pop();
                znalezione=true ;
            }
            if(!mniejsze.empty()  && mniejsze.top()==accept[wskazni_accept].fi)
            {
                mniejsze.pop();
                znalezione=true ;
            }
            if(znalezione==false)
            {
                //cout <<"kop"<<endl;
                odp=0;
            }

            wskazni_accept++;
            czy_juz_cos=true;
        }

        if(wskazni_accept!=accept.size() && wskaznik_ad!=ad.size() && ad[wskaznik_ad].se<accept[wskazni_accept].se && czy_juz_cos==false)
        {
            if(ad[wskaznik_ad].fi<accept[wskazni_accept].fi)
                mniejsze.push(ad[wskaznik_ad].fi);

            if(ad[wskaznik_ad].fi>accept[wskazni_accept].fi)
                wieksze.push(ad[wskaznik_ad].fi);

            if(ad[wskaznik_ad].fi==accept[wskazni_accept].fi)
            {
                wieksze.push(ad[wskaznik_ad].fi);
                odp=(odp*2)%modulo;
            }

            wskaznik_ad++;
            czy_juz_cos=true;
        }

        if(wskazni_accept==accept.size() &&  czy_juz_cos==false )
        {
            long long licznik=0;
            for (int i=wskaznik_ad; i<ad.size(); i++)
                if((mniejsze.empty()||   ad[i].fi>mniejsze.top()) && (   wieksze.empty()  ||ad[i].fi<wieksze.top()  ))
                    licznik++;
            odp=(odp*(licznik+1))%modulo;
            cout <<odp<<endl;
            return 0;
        }
    }
    cout <<odp<<endl;
}