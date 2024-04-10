    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;

    #define f first



    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}

    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500003],c[500003],sum;

    int cnt;
    string s;




    int main()
    {

     ios_base::sync_with_stdio(false);



        cin>>t;

        while(t--)
        {


        cin>>n;multiset<ll>myset;
        ll cake=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            cake+=x;
            myset.insert(x);
        }
        multiset<ll>piece;
        piece.insert(cake);
        while(1)
        {
            if(myset.empty())break;
            auto it=--myset.end();
            ll mx=*it;
            auto it2=--piece.end();
            ll mxp=*it2;
            if(mx>mxp)break;
            if(mx==mxp)
            {
                myset.erase(it);
                piece.erase(it2);
                continue;
            }
            ll ad=mxp/2;
            piece.insert(ad);
            if(mxp%2)ad++;
            piece.insert(ad);
            piece.erase(it2);
        }
        if(myset.empty())jaaa();
        else nein();











        }












        return 0;
    }