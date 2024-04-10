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
                cin>>s;
                n=s.size();
                for(int i=0;i<10;i++)
                    a[i]=0,b[i]=0;

                for(int i=0;i<n;i++)
                {
                    int ind=int(s[i]-'0');
                    a[ind]++;

                }
                for(int i=0;i<n;i++)
                {
                    int ind=int(s[i]-'0');
                    for(int j=ind-1;j>=0;j--)
                    {
                        if(a[j]){b[ind]++;break;}
                    }
                    a[ind]--;

                }
                sort(s.begin(),s.end());

                for(int i=n-1;i>0;i--)
                {
                    int ind=int(s[i]-'0');
                    if(ind==9)continue;
                    else
                    {
                        if(b[ind])
                        {s[i]++;
                        b[ind]--;
                        }
                    }

                }
                cout<<s<<endl;







            }



        return 0;
    }