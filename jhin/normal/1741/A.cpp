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
                string s1,s2;
                cin>>s1>>s2;
                int n1=s1.size(),n2=s2.size();
                bool yes=true;
                char ch1=s1[n1-1],ch2=s2[n2-1];
                if(ch1=='L'&&ch2=='L')
                {
                    if(n1<n2)cout<<"<\n";
                    else if(n1>n2)cout<<">\n";
                    else cout<<"=\n";

                }
                else if(ch1=='L'&&(ch2=='M'||ch2=='S'))
                {
                    cout<<">\n";

                }
                else if(ch1=='M'&&ch2=='L')
                {
                    cout<<"<\n";
                }
                else if(ch1=='M'&&ch2=='M')
                {
                    cout<<"=\n";
                }
                else if(ch1=='M'&&ch2=='S')
                {
                    cout<<">\n";
                }
                else if(ch1=='S'&&ch2=='S')
                {
                     if(n1<n2)cout<<">\n";
                    else if(n1>n2)cout<<"<\n";
                    else cout<<"=\n";
                }
                else if(ch1=='S'&&(ch2=='M'||ch2=='L'))
                {
                    cout<<"<\n";
                }















            }



        return 0;
    }