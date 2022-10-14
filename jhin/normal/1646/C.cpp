    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;

    #define f first

    #define s second

    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}

    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500003],c[500003],sum;
    vector<int>v;
    int cnt;

    void go(int i,ll sum,int cn)
    {

        if(i==15)
        {
            while(sum)
            {
                if(sum%2)cn++;
                sum/=2;
            }
            cnt=min(cn,cnt);
            return;
        }
        if(sum-a[i]>=0)
        go(i+1,sum-a[i],cn+1);
        go(i+1,sum,cn);


    }




    int main()
    {

     ios_base::sync_with_stdio(false);



        cin>>t;
        for(int i=0;;i++)
        {
            if(!i)a[i]=1;
            else a[i]=a[i-1]*i;
            if(a[i]>1000000000000)break;
            v.push_back(a[i]);
        }
            //cout<<v.size();
        while(t--)
        {
            cin>>n;cnt=1e9;

            go(1,n,0);
            cout<<cnt<<endl;










        }












        return 0;
    }