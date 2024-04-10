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



        cin>>t;
        while(t--)
        {
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];c[i]=b[i]=a[i];
            }
            ans=a[n-1]-a[0];
            sort(b+1,b+n);
            ans=b[n-1]-b[0];
            sort(c,c+n-1);
            ans=max(ans,c[n-1]-c[0]);

            for(int i=0;i<n-1;i++)
            {
                ans=max(a[i]-a[i+1],ans);
            }
            cout<<ans<<endl;
        }







        return 0;
    }