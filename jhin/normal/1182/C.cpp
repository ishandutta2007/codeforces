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
bool chck(char d)
{
    if(d=='o'||d=='i'||d=='u'||d=='a'||d=='e')return true;
    return false;
}
int m,x,n,y,z,x1,k,one,gd,x2,y2,two,mn=1e9,mid,l,r,pos,a[500003],b[500003],c[500000],c2[500000],dd[100];string s2;vector<string>v[1000003];long long sum,ans,num;
bool yes;int t;
multiset<pair<int,int> > df;
map<char ,multiset<pair<int,string> > > mp;
set<int>myset;//its not muuultiset
string s[1000003];
vector<string>v1,v2;

int main()
{

ios_base::sync_with_stdio(false);
cin>>n;
for(int i=0;i<n;i++)cin>>s[i];
for(int i=0;i<n;i++)
{
    int tmp=-1;x=0;
    for(int j=s[i].size()-1;j>=0;j--)if(chck(s[i][j])){if(tmp==-1)tmp=j;x++;}
    if(tmp!=-1)mp[s[i][tmp]].insert({x,s[i]});

}
for(char c='a';c<='z';c++)
{

    for(auto it=mp[c].begin();it!=mp[c].end();)
    {
        int x=(*it).first;
        auto it2=mp[c].lower_bound({x+1,"a"});
        it2--;if(it2!=it){auto it3=it;it++;if(it2==it)it++;
        v2.push_back((*it3).second);v2.push_back((*it2).second);
        mp[c].erase(it3);mp[c].erase(it2);
    }
    else it++;

}}
for(char c='a';c<='z';c++)
{

    for(auto it=mp[c].begin();it!=mp[c].end();it++)
    {
        int tmp=(*it).first;
        v[tmp].push_back((*it).second);


    }

}
for(int i=1;i<=1000000;i++)
{
    int tmp=v[i].size();if(tmp%2)tmp--;
    for(int j=0;j<tmp;j++)v1.push_back(v[i][j]);
}
while(v2.size()>v1.size()+3){v1.push_back(*(--v2.end()));v2.erase(--v2.end());v1.push_back(*(--v2.end()));v2.erase(--v2.end());}
x=v1.size();y=v2.size();
int siz=min(x/2,y/2)*2;
cout<<min(x/2,y/2)<<endl;
for(int i=0;i<siz;i++)cout<<v1[i]<<" "<<v2[i]<<'\n';
return 0;
}