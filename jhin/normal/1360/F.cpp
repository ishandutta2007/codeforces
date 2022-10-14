        #include <bits/stdc++.h>

        using namespace std;




        const int mod=998244353;
        vector<long long> p;


        int ho,mi,se,ho1,mi1,cnt;
        void fix_time()
        {   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
            if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
            if(ho<0)ho+=24;if(ho>=24)ho-=24;
        }
        unsigned long long my_pow(int x,int y)
        {  unsigned  long long num=1;
            for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
                if(y&1)num=(num*i);
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
        void pfact(long long xx)
        {   if(xx%2==0){p.push_back(2);while(xx%2==0)xx/=2,cnt++;vv.push_back(cnt);}
                for(long long i=3;i*i<=xx;i+=2)
                        if(xx%i==0){cnt=0;p.push_back(i);while(xx%i==0)xx/=i,cnt++;vv.push_back(cnt);}
                            if(xx>1)p.push_back(xx),cnt++,vv.push_back(1);
        }
        long long gcd(long long a , long long b)
        {
          if(b==0) return a;
                   a%=b;
            return gcd(b,a);
        }
        long long m,n,x,y,z,k,mn=3e9,mx,ans,a[500001],b[500003];vector<long long>v;char ch;

        string s;
        int t;
        bool yes;



        int main()
        {

        ios_base::sync_with_stdio(false);

        cin>>t;
        while(t--)
        {
            cin>>n>>m;string strings[n];
            for(int i=0;i<n;i++)cin>>strings[i];
            yes=true;
            for(int i=0;i<n;i++)
            {
                string tmp=strings[i];
                for(int j=0;j<n;j++)
                {
                    cnt=0;
                    vector<int>ind;
                    for(int z=0;z<m;z++)
                    {
                        if(strings[j][z]!=tmp[z])ind.push_back(z);
                    }
                    if(ind.size()>2)yes=false;
                    else if(ind.size()==2)
                    {
                        yes=true;
                        string tr=strings[j];
                        string tr2=strings[i];
                        tr[ind[0]]=tr2[ind[0]];
                        for(int k=0;k<n;k++)
                        {
                            int cnt2=0;
                            for(int d=0;d<m;d++)
                            {
                                if(tr[d]!=strings[k][d])cnt2++;
                            }
                            if(cnt2>1)yes=false;
                        }
                        if(yes){cout<<tr<<endl;break;}
                        yes=true;
                        tr=strings[j];
                        tr[ind[1]]=tr2[ind[1]];
                        for(int k=0;k<n;k++)
                        {
                            int cnt2=0;
                            for(int d=0;d<m;d++)
                            {
                                if(tr[d]!=strings[k][d])cnt2++;
                            }
                            if(cnt2>1)yes=false;
                        }
                        if(yes){cout<<tr<<endl;break;}
                    }
                    else if(ind.size()==1)
                    {
                        yes=true;
                        string tr=strings[j];
                        string tr2=strings[i];

                        for(int k=0;k<n;k++)
                        {
                            int cnt2=0;
                            for(int d=0;d<m;d++)
                            {
                                if(tr[d]!=strings[k][d])cnt2++;
                            }
                            if(cnt2>1)yes=false;
                        }
                        if(yes){cout<<tr<<endl;break;}
                        yes=true;
                        tr=strings[j];
                        tr[ind[0]]=tr2[ind[0]];
                        for(int k=0;k<n;k++)
                        {
                            int cnt2=0;
                            for(int d=0;d<m;d++)
                            {
                                if(tr[d]!=strings[k][d])cnt2++;
                            }
                            if(cnt2>1)yes=false;
                        }
                        if(yes){cout<<tr<<endl;break;}

                    }
                    else if(ind.empty())
                    {
                        yes=true;
                        string tr=strings[j];
                        string tr2=strings[i];

                        for(int k=0;k<n;k++)
                        {
                            int cnt2=0;
                            for(int d=0;d<m;d++)
                            {
                                if(tr[d]!=strings[k][d])cnt2++;
                            }
                            if(cnt2>1)yes=false;
                        }
                        if(yes){cout<<tr<<endl;break;}
                    }
                    if(yes)break;
                }
                if(yes)break;
            }
            if(!yes)cout<<-1<<endl;

        }










        return 0;
        }