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
            cin>>n>>k;
            if(n==1&&k==1)jaaa(),cout<<"1\n";
            else if(n==1)nein();
            else if(k==1)
            {
                jaaa();
                for(int i=1;i<=n;i++)
                    cout<<i<<endl;
            }
            else
            {
                if(n%2)nein();
                else
                {
                    jaaa();
                    set<int>eve,odd;
                    for(int i=1;i<=n*k;i++)
                    {
                        if(i%2)odd.insert(i);
                        else eve.insert(i);
                    }
                    for(int i=0;i<n;i++)
                    {
                        if(i%2)
                        {
                            for(int j=0;j<k;j++)
                            {
                                cout<<*(odd.begin())<<" ";
                                odd.erase(odd.begin());
                            }
                        }
                        else
                        {
                           for(int j=0;j<k;j++)
                            {
                                cout<<*(eve.begin())<<" ";
                                eve.erase(eve.begin());
                            }
                        }
                        cout<<endl;

                    }

                }
            }



        }











        return 0;
    }