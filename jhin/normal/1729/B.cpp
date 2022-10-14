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
            cin>>n>>s;
            s+=".....";

            string ss="";
            for(int i=0;i<n;i++)
            {
                int tmp=0;
                int nm1=int(s[i]-'0');

                if((s[i+2]=='0'&&s[i+3]=='0')||s[i+2]!='0')
                    {ss+=char('a'+(nm1-1));continue;}
                else
                {
                    tmp=nm1*10;
                    int nm2=int(s[i+1]-'0');
                    tmp+=nm2;
                    ss+=char('a'+(tmp-1));
                    i+=2;
                }
            }
            cout<<ss<<endl;





        }







        return 0;
    }