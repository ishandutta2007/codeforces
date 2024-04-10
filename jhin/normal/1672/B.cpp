    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;

    #define f first



    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}

    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500003],c[500003],sum;

    int cnt;
    string s;




    int main()
    {

     ios_base::sync_with_stdio(false);



        cin>>t;

        while(t--)
        {


        cin>>s;
        n=s.size();
        bool yes=true;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B')cnt1++;
            else cnt2++;
            if(cnt2<cnt1)yes=false;
        }
        if(s[n-1]!='B'||s[0]=='B')yes=false;

        if(yes)jaaa();
        else nein();










        }







        return 0;
    }