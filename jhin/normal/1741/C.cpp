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
                ans=0;
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];ans+=a[i];
                }

                set<int>di;
                for(int i=1;i*i<=ans;i++)
                {
                    if(i>n)break;
                    if(ans%i==0)
                    {
                        if(ans/i<=n)di.insert(ans/i);
                        di.insert(i);
                    }
                }
                x=1e9;
                for(auto it=di.begin();it!=di.end();it++)
                {
                    int nn=*it;
                    ll num=ans/nn;
                    ll tmp=0;
                    ll cnt1=0;
                    ll mnx=0;


                    for(int i=0;i<n;i++)
                    {
                        tmp+=a[i];
                        cnt1++;
                        if(tmp==num)
                        {
                            mnx=max(mnx,cnt1);
                            tmp=0;
                            cnt1=0;
                        }
                    }
                    if(mnx&&tmp==0)
                    x=min(x,mnx);

                }
                if(x)
                cout<<x<<endl;















            }



        return 0;
    }