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

int calmex(vector<int>vec)
{
    vector<int>tmp;int cnn=vec.size();
    for(int i=0;i<vec.size();i++)
    {
        if(!vec[i])cnn++;
    }
    return cnn;
}




    int main()
    {

     ios_base::sync_with_stdio(false);



        cin>>t;

        while(t--)
        {
            cin>>n;yes=false;ans=0;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];

            }

            for(int i=0;i<n;i++)
            {
                vector<int>v;
                for(int j=i;j<n;j++)
                {
                    v.push_back(a[j]);
                    ans+=calmex(v);
                }
            }
            cout<<ans<<endl;


        }











        return 0;
    }