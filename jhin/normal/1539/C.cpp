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

    int pfact(int x)
    { int cnt=0; if(x%2==0){while(x%2==0)x/=2,cnt++;}
    for(int i=3;i*i<=x;i+=2)
    if(x%i==0){while(x%i==0)x/=i,cnt++;}
    if(x>1)cnt++;
    return cnt;

    }
        long long m,n,x,y,z,k,mn=1e9,mx,ans,a[500003],b[500003],c[500003],d[500003];char ch;



        string s;



        int t;
        bool yes;



        int main()
        {

        ios_base::sync_with_stdio(false);


/*
        cin>>n>>t>>s;
        int ar[n+5][27];
        memset(ar,0,sizeof ar);
        int ind=int(s[0]-'a');
        //cout<<"H "<<ind<<endl;
        ar[1][ind]=1;
        for(int i=1;i<n;i++)
            {
                for(char ch='a';ch<='z';ch++)
                {
                   int ind=int(ch-'a');
                   ar[i+1][ind]=ar[i][ind];
                }
                int ind=int(s[i]-'a');
                ar[i+1][ind]++;
                //cout<<ar[i+1][ind]<<endl;
            }

        while(t--)
        {

        cin>>x>>y;
        ans=0;

        for(int i=0;i<26;i++)
        {

           int tmp=ar[y][i]-ar[x-1][i] ;
           ans+=tmp*(i+1);
        }
        cout<<ans<<endl;


        }
*/
cin>>n>>k>>x;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
sort(a,a+n);
vector<long long>tmp;
for(int i=1;i<n;i++)
{
    if(a[i]-a[i-1]>x)
    tmp.push_back(a[i]-a[i-1]);
}
sort(tmp.begin(),tmp.end());
int si=tmp.size();
si++;
//cout<<si<<endl;

for(int i=0;i<tmp.size();i++)
{
    long long chk=(tmp[i])/x;
    if(tmp[i]%x==0)chk--;
    if(chk<=k)
    k-=chk,si--;
    else break;

}
cout<<si<<endl;




        return 0;
        }