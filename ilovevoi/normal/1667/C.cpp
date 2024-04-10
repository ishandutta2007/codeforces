#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define F(i,a,b) for(ll i=a;i<=b;i++)

const ll maxn=7e5+100;
const ll base=3e18;
const ll mod= 1e9+7 ;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

/// have medal in APIO
/// goal 2/8


/*ll n, k ;
vector<pll> vt;
void dosth(ll x,ll y)
{
    if (x==n+1)
    {
        if (vt.size()!=k) return ;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                bool chk=false;
                for (auto p:vt)
                {
                    if (i==p.ff||j==p.ss)
                    {
                        chk=true;
                        break;
                    }
                    if (i-j==p.ff-p.ss)
                    {
                        chk=true;
                        break;
                    }

                }
                if (chk==false)
                    return ;
            }
        }

        for (auto p:vt)
        {
            cout <<p.ff<<" "<<p.ss<<endl;
        }
        cout <<endl;
        return ;
    }
    if (y==n)
    {
        dosth(x+1,1);
    }
    else
    {
        dosth(x,y+1);
    }
    if (vt.size()!=k)
    {
        vt.pb(make_pair(x,y));
        if (y==n)
    {
        dosth(x+1,1);
    }
    else
    {
        dosth(x,y+1);
    }
    vt.pop_back();
    }
}*/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp","r"))
    {
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
    }
    ll n;
    cin>> n;
    ll x=2;
    ll y=n;
    ll px=1;
    ll py=-2;
    vector<pll> vt;
    while (x<=n&&y>=1)
    {
        vt.pb(make_pair(x,y));
        x+=px;
        y+=py;
        px=(3-px);
        py=(-3-py);
    }
    if (n%3==1)
        vt.pb(make_pair(1,1));
    cout <<vt.size()<<endl;
    for (auto p:vt)
    {
        cout <<p.ff<<" "<<p.ss<<endl;
    }
  /*  for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            bool chk=false;
            for (auto p:vt)
            {
                if (i==p.ff||j==p.ss)
                {
                    chk=true;
                    break;
                }
                if (i-j==p.ff-p.ss)
                {
                    chk=true;
                    break;
                }

            }
            if (chk==false)
            {
                cout <<"sai cmmr"<<endl;
                return 0;
            }
        }
    }*/
}