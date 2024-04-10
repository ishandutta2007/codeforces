    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;

    #define f first

    #define s second

    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}

    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],b[500003],c[500003],sum;






    int main()
    {

     ios_base::sync_with_stdio(false);



        cin>>t;

        while(t--)
        {
            cin>>n;multiset<pair<int,int>>myset;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }

            bool yes=true;
            for(int i=0;i<n-1;i++)
            {
                if(a[i]>a[i+1])yes=false;
            }
            if(yes)cout<<0<<endl;
            else
            {
            if(a[n-2]<=a[n-1]&&a[n-1]>=0)
            {
                cout<<n-2<<endl;
                for(int i=1;i<n-1;i++)
                    cout<<i<<" "<<n-1<<" "<<n<<endl;
            }
            else cout<<-1<<endl;
            }







        }











        return 0;
    }