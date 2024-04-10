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
            cin>>n>>s;
            bool zer=true;
            if(s[0]=='1')zer=false;
            int seg=1;
            ll ans=0;
            for(int i=1;i<n;i++)
            {
             if(s[i]=='1')
             {
                 if(!zer)seg++;
                 else
                 {
                     if(seg%2)
                     {ans++;
                     if(s[i+1]=='1')zer=false;
                     else zer=true;
                     i++;
                     seg=1;}
                     else
                     {
                         zer=!zer;
                         seg=1;
                     }
                 }
             }
             else
             {
                if(zer)seg++;
                 else
                 {
                     if(seg%2)
                     {ans++;
                     if(s[i+1]=='1')zer=false;
                     else zer=true;
                     i++;
                     seg=1;}
                     else
                     {
                         zer=!zer;
                         seg=1;
                     }
                 }
             }
            }
            cout<<ans<<endl;

        }

        /*while(t--)
        {

        cin>>n>>s;
        bool zer=true;
        if(s[0]=='1')zer=false;
        int seg=1;
        vector<int>v;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='1')
            {if(!zer)seg++;
             else
             {
                v.push_back(seg);
                seg=1;
                zer=!zer;
                if(i==n-1)break;
             }
            }
            else
            {
              if(zer)seg++;
             else
             {
                v.push_back(seg);
                seg=1;
                zer=!zer;
                if(i==n-1)break;
             }
            }
            if(i==n-1)v.push_back(seg);
        }
        ll ans=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]%2)
            {
                ll num1=v[i];
                ll num2=0;
                for(int j=i+1;j<v.size();j++)
                {
                    if(j%2!=i%2)num2+=v[j];
                    else num1+=v[j];
                    if(v[j]%2)
                    {
                       if(j%2!=i%2)ans+=;
                    }
                }
                11100111
            }
        }


        }*/






        return 0;
    }