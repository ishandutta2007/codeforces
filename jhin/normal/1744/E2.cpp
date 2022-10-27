    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;

    using pi =pair<int,int>;





    # define be(v) (v).begin(),(v).end()

    #define eb(v)  (v).begin(),(v).end(),greater<int>()


    void jaaa(){cout<<"YES\n";}
    void nein(){cout<<"NO\n";}


    ll t,m,n,x,y,z,k,mn=1e9,mx,ans;

    ll cnt;
    string s;




    int main()
    {

     ios_base::sync_with_stdio(false);




            cin>>t;
            while(t--)
            {
                ll a,b,c,d;
                cin>>a>>b>>c>>d;
                ll dv=a*b;
                vector<ll>divo1;
                vector<ll>divo2;

                set<ll>divo;
                for(ll i=1;i*i<=a;i++)
                {
                    if(a%i==0)
                    {

                        divo1.push_back(i);
                        if(i*i!=a)
                        divo1.push_back(a/i);

                    }
                }
                for(ll i=1;i*i<=b;i++)
                {
                    if(b%i==0)
                    {

                        divo2.push_back(i);
                        if(i*i!=b)
                        divo2.push_back(b/i);
                    }
                }

                int si=divo1.size();
                for(ll i=0;i<divo1.size();i++)
                {
                    for(ll j=0;j<divo2.size();j++)
                    {
                            divo.insert(divo1[i]*divo2[j]);
                    }
                }
               
                bool yes=false;

                for(auto it=divo.begin();it!=divo.end();it++)
                {
                ll tmp=*it;

                ll tmp2=dv/tmp;
                if(!tmp||!tmp2)continue;

                ll td1=d/(tmp);
                ll tmd=td1*tmp;

                ll tc1=c/tmp2;
                ll tmc=tc1*tmp2;

               //cout<<tmp<<" "<<tmp2<<" "<<td1<<" "<<tmd<<" "<<tc1<<" "<<tmc<<endl;
                if(tmd>b&&tmd<d+1&&tmc>a&&tmc<c+1)
                {
                    cout<<tmc<<" "<<tmd<<endl;
                    yes=true;
                    break;
                }





                }





                if(!yes)
                cout<<"-1 -1\n";




            }



        return 0;
    }