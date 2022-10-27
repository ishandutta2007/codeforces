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
                for(int i=0;i<n;i++)
                {

                    cin>>a[i];b[i]=a[i];
                }
                sort(b,b+n);cnt=0;
                for(int i=0;i<n;i++)
                {
                    if(b[i]!=a[i])cnt++;
                }
                cout<<(cnt+1)/2<<endl;






















            }



        return 0;
    }