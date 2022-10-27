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
                cin>>n;
                cnt=0;
                vector<int>v;
                for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                    int tmp=a[i];
                    while(tmp%2==0)tmp/=2,cnt++;
                    tmp=i+1;
                    int cnt2=0;
                    while(tmp%2==0)tmp/=2,cnt2++;
                    if(cnt2)v.push_back(cnt2);
                }

                int op=0;
                sort(v.begin(),v.end());
                while(n-cnt>0&&!v.empty())
                {

                    auto it=--v.end();
                    cnt+=*it;
                    v.erase(it);
                    op++;
                }
                if(n>cnt)cout<<"-1\n";
                else cout<<op<<endl;





            }



        return 0;
    }