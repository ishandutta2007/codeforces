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

        cin>>n;vector<int>v;
        set<int>myset;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i])v.push_back(a[i]),myset.insert(a[i]);
        }
        int si1=v.size(),si2=myset.size();
        if(si1<n)cout<<si1<<endl;
        else if(si2!=n)cout<<si1<<endl;
        else cout<<si1+1<<endl;

        }







        return 0;
    }