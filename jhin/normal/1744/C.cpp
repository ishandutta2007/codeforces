    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;





    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}


    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500000],c[500003],sum;

    ll cnt;
    string s;





    int main()
    {

     ios_base::sync_with_stdio(false);




            cin>>t;
            while(t--)
            {
                char ch;
                cin>>n>>ch>>s;
                s+=s;
                set<int>gpos;
                for(int i=0;i<n*2;i++)
                {
                    if(s[i]=='g')gpos.insert(i);
                }
                int mni=0;
                for(int i=0;i<n;i++)
                {
                    if(ch==s[i])
                    {
                        auto it=gpos.lower_bound(i);
                        int tmp=*it;
                        mni=max(mni,tmp-i);

                    }
                }
                cout<<mni<<endl;





            }



        return 0;
    }