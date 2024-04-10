    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;

    #define f first



    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}


    int t,m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500003],c[500003],sum;

    int cnt;
    string s;




    int main()
    {

     ios_base::sync_with_stdio(false);



        cin>>t;


        while(t--)
        {
            cin>>n>>m;
            map <int,int>mp;
            for(int i=0;i<n;i++)
            {
               cin>>a[i];
            }
            for(int i=0;i<m;i++)
            {
                cin>>b[i]>>c[i];
                mp[b[i]-1]++;
                mp[c[i]-1]++;
            }
            int mno=1e9,mnp=1e9;
            for(int i=0;i<n;i++)
            {
                if(mp[i]%2)mno=min(mno,a[i]);
            }
            for(int i=0;i<m;i++)
            {
                if(mp[b[i]-1]%2==0&&mp[c[i]-1]%2==0)
                   mnp=min(mnp,a[b[i]-1]+a[c[i]-1]);


            }
            if(m%2==0)cout<<"0\n";
            else
                cout<<min(mnp,mno)<<"\n";

        }



        return 0;
    }