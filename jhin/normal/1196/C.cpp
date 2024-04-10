    // system.cout(translate *from glut);
    #include <bits/stdc++.h>

    using namespace std;




    const int mod=1e9+7;
    vector<long long> p;


    int ho,mi,se,ho1,mi1;
    void fix_time()
    {   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
        if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
        if(ho<0)ho+=24;if(ho>24)ho-=24;
    }
    unsigned long long my_pow(int x,int y)
    {  unsigned  long long num=1;
        for(unsigned long long i=x;y>0;i=(i*i),y>>=1)
            if(y&1)num=(num*i);
        return num;
    }

    bool prime[1000001],prime2[1000001];
    void sieve(){
        for(int i=2;i<=1000000;i+=2)
            prime[i]=false,prime[i-1]=true;
        prime[2]=true;
        for(int i=3;i*i<=1000000;i+=2)
            if(prime[i])
                for(int j=i*i;j<=1000000;j+=2*i)
                    prime[j]=false;
    }
    vector<long long>vv,vv1;int cnt=0;
    void pfact(long long x)
    {   if(x%2==0){p.push_back(2);while(x%2==0)x/=2,cnt++;vv.push_back(cnt);}
        for(long long i=3;i*i<=x;i+=2)
            if(x%i==0){cnt=0;p.push_back(i);while(x%i==0)x/=i,cnt++;vv.push_back(cnt);}
        if(x>1)p.push_back(x),cnt++,vv.push_back(1);
    }
    long long gcd(long long a , long long b)
    {
       if(b==0) return a;
       a%=b;
       return gcd(b,a);
    }
int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[4][500003],b[500003],c[500000],c2[500000];string s2;vector<int>v,vr,v2[100003];unsigned long long sum,ans,num;char ch;
    //vector<pair<int,char>>r1,r2;
    map<char,vector<int> > mp1;
    set<int>myset;//its not muuultiset
    string s1;bool yes,lft,rt;
    multiset<string>lfts[100001],rts[100001];
    vector<pair<long long,long long> >v1,tmpv;
    char movx,movy;
    vector<int>vx[100001];
    int post[10000000][2];
    int t,sum2,y3,z3,mx2,mx;bool used;//))(())))
    bool hast[200001];
    int prevx,prevy;
    map<int,int>mymp,mymp2;
    vector<int>myst;
    string ss,s3;
    map<int,int>mpt;int nums[11],sums[11];

    int main()
    {

    ios_base::sync_with_stdio(false);

cin>>t;
while(t--){
    cin>>n;int mnlft=1e5,mnrt=-1e5,mnylft=mnlft,mnyrt=mnrt;yes=true;
    for(int i=0;i<n;i++)
    {
        cin>>b[i]>>c[i]>>a[0][i]>>a[1][i]>>a[2][i]>>a[3][i];
        if(a[2][i]==0)mnlft=min(mnlft,b[i]);
        if(a[0][i]==0)mnrt=max(mnrt,b[i]);
        if(a[1][i]==0)mnylft=min(mnylft,c[i]);
        if(a[3][i]==0)mnyrt=max(mnyrt,c[i]);
    }
    for(int i=0;i<n;i++)
    {
        x=b[i];y=c[i];//cout<<x<<" "<<mnlft<<" "<<mnrt<<endl;
        if(a[2][i]==0&&x<mnrt){yes=false;cout<<"0\n";break;}
        if(a[0][i]==0&&x>mnlft){yes=false;cout<<"0\n";break;}
        if(a[1][i]==0&&y<mnyrt){yes=false;cout<<"0\n";break;}
        if(a[3][i]==0&&y>mnylft){yes=false;cout<<"0\n";break;}
    }
    if(yes)cout<<"1 "<<min(mnlft,mnrt)<<" "<<min(mnylft,mnyrt)<<'\n';
    }


    return 0;
    }