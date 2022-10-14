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
            int ai;
            cin>>x>>y>>ai;
            int tmp1=y/ai;
            ans=tmp1+(y%ai);
            ll ans2=tmp1-1+ai-1;
            if(!((tmp1-1)*ai+ai-1>=x&&(tmp1-1)*ai+ai-1<=y))ans2=0;
            ans=max(ans,ans2);
            cout<<ans<<endl;












        }












        return 0;
    }