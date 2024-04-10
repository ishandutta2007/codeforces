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
                cin>>x>>y;
                if(x<0)
                mnx=max(mnx,abs(x));
                if(x>0)mxx=max(mxx,abs(x));
                if(y<0)
                mny=max(mny,abs(y));
                if(y>0)mxy=max(mxy,abs(y));
            }
            cout<<2*(mxx+mxy+mnx+mny)<<endl;
        }

        return 0;
    }