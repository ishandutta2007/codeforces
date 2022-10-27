    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;





    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}


    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500000],c[500003],sum;

    ll cnt;
    string s;





    int main()
    {

     ios_base::sync_with_stdio(false);




            cin>>t;
            while(t--)
            {
                cin>>n>>m;
                ll cnt1=0,cnt2=n;ans=0;


                for(int i=0;i<n;i++)
                {
                      cin>>a[i];
                      if(a[i]%2)cnt1++;
                      ans+=a[i];

                }

                cnt2-=cnt1;

                while(m--)
                {
                    cin>>x>>y;
                    if(x%2==0)
                    {
                        ans+=cnt2*y;
                        if(y%2)cnt1=n,cnt2=0;
                    }
                    else
                    {

                        ans+=cnt1*y;
                        if(y%2)cnt2=n,cnt1=0;
                    }
                    cout<<ans<<endl;
                }




            }



        return 0;
    }