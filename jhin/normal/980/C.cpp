// system.cout(translate *from glut);
#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define f for(int i=0;i<n;i++)
const int mod=1e9+7;
vector<int> p;


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

int n,x,y,m,cnt1,k,cnt2,a[100001],b[100001];string s;set<pair<int,int>>grp;
int main()
{
ios_base::sync_with_stdio(false);

   cin>>n>>k;
   for(int i=0;i<n;i++)
    cin>>a[i];
    b[0]=max(0,a[0]-k+1);grp.insert(make_pair(b[0],a[0]));
   for(int i=1;i<n;i++)
       {bool found=false;
           for(auto j=grp.begin();j!=grp.end();j++)
            if(a[i]>=(*j).first&&a[i]<=(*j).second)b[i]=(*j).first,found=true;
            if(!found)
           {auto j=grp.begin();
           while(a[i]>(*j).first&&j!=grp.end())j++;
           if(j==grp.begin())b[i]=max(a[i]-k+1,0),grp.insert(make_pair(b[i],a[i]));
            else
           {j--;int tmp=(*j).first;
           if(a[i]-k+1<=tmp){b[i]=tmp;grp.erase(j);grp.insert(make_pair(tmp,a[i]));}
           else {b[i]=max(a[i]-k+1,(*j).second+1);grp.insert(make_pair(b[i],a[i]));}
           }
           }
       }
//for(auto j=grp.begin();j!=grp.end();j++)cout<<(*j).first<<" "<<(*j).second<<endl;
for(int i=0;i<n;i++) cout<<b[i]<<" ";
    return 0;
}