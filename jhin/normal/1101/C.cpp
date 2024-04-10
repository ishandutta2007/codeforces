// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;




const int mod=1e9+7;
vector<long long> p;


int ho,mi,se;
void fix_time()
{   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
    if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>24)ho-=24;
}
long long my_pow(int x,int y)
{    long long num=1;
    for(long long i=x;y>0;i=(i*i),y>>=1)
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
vector<int>vv;int cnt=0;
void pfact(long long x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2,cnt++;vv.push_back(cnt);}
    for(long long i=3;i*i<=x;i+=2)
        if(x%i==0){cnt=0;p.push_back(i);while(x%i==0)x/=i,cnt++;vv.push_back(cnt);}
    if(x>1)p.push_back(x),cnt++,vv.push_back(1);
}
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,k,mx,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500000];string s2;vector<int>v,v2[100003];long long sum,ans,num;char ch;
//vector<pair<int,char>>r1,r2;
map<string,int> mp1;
set<int>myset;
string s,s1;int tmp;bool yes,lft,rt;
multiset<string>lfts[100001],rts[100001];


int t,sum2,y3,z3;bool used;//))(())))
int main()
{

ios_base::sync_with_stdio(false);
cin>>t;
while(t--)
{
    cin>>n;bool res[n];
    memset(res,0,n);
    vector<pair<pair<int,int>,int> > myvec;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        myvec.push_back({{y,x},i});
    }

    sort(myvec.begin(),myvec.end());
    int ind=myvec[0].second;
    int beg=myvec[0].first.second;
    int en=myvec[0].first.first;
    res[ind]=true;
    vector<int>shits;
    for(int i=1;i<n;i++)
    {
        m=i;
        int f=myvec[i].first.first;
        int se=myvec[i].first.second;
        ind=myvec[i].second;
        if(en>=se){if(beg>se)beg=se;
                   en=f;
                shits.push_back(ind);
                for(int j=0;j<shits.size();j++)res[shits[j]]=true;
                shits.clear();
                }
        else shits.push_back(ind);

    }

    yes=false;
    for(int i=0;i<n;i++)if(!res[i])yes=true;
   if(yes) for(int i=0;i<n;i++)if(res[i])cout<<"1 ";else cout<<"2 ";
   else cout<<-1;
    cout<<endl;

}
return 0;
}