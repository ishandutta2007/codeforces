    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;





    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}


    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500000],c[500003],sum;

    int cnt;
    string s;




    int main()
    {

     ios_base::sync_with_stdio(false);







            cin>>n>>m;

            for(int i=0;i<n;i++)
                cin>>a[i];

            ll ans=0;
            for(ll i=1;i<=n;i++)
                ans+=(i*(i+1))/2;
            for(int i=0;i<n-1;i++)
            {
                if(a[i]==a[i+1])
                {
                    ans-=(i+1)*(n-i-1);
                }
            }


            for(ll i=0;i<m;i++)
            {
                ll ii;ll ai;
                cin>>ii>>ai;
                ii--;
                if(a[ii]!=a[ii-1]&&ai==a[ii-1])
                    ans-=(ii)*(n-ii);
                else if(a[ii]==a[ii-1]&&ai!=a[ii-1])
                    ans+=(ii)*(n-ii);
                if(a[ii]!=a[ii+1]&&ai==a[ii+1])
                    ans-=(ii+1)*(n-ii-1);


                else if(a[ii]==a[ii+1]&&ai!=a[ii+1])
                    ans+=(ii+1)*(n-ii-1);
                a[ii]=ai;

                cout<<ans<<endl;













        }

        return 0;
    }