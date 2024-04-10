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
        int cnt1=0,cnt2=0,cnt3=0;


        for(int i=0;i<n;i++)
        {
            cin>>a[i];if(a[i])cnt1++;
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            if(b[i])cnt2++;
            if(b[i]!=a[i])cnt3++;
        }
        if(cnt3<abs(cnt1-cnt2)+1)cout<<cnt3<<endl;
        else cout<<abs(cnt1-cnt2)+1<<endl;



     }








        return 0;
    }