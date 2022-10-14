    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;





    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()



    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}


   int t,m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500000],c[500003],sum;

    int cnt;
    string s;
    bool isco(int x,int y)
    {
        int gd=__gcd(x,y);
        if(gd==1)return true;
        else return false;
    }




    int main()
    {

     ios_base::sync_with_stdio(false);


          cin>>t;

    while(t--)
     {
        cin>>n;
        bool yes=true;
        vector<int>v[1001];
        for(int i=0;i<n;i++)
        {cin>>a[i];
        v[a[i]].push_back(i+1);
        }


        mx=-1;
        for(int i=1;i<1001;i++)
        {
            for(int j=1;j<1001;j++)
            {
                if(isco(i,j)&&!v[i].empty()&&!v[j].empty())
                {
                    auto it1=--v[i].end();
                    auto it2=--v[j].end();
                    int tmp1=*it1,tmp2=*it2;
                    mx=max(mx,tmp1+tmp2);
                }
            }
        }
        cout<<mx<<endl;





     }
     /*
    while(t--)
     {
        cin>>n>>m;
        bool yes=true;
        vector<int>v;
        v.push_back(0);
        for(int i=0;i<n;i++)
        {cin>>a[i];
          if(i)v.push_back(v[i-1]+a[i]);

        }

        for(int i=0;i<m;i++)
        {
            cin>>b[i];
            auto it=lower_bound(v.begin(),v.end(),b[i]);
            if()
            int tmp=*it;
            if()
        }
        */
















        return 0;
    }