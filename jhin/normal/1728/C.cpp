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
            cin>>n; multiset<int>amul,bmul,aamul,bbmul;ans=0;int aone=0,bone=0;
            for(int i=0;i<n;i++)
                {
                    cin>>a[i];
                    if(a[i]==1)aone++;

                    else if(a[i]<10)aamul.insert(a[i]);
                    else amul.insert(a[i]);
                }
            for(int i=0;i<n;i++)
                {
                    cin>>b[i];
                    if(b[i]==1)bone++;
                    else if(b[i]<10)bbmul.insert(b[i]);
                    else bmul.insert(b[i]);
                }
            while(1)
            {
                if(amul.empty())
                {
                    while(!bmul.empty())
                    {
                    auto it2=bmul.begin();
                    int bb=*it2;
                    int num=int(log10(bb))+1;
                    bbmul.insert(num);
                    bmul.erase(bmul.begin());
                    ans++;
                    }
                    break;


                }
                if(bmul.empty())
                {
                    while(!amul.empty())
                    {
                    auto it=amul.begin();
                    int aa=*it;
                    int num=int(log10(aa))+1;
                    aamul.insert(num);
                    amul.erase(amul.begin());
                    ans++;
                    }
                    break;


                }
                auto it=amul.begin();auto it2=bmul.begin();
                int aa=*it,bb=*it2;
                if(aa==bb)
                {

                    amul.erase(amul.begin());bmul.erase(bmul.begin());
                }
                else if(aa<bb)
                {
                    int num=int(log10(aa))+1;
                    aamul.insert(num);
                    amul.erase(amul.begin());
                    ans++;
                }
                else
                {
                    int num=int(log10(bb))+1;
                    bbmul.insert(num);
                    bmul.erase(bmul.begin());
                    ans++;
                }

            }

            while(1)
            {
                if(aamul.empty())
                {
                    int si=bbmul.size();
                    ans+=si;
                    break;


                }
                if(bbmul.empty())
                {
                    int si=aamul.size();
                    ans+=si;
                    break;



                }
                auto it=aamul.begin();auto it2=bbmul.begin();
                int aa=*it,bb=*it2;
                if(aa==bb)
                {

                    aamul.erase(aamul.begin());bbmul.erase(bbmul.begin());
                }
                else if(aa<bb)
                {

                    aamul.erase(aamul.begin());
                    ans++;
                }
                else
                {

                    bbmul.erase(bbmul.begin());
                    ans++;
                }

            }
            cout<<ans<<endl;




        }







        return 0;
    }