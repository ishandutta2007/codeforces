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
    bool isco(int x,int y)
    {
        int gd=__gcd(x,y);
        if(gd==1)return true;
        else return false;
    }




    int main()
    {

     ios_base::sync_with_stdio(false);


          cin>>t;



    while(t--)
     {
        cin>>n;
        bool chr1[26],chr2[26];
        bool onlya1=true,onlya2=true;
        ll si1=1,si2=1;
        for(int i=0;i<n;i++)
        {
        cin>>x>>y>>s;
        ll tmp=s.size();
        if(x==1)
        {

            for(int i=0;i<s.size();i++)
                if(s[i]!='a')onlya1=false;
            si1+=y*tmp;

        }
        else
        {

            for(int i=0;i<s.size();i++)
                if(s[i]!='a')onlya2=false;
                si2+=y*tmp;
        }
        if(!onlya2)jaaa();
        else
        {
            if(onlya1)
            {
                if(si1<si2)jaaa();
                else nein();
            }
            else nein();
        }


        }




     }













        return 0;
    }