// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
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
{    ll num=1;
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


int n,l,r,x,y,m,k,ans,a[100003];vector<int>b;
vector<int>kh;string txt;

string rev(string x)
{string y="";int si=x.size();
    for(int i=si-1;i>=0;i--)
        y+=x[i];
        return y;
}
string take(string x,int j)
{
  string y="";
  for(int i=0;i<j;i++)y+=x[i];
  return y;
}
void fix(int j,string y)
{
    for(int i=0;i<j;i++)txt[i]=y[i];
}

int main()
{
ios_base::sync_with_stdio(false);
  cin>>n;
  for(int i=2;i<=n;i++)if(n%i==0)kh.push_back(i);
  cin>>txt;
  for(int i=0;i<kh.size();i++)
  {
      string tmp=take(txt,kh[i]);
      tmp=rev(tmp);
      fix(kh[i],tmp);
  }
  cout<<txt;

return 0;
}