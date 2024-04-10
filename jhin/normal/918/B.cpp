// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
const int mod=1e9+7;
vector<int> p;

ll n,x,y,sum,cnt1,cnt2,m;
string s1,s2;
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%mod,y>>=1)
        if(y&1)num=((num%mod)*i)%mod;
    return num%mod;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
string strings[1000];

map<string,string>m2;
string m1[1000];
int main()
{
   ios_base::sync_with_stdio(false);
   cin>>n>>m;
   for(int i=0;i<n;i++)
    {cin>>s1>>s2;
   m2[s2+';']=s1;}
   for(int i=0;i<m;i++)
    {cin>>s1>>s2;strings[i]=s1;m1[i]=s2;
   }

   for(int i=0;i<m;i++)
    cout<<strings[i]<<" "<<m1[i]<<" #"<<m2[m1[i]]<<endl;




    return 0;
}