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


            cin>>n>>k>>x>>sum;

            if(n*(k-1)+k*x<sum||sum/k<x)cout<<"-1\n";

            else
            {
                ll tmp=sum-k*x;
                for(int i=0;i<n-1;i++)
                {
                    if(tmp>0)
                    {
                        if(tmp<k)
                        {
                            cout<<tmp<<" ";
                            tmp=0;
                        }
                        else
                        {
                            cout<<k-1<<" ";
                            tmp-=k-1;
                        }
                    }
                    else cout<<"0 ";
                }
                cout<<tmp+k*x<<endl;

            }






        }

        return 0;
    }