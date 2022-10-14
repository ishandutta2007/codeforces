    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;





    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()



    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}


    int t,m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500000],c[500003],sum;

    int cnt;
    string s;




    int main()
    {

     ios_base::sync_with_stdio(false);



        cin>>t;
        while(t--)
        {
            cin>>s;
            int n=s.size();
            int lo=int(s[0]);
            int hi=int(s[n-1]);
            vector<pair<int,int>> myset;
            myset.push_back({lo,1});
            if(lo>hi)
            {
                for(int i=1;i<n;i++)
                {
                    int tmp=int(s[i]);
                    if(tmp<=lo&&tmp>=hi)myset.push_back({tmp,i+1});
                }
                sort(++myset.begin(),--myset.end(),greater<pair<int,int> >());

            }
            else
            {
                for(int i=1;i<n;i++)
                {
                    int tmp=int(s[i]);
                    if(tmp>=lo&&tmp<=hi)myset.push_back({tmp,i+1});
                }
                sort(++myset.begin(),--myset.end());
            }
            cout<<abs(lo-hi)<<" "<<myset.size()<<endl;
            for(int i=0;i<myset.size();i++)
            {

                cout<<myset[i].second<<" ";
            }
            cout<<endl;




        }







        return 0;
    }