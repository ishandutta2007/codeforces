    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;

    #define f first

    #define s second

    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()




    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],b[500003],sum;



    string s;

    bool yes;


    int main()
    {

     ios_base::sync_with_stdio(false);





            cin>>t;
            while(t--)
            {
                cin>>s;x=0;y=0;
                for(int i=0;i<s.size();i++)
                {
                   if(s[i]=='1')x++;else y++;
                }
                if(y==x)x--;
                cout<<min(x,y)<<endl;





            }




        return 0;
    }