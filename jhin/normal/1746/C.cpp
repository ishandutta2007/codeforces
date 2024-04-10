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

                    cin>>a[i];b[i]=0;
                }

                set<int>myset;
                for(int i=0;i<n;i++)myset.insert(i+1);
                for(int i=1;i<n;i++)
                {
                    if(a[i]<a[i-1])
                    {
                        int tmp=a[i-1]-a[i];
                        auto it=myset.lower_bound(tmp);
                        tmp=*it;
                        b[tmp]=i+1;
                        myset.erase(it);

                    }
                }

                for(int i=0;i<n;i++)
                {
                    if(!b[i])b[i]=1;
                    cout<<b[i]<<" ";
                }
                cout<<endl;
                
                
                























            }



        return 0;
    }