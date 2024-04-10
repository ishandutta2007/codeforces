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


            cin>>n>>m;
            if(n==1&&m==1)cout<<0<<endl;
            else
            cout<<(n-1)+(m-1)+min(n,m)<<endl;





        }

        return 0;
    }