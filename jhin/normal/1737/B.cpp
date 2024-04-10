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
                cin>>x>>y;
                ll sqy=sqrt(y);
                if((sqy+1)*(sqy+1)<y)sqy++;
                if((sqy)*(sqy)>y)sqy--;
                ll sqx=sqrt(x);
                if((sqx+1)*(sqx+1)<x)sqx++;
                if((sqx)*(sqx)>x)sqx--;
                ll yy=1,xx=0;
                if(y!=1)
                yy=(sqy-1)*3+(y/sqy)-(sqy-1);
                if(x!=1)
                {
                xx=(sqx-1)*3+(x/sqx)-(sqx-1);
                if(x%sqx==0)xx--;
                }

                cout<<yy-xx<<endl;











            }



        return 0;
    }