// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;

int x,cnt1,cnt2,k,n,m,t,d,sum,op;int ans=1e7, z;
int ho,mi,se;
void fix_time()
{   if(se>59)se-=60,mi++;if(se<0)se+=60,mi--;
    if(mi>59)mi-=60,ho++;if(mi<0)mi+=60,ho--;
    if(ho<0)ho+=24;if(ho>23)ho-=24;
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
int a,b,cnt3;char st[200000];vector<int> gr;string str;
int conv(string tmp)
{int num=0;int os=1;
    for(int i=tmp.size()-1;i>=0;i--)num+=os*(int(tmp[i])-48),os*=10;
    return num;

}
string tobin(int x)
{    string tmp;
    int siz=int(log2(x))+1;
    for(int i=0;i<siz;i++){if(x&1)tmp+='1';else tmp+='0';x/=2;}
    return tmp;
}
int main()
{
ios_base::sync_with_stdio(false);

       cin>>str;int len=str.size();
       for(int i=1;i*i<=2e9;i++)
        gr.push_back(i*i);int pos=my_pow(2,len);
        for(int i=1;i<=pos;i++)
        {   string comp=tobin(i);
            string tmp1="";z=0;
            for(int j=0;j<comp.size();j++)if(comp[j]=='1')tmp1+=str[j];
            string tmp="";
            while(tmp1[z]=='0')z++;
            for(;z<tmp1.size();z++)tmp+=tmp1[z];

           int tp=conv(tmp);int len2=tmp.size();
            int tst=*lower_bound(gr.begin(),gr.end(),tp);
            if(tst==tp)ans=min(ans,len-len2);
        }
         if(ans>30)ans=-1; cout<<ans;

    return 0;
}