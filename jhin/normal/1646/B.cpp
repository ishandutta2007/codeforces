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

    ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],b[500003],c[500003],sum;






    int main()
    {

     ios_base::sync_with_stdio(false);



        cin>>t;

        while(t--)
        {
            cin>>n; bool yes=false;
            for(int i=0;i<n;i++)cin>>a[i];
            sort(a,a+n);

            a[1]+=a[0];
                for(int i=n-1,j=1;i>n/2;)
                {
                    if(a[i]>a[j])
                    {
                        jaaa();
                        yes=true;
                        break;
                    }
                    j++;
                    i--;
                    a[j]+=a[j-1];
                    a[i]+=a[i+1];


                }
                if(!yes)nein();











        }











        return 0;
    }