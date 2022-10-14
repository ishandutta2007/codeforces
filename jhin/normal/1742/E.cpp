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
        cin>>n>>m;
        bool yes=true;
        vector<ll>v,v2;
        v.push_back(0);v2.push_back(0);
        for(int i=0;i<n;i++)
        {cin>>a[i];
          v.push_back(v[i]+a[i]);
          v2.push_back(max(v2[i],a[i]));


        }
       // for(int i=0;i<n+1;i++)cout<<v[i]<<" ";cout<<endl;

        for(int i=0;i<m;i++)
        {
            cin>>b[i];
            auto it=lower_bound(v2.begin(),v2.end(),b[i]);
            if(it==v2.end())it--;
            int tmp=*it;
            if(tmp>b[i])it--,tmp=*it;
            if(tmp==b[i])
            {
                it=lower_bound(v2.begin(),v2.end(),b[i]+1);
                it--;
                tmp=*it;
                //cout<<tmp<<endl;
            }

            tmp=it-v2.begin();

            b[i]=v[tmp];
        }
        for(int i=0;i<m;i++)cout<<b[i]<<" ";cout<<endl;



     }













        return 0;
    }