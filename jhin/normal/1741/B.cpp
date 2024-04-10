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
                if(n==3){cout<<-1<<endl;continue;}
                if(n==1){cout<<1<<endl;continue;}
                if(n%2==0)
                {
                    for(int i=n;i>0;i--)cout<<i<<" ";cout<<endl;continue;
                }
                for(int i=(n+1)/2;i<n+1;i++)cout<<i<<" ";
                for(int i=1;i<(n+1)/2;i++)cout<<i<<" ";cout<<endl;















            }



        return 0;
    }