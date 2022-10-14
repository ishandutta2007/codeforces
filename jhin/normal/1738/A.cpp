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
        vector<int>frost,fire;ans=0;

        for(int i=0;i<n;i++)
        {

            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {

            cin>>b[i];
            if(a[i])frost.push_back(b[i]);
            else fire.push_back(b[i]);
            ans+=b[i];
        }
        if(frost.empty()||fire.empty()){cout<<ans<<endl;continue;}
        sort(frost.begin(),frost.end());sort(fire.begin(),fire.end());
        ll ans1=frost[0],ans2=fire[0];
        int si1=frost.size(),si2=fire.size();
        for(int i=si2-1,j=si1;i>=0;i--,j--)
        {
            ans1+=fire[i];
            if(j>0)ans1+=fire[i];

        }
        for(int i=si1-1,j=si2;i>0;i--,j--)
        {
            ans1+=frost[i];
            if(j>0)ans1+=frost[i];

        }

        for(int i=si1-1,j=si2;i>=0;i--,j--)
        {
            ans2+=frost[i];
            if(j>0)ans2+=frost[i];

        }
        for(int i=si2-1,j=si1;i>0;i--,j--)
        {
            ans2+=fire[i];
            if(j>0)ans2+=fire[i];


        }
        //cout<<ans1<<" "<<ans2<<endl;

        cout<<max(ans1,ans2)<<endl;














     }








        return 0;
    }