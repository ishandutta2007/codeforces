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

    bool ispal(string s)
    {
        string tmp="";
        for(int i=n-1;i>=0;i--)
            tmp+=s[i];
        if(tmp==s)return true;
        else return false;
    }

    string s;

    bool yes;


    int main()
    {

     ios_base::sync_with_stdio(false);



        cin>>t;

        while(t--)
        {
            cin>>n>>k>>s;
            string tmp="";
            for(int i=n;i>=0;i--)tmp+=s[i];
            
            if(ispal(s)||k==0)
            {
                cout<<1<<endl;
            }
            
            else cout<<2<<endl;
        }










        return 0;
    }