    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;

    #define f first



    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}

    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500003],c[500003],sum;

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

            int tmp=n;
            int ind=0;
            while(tmp>0)
            {

               for(int i=0;i<n;i++)
               {
                   if(a[i]==tmp){ind=i;if(tmp!=i+1)b[tmp-1]=i+1;break;}
               }
               vector<int>v;
               for(int i=ind+1;i<tmp;i++)v.push_back(a[i]);
               for(int i=0;i<ind+1;i++)v.push_back(a[i]);
               for(int i=0;i<v.size();i++)a[i]=v[i];
               tmp--;

            }


            for(int i=0;i<n;i++)cout<<b[i]<<" ";cout<<endl;






        }












        return 0;
    }