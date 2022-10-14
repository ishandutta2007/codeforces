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
            cin>>n;
            ans=0;cnt=0;ll backup=0;ll sum=0;
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
                if(a[i]%2&&i!=0&&i!=n-1)ans+=a[i]/2,cnt++,sum+=a[i];
                else if(a[i]%2==0&&i!=0&&i!=n-1)ans+=a[i]/2,sum+=a[i];

            }
            if(sum==cnt||(n==3&&cnt==1))cout<<-1<<endl;
            else
            {
                cout<<cnt+ans+backup<<endl;
            }











        }











        return 0;
    }