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
            cin>>n;
            int mnx=0,mny=0,mxx=0,mxy=0;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
                mxx=max(a[i],mxx);

            }
            bool yes=true;
            int incr=0,decr=0;

            int increasing=-1;
            for(int i=0;i<n;i++)
            {
                if(a[i]==mxx){cnt=i;break;}


            }
            vector<int>inc,dec;
            for(int i=0;i<cnt;i++)
            {
                inc.push_back(a[i]);
            }
            for(int i=cnt;i<n;i++)
            {
                dec.push_back(a[i]);
            }

            for(int i=1;i<inc.size();i++)
            {
                if(inc[i]<inc[i-1])yes=false;
            }
            for(int i=1;i<dec.size();i++)
            {
                if(dec[i]>dec[i-1])yes=false;
            }
            if(yes)jaaa();
            else nein();

        }

        return 0;
    }