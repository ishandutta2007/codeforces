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
            cin>>n>>m; vector<pair<int,int> > v;
            map<int,int>mp;
            for(int i=0;i<m;i++)
            {
                cin>>x>>y;
                v.push_back({y,x});
                mp[x]=i+1;
            }
            sort(v.begin(),v.end());
            while(v.size()>2*n)
            {
                v.erase(--v.end());
            }
            set<int> ind;
            ans=0;
            for(int i=0;i<2*n;i++)
            {
                ind.insert(v[i].second);
                ans+=v[i].first;
            }
            cout<<ans<<endl;
            for(int i=0;i<n;i++)
            {
                auto it=ind.begin();
                auto it2=--ind.end();
                int tmp1=mp[(*it)],tmp2=mp[(*it2)];
                cout<<tmp1<<" "<<tmp2<<endl;
                ind.erase(it);ind.erase(it2);
            }












        }












        return 0;
    }