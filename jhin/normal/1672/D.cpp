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


        cin>>n;
        bool yes=true;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        map<int,int>mp;
        int ind=0;

       for(int i=n-1;i>=0;i--)
       {
           if(b[i]!=a[i+ind])
           {
               
               if(i!=n-1&&b[i]==b[i+1])
            {
                ind++;
                mp[b[i]]++;

            }
else if(mp[a[i+ind]]>0){mp[a[i+ind]]--;ind--;i++;continue;}
else yes=false;

           }


       }


            if(yes)jaaa();
            else nein();


        }







        return 0;
    }