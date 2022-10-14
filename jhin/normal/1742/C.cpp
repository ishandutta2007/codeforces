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
        string s[8];
        bool yes=true;
        n=8;
        for(int i=0;i<n;i++)cin>>s[i];

        for(int i=0;i<n;i++)
        {
            int re=0;
            int bl=0;
            for(int j=0;j<n;j++)
            {
                if(s[j][i]=='R')re++;
                else if(s[j][i]=='B')bl++;
                if(bl==8)yes=false;
            }

        }
        if(yes)cout<<"R\n";
        else cout<<"B\n";
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







     }








        return 0;
    }