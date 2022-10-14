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
        int m,n,x,y,z,k,cnt,mn=3e9,mx,ans,a[500003],b[500003],c[500003];bool yes1,yes2;vector<long long>v;char ch;string st[102];


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
            int arr[n+4][m+4];
            int arr2[n+4][m+4];
            int arrs[n+4][m+4];
            for(int i=0;i<n;i++)
            {
             for(int j=0;j<m;j++)
                cin>>arr[i][j];
            }
            for(int j=0;j<m;j++)
            {
             for(int i=0;i<n;i++)
                cin>>arr2[i][j];
            }
            vector<int> arr3[n+4],arr4[n+4];
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                arr3[i].push_back(arr[i][j]);
                sort(arr3[i].begin(),arr3[i].end());
            }
             for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                arr4[i].push_back(arr2[i][j]);
                sort(arr4[i].begin(),arr4[i].end());
            }

            for(int i=0;i<n;i++)
            {


                for(int z=0;z<n;z++)
                {

                yes=true;

                for(int j=0;j<m;j++)
                {
                    if(arr3[i][j]!=arr4[z][j])yes=false;
                }
                if(yes)
                {
                    for(int j=0;j<m;j++)
                        arrs[z][j]=arr[i][j];
                        break;
                }
                }

            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<arrs[i][j]<<" ";
                }
                cout<<"\n";
            }
//            1 2 3
//            6 5 4
//
//
//
//            6 5 4
//            1 2 3
//
//            2 5
//            3 4
//            1 6
//
//            2 5
//            1 6
//            3 4
//
//            2 1 3
//            5 6 4
//            3 2 2
        }









        return 0;
        }