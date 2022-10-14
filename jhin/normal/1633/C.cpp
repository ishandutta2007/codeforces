    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;

    #define f first

    #define s second

    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void ja(){cout<<"YES\n";}
    void ne(){cout<<"NO\n";}

    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],b[500003],sum;



    string s;

    bool yes;


    int main()
    {

     ios_base::sync_with_stdio(false);





            cin>>t;
            while(t--)
            {
                ll hh,mh,ha,ma;yes=false;
                cin>>hh>>ha;
                cin>>mh>>ma;
                cin>>k>>y>>x;
                hh+=k*x;
                for(int i=0;i<=k;i++)
                {
                    ll div1=(hh+ma-1)/ma;
                    ll div2=(mh+ha-1)/ha;

                    if(div1>=div2){yes=true;break;}
                    hh-=x;
                    ha+=y;
                }
                if(yes)ja();
                else ne();





            }




        return 0;
    }