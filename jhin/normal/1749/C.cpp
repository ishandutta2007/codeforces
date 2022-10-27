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
            cin>>n;ans=0;

            for(int i=0;i<n;i++)
            {
                cin>>a[i];

            }

             mx=0;
             ll khra=51;
             for(ll j=1;j<(n+3)/2;j++)
             {
                multiset<ll>myset;
                for(int i=0;i<n;i++)
                {
                    myset.insert(a[i]);
                    }

                   bool yes=true;
                   ll tmpr=j;
                    while(tmpr--)
                    {
                        if(myset.empty()){yes=false;break;}
                        auto it=myset.lower_bound(tmpr+1);

                        if(it==myset.end())it--;
                        ll tmp=*it;

                        if(it==myset.begin()&&tmp>tmpr+1){yes=false;break;}
                        if(tmp>tmpr+1)it--;
                        myset.erase(it);
                        if(myset.empty()){if(tmpr!=0)yes=false;break;}
                        myset.erase(myset.begin());
                        if(!tmpr)break;




                    }

                    if(tmpr==0&&yes)mx=max(mx,j);

                }
                cout<<mx<<endl;





        }












        return 0;
    }