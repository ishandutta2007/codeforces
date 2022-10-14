#include <bits/stdc++.h>

        using namespace std;




        const int mod=998244353;
        vector<long long> p;


        int ho,mi,se,ho1,mi1;
        void fix_time()
        {   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
            if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
            if(ho<0)ho+=24;if(ho>=24)ho-=24;
        }
        unsigned long long my_pow(int x,int y)
        {  unsigned  long long num=1;
            for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
                if(y&1){num=(num%mod*i%mod)%mod;}
                    return num;
        }

        bool prime[10000001],prime2[1000001];
        void sieve(){
        for(int i=2;i<=10000000;i+=2)
        prime[i]=false,prime[i-1]=true;
        prime[2]=true;
        for(int i=3;i*i<=10000000;i+=2)
            if(prime[i])
                for(int j=i*i;j<=10000000;j+=2*i)
                    prime[j]=false;
                    }
        vector<long long>vv,vv1;

        long long gcd(long long a , long long b)
        {
          if(b==0) return a;
                   a%=b;
            return gcd(b,a);
        }
        long long m,n,x,y,z,k,cnt,mn=3e9,mx,ans,a[500003],b[500003],c[500003];bool yes1,yes2;vector<long long>v;char ch;string st[102];


        string s;
        int t,x1,y1,z1;
        bool yes;



        int main()
        {

        ios_base::sync_with_stdio(false);


        cin>>t;
        while(t--)
        {

            cin>>n>>m;
            vector<int>ansr[3*n*m];
            int ind=0;
            string tmps[n];
            for(int i=0;i<n;i++)cin>>tmps[i];
            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<m-1;j++)
                {
                    vector<pair<int,int> >tmp;
                    vector<pair<int,int> >zero;
                    if(tmps[i][j]=='1')tmp.push_back({i+1,j+1});
                    else zero.push_back({i+1,j+1});
                    if(tmps[i+1][j]=='1')tmp.push_back({i+2,j+1});
                     else zero.push_back({i+2,j+1});
                    if(tmps[i][j+1]=='1')tmp.push_back({i+1,j+2});
                     else zero.push_back({i+1,j+2});
                    if(tmps[i+1][j+1]=='1')tmp.push_back({i+2,j+2});
                     else zero.push_back({i+2,j+2});
                    if(tmp.size()==3)
                    {
                        for(int z=0;z<3;z++)
                           {

                            ansr[ind].push_back(tmp[z].first);
                            ansr[ind].push_back(tmp[z].second);
                           }
                           ind++;
                    }
                    else if(tmp.size()==2)
                    {
                       pair<int,int>firs1=tmp[0];
                       pair<int,int>seco1=tmp[1];
                       pair<int,int>firs0=zero[0];
                       pair<int,int>seco0=zero[1];
                       ansr[ind].push_back(firs1.first);ansr[ind].push_back(firs1.second);
                        ansr[ind].push_back(firs0.first);ansr[ind].push_back(firs0.second);
                        ansr[ind].push_back(seco0.first);ansr[ind].push_back(seco0.second);
                        ind++;
                        ansr[ind].push_back(firs0.first);ansr[ind].push_back(firs0.second);
                        ansr[ind].push_back(seco0.first);ansr[ind].push_back(seco0.second);
                        ansr[ind].push_back(seco1.first);ansr[ind].push_back(seco1.second);
                        ind++;

                    }
                    else if(tmp.size()==1)
                    {
                        pair<int,int>firs1=tmp[0];
                        pair<int,int>firs0=zero[0];
                        pair<int,int>seco0=zero[1];
                        pair<int,int>thir0=zero[2];
                        ansr[ind].push_back(firs1.first);ansr[ind].push_back(firs1.second);
                        ansr[ind].push_back(firs0.first);ansr[ind].push_back(firs0.second);
                        ansr[ind].push_back(thir0.first);ansr[ind].push_back(thir0.second);
                        ind++;
                        ansr[ind].push_back(firs1.first);ansr[ind].push_back(firs1.second);
                        ansr[ind].push_back(seco0.first);ansr[ind].push_back(seco0.second);
                        ansr[ind].push_back(thir0.first);ansr[ind].push_back(thir0.second);
                        ind++;
                        ansr[ind].push_back(firs1.first);ansr[ind].push_back(firs1.second);
                        ansr[ind].push_back(firs0.first);ansr[ind].push_back(firs0.second);
                        ansr[ind].push_back(seco0.first);ansr[ind].push_back(seco0.second);
                        ind++;

                    }
                    if(tmp.size()==4)
                    {
                        pair<int,int>firs1=tmp[0];
                        pair<int,int>firs0=tmp[1];
                        pair<int,int>seco0=tmp[2];
                        pair<int,int>thir0=tmp[3];

                        ansr[ind].push_back(firs0.first);ansr[ind].push_back(firs0.second);
                        ansr[ind].push_back(seco0.first);ansr[ind].push_back(seco0.second);
                        ansr[ind].push_back(thir0.first);ansr[ind].push_back(thir0.second);
                        ind++;

                        ansr[ind].push_back(firs1.first);ansr[ind].push_back(firs1.second);
                        ansr[ind].push_back(firs0.first);ansr[ind].push_back(firs0.second);
                        ansr[ind].push_back(thir0.first);ansr[ind].push_back(thir0.second);
                        ind++;
                        ansr[ind].push_back(firs1.first);ansr[ind].push_back(firs1.second);
                        ansr[ind].push_back(seco0.first);ansr[ind].push_back(seco0.second);
                        ansr[ind].push_back(thir0.first);ansr[ind].push_back(thir0.second);
                        ind++;
                        ansr[ind].push_back(firs1.first);ansr[ind].push_back(firs1.second);
                        ansr[ind].push_back(firs0.first);ansr[ind].push_back(firs0.second);
                        ansr[ind].push_back(seco0.first);ansr[ind].push_back(seco0.second);
                        ind++;
                    }

                    tmps[i][j]='0';tmps[i+1][j]='0';tmps[i][j+1]='0';tmps[i+1][j+1]='0';

                    if(j<m-3)j++;

                }
                if(i<n-3)i++;
            }

            cout<<ind<<endl;
            for(int i=0;i<ind;i++)
            {
                for(int j=0;j<6;j++)
                    cout<<ansr[i][j]<<" ";
                cout<<"\n";
            }



        }
//            11 01 10 11
//            11 00 01 10


        return 0;
        }