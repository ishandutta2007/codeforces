// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;
#define f first

#define ll long long
const int s=1e9+7;
vector<int> p;

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
string ss,sway;int way[100];
int down,up,right1,left1;

map<int,int> nums;
bool a[2000001];
int main()
{
   ios_base::sync_with_stdio(false);
   cin>>n;
   for(int i=0;i<n;i++){cin>>x;nums[x]++;}
   auto it=nums.end();it--;
   for(it;;it--)
    {if(it->second%2)return cout<<"Conan",0;if(it==nums.begin())break;}
   cout<<"Agasa";


    return 0;
}