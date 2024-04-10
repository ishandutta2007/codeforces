    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;







    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()




    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}


    ll t,n,m,x,y,z,k,mn=1e9,mx,ans,a[500000],b[500000],c[500000];

    ll cnt;

    string s;




    int main()
    {

     ios_base::sync_with_stdio(false);





        cin>>t;
        while(t--)
        {
            cin>>n>>m;
            
            for(int i=0;i<m;i++)
            {
                cin>>x>>y;
                
            }
            if(n<=m)nein();
            else jaaa();
        }












        return 0;
    }