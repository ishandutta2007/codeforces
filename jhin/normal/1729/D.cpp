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




    int main()
    {

     ios_base::sync_with_stdio(false);



        cin>>t;
        while(t--)
        {
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            for(int i=0;i<n;i++)
            {
                cin>>b[i];
            }
            for(int i=0;i<n;i++)
            {
                c[i]=b[i]-a[i];
            }
            sort(c,c+n);
            int j=n-1;
            ans=0;
            for(int i=0;i<j;i++)
            {
                if(c[i]+c[j]<0)continue;
                ans++;
                j--;
            }
            cout<<ans<<endl;



        }







        return 0;
    }