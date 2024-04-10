    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;

    #define f first

    #define s second

    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}

    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],b[500003],c[500003],sum;






    int main()
    {

     ios_base::sync_with_stdio(false);



        cin>>t;

        while(t--)
        {
            cin>>n;x=0;int cnt1=0,cnt2=0;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];b[i]=a[i];
            }

            for(int i=1;i<n-1;i++)
            {
                if(a[i]>a[i-1]&&a[i]>a[i+1])
                {
                    if(i<n-2&&a[i+2]>=a[i])a[i+1]=a[i+2],cnt1++;
                    else a[i+1]=a[i],cnt1++;
                }

            }


                cout<<cnt1<<endl;
                for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;


        }











        return 0;
    }