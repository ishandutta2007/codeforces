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
                cin>>n>>k>>s;

                map<char,int>mp;
                for(char ch='a';ch<='z';ch++)mp[ch]=0;
                for(int i=0;i<n;i++)mp[s[i]]++;
                string fs="";
                for(int i=0;i<k;i++)
                {
                    int j;
                    for(char ch='a',j=0;ch<='z',j<n/k;ch++,j++)
                    {
                        if(mp[ch]<1){if(i==fs.size())fs+=ch;}
                        else {mp[ch]--; if(i==fs.size()&&j==n/k-1)fs+=++ch;}
                    }
                }
                cout<<fs<<endl;










            }



        return 0;
    }