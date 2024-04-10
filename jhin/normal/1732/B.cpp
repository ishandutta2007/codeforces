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
            cin>>n>>s;
            string tmp="";
            int i=0;
            while(s[i]=='0')i++;
            if(i<n)tmp+='1',i++;

            for(int j=0;i<n;i++)
            {
                if(s[i]!=tmp[j])tmp+=s[i],j++;
            }
            int si=tmp.size();

            cout<<max(0,si-1)<<endl;












        }


        return 0;
    }