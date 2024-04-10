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


        cin>>n>>x>>y;
        bool yes=true;
        for(int i=1;i<=n;i++)
        {
            if(x%i==0)
            a[i]=x;
            else if(y%i==0) a[i]=y;
            else
            {
             int lo=x/i;
             int hi=y/i;
             if(lo==hi)yes=false;
             else
                    a[i]=i*hi;
            }
        }
        if(yes)
        {
            jaaa();
            for(int i=1;i<=n;i++)
                cout<<a[i]<<" ";
                cout<<endl;

        }
        else nein();




        }










        return 0;
    }