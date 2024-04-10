// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;



#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;


int ho,mi,se;
void fix_time()
{   if(se>59)mi+=se/60,se=se%60;if(se<0)se+=60,mi--;
    if(mi>59)ho+=mi/60,mi=mi%60;if(mi<0)mi+=60,ho--;
    //if(ho<0)ho+=24;if(ho>24)ho-=24;
}
int my_pow(int x,int y)
{    long long num=1;
    for(int i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=((num)*i);
    return num;
}

bool prime[1000001];
void sieve(){
    for(int i=2;i<=1000000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i<=1000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=1000000;j+=2*i)
                prime[j]=false;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}


long long l,r,x,y,ans,a[200003];vector<int>b;long long n,m,k;
vector<int>kh;string txt;
multiset<pair<long long,int>>rem;
int main()
{
ios_base::sync_with_stdio(false);
cin>>n>>m;int nn=int(n);
for(int i=0;i<nn;i++){cin>>a[i];rem.insert(make_pair(a[i]%m,i));}
k=n/m;

for(long long i=0;i<m;i++)
{
    for(long long j=0;j<k;j++)
    {long long ad=0;
        auto it=rem.lower_bound({i,0});
        if((*it).first>i&&it!=rem.begin())it--;
        long long tmpval=(*it).first;
        int tmppos=(*it).second;
        //cout<<tmpval<<" "<<tmppos<<endl;
        if(tmpval<=i&&it!=rem.end()){ad=i-tmpval;
        a[tmppos]+=ad;ans+=ad;
        rem.erase(it);
        }
        else
        {  it=rem.lower_bound({0,0});
        if((*it).first!=0)
            it=--rem.end();
         tmpval=(*it).first;
         tmppos=(*it).second;
            ad=tmpval%m;
            if(tmpval)ad=m-tmpval;
            ad+=i;
            a[tmppos]+=ad,ans+=ad;
        rem.erase(it);

        }

            }

}
cout<<ans<<endl;
            for(int i=0;i<nn;i++)cout<<a[i]<<" ";
return 0;
}