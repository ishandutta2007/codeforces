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


        cin>>n;
        int pre=0,cnt=1;ans=0;int st=n,en=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

        }

       for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1])st=min(st,i-1),en=max(en,i+1);
        }
        if(st==n||en-st==2)cout<<"0\n";
        else
        {
            x=en-st;
            x-=2;
            if(x==1)cout<<1<<endl;
            else cout<<x-1<<endl;

        }




        }







        return 0;
    }