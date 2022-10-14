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
                cin>>n;vector<pair<int,int> >tmp,tmp2;
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];tmp.push_back({a[i],a[i]});

                }
                ans=0;bool yes=true;
                while(tmp.size()>1)
                {
                    for(int i=0;i<tmp.size();i+=2)
                    {
                        int mxx=tmp[i].first;
                        int mnn=tmp[i].second;
                        int mxx2=tmp[i+1].first;
                        int mnn2=tmp[i+1].second;

                        if((mnn2<mxx&&mxx2>mxx)||(mnn<mxx2&&mxx>mxx2))yes=false;
                        if(mxx2<mxx)ans++; tmp2.push_back({max(mxx,mxx2),min(mnn,mnn2)});
                    }
                    tmp=tmp2;
                    tmp2.clear();
                }
                if(yes)cout<<ans<<endl;
                else cout<<"-1\n";



















            }



        return 0;
    }