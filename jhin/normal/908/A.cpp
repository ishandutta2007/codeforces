// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;
#define f first

#define ll long long
const int s=1e9+7;
vector<int> p;
map<int,int> factors;
int n,i,b,c,d,x,y,del,cnt1,cnt2,max1,max2,sum;
ll my_pow(int x,int y)
{    ll num=1;
    for(ll i=x;y>0;i=(i*i)%s,y>>=1)
        if(y&1)num=((num%s)*i)%s;
    return num%s;
}
void pfact(int x)
{   if(x%2==0){p.push_back(2);while(x%2==0)x/=2;}
    for(int i=3;i*i<=x;i+=2)
        if(x%i==0){p.push_back(i);while(x%i==0)x/=i;}
    if(x>1)p.push_back(x);
}
string ss;

int main()
{
   ios_base::sync_with_stdio(false);
   cin>>ss;
   for(int i=0;i<ss.size();i++)
    {if(ss[i]=='e'||ss[i]=='a'||ss[i]=='u'||ss[i]=='o'||ss[i]=='i')cnt1++;
    int x=ss[i];
    if(x>47&&x<59&&x%2)cnt1++;}
   cout<<cnt1;
    return 0;
}