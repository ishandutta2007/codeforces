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
            cin>>n;
            if(n==1)cout<<"1\n";
            else if(n==2)cout<<"1 2\n";
            else if(n==3)cout<<"2 1 3\n";
            else
            {
                if(n%2==0)
                {
                    for(int i=1;i<=n-2;i+=2)
                        cout<<i+1<<" "<<i<<" ";
                        cout<<n-1<<" "<<n<<endl;
                }
                else
                {
                    cout<<n-1<<" "<<2<<" ";
                    for(int i=3;i<=n-4;i+=2)
                        cout<<i+1<<" "<<i<<" ";
                    cout<<"1 "<<n-2<<" "<<n<<endl;
                }
            }




        }






        return 0;
    }