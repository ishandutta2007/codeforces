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
            cin>>n;

            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            ll gd=a[0],gd2=a[0],gd3=a[0];
            for(int i=0;i<n;i++)
            {
                gd=__gcd(a[i],gd);
                 gd2=__gcd(a[i],gd);

            }
            if(gd==1)cout<<0<<endl;
            else
            {
            ll lm=__gcd(gd2,n);
            if(lm==1)cout<<1<<endl;
            else
            {
                ll bm=__gcd(gd2,n-1);
                if(bm==1)cout<<2<<endl;
                else cout<<3<<endl;
            }

            }




        }


        return 0;
    }