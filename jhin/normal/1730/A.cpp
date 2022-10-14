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
                cin>>n>>k;
                map<int,int>mp;ans=0;
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                    mp[a[i]]++;
                }
                for(auto it=mp.begin();it!=mp.end();it++)
                {
                    int tmp=it->second;
                    if(tmp>k)tmp=k;
                    ans+=tmp;
                }
                cout<<ans<<endl;
            }



        return 0;
    }