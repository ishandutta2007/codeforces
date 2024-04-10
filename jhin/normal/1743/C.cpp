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
                cin>>n>>s;

                for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                }

                ll mn=1e9,cnt=0;ans=0;
                for(int i=n-1;i>=0;i--)
                {
                    if(s[i]=='1')
                    {
                        cnt++;
                        mn=min(mn,a[i]);
                        ans+=a[i];
                    }
                    else
                    {
                        if(cnt)
                        {
                            if(a[i]>mn)ans+=a[i]-mn;
                            cnt=0;
                            mn=1e9;
                        }
                    }

                }
                cout<<ans<<endl;



            }



        return 0;
    }