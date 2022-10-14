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
    if(ho<0)ho+=24;if(ho>24)ho-=24;
}
long long my_pow(int x,int y)
{    long long num=1;
    for(long long i=x;y>0;i=(i*i),y>>=1)
        if(y&1)num=(num*i);
    return num;
}

bool prime[16000003];
void sieve(){
    for(int i=2;i<=16000000;i+=2)
        prime[i]=false,prime[i-1]=true;
    prime[2]=true;
    for(int i=3;i<=4000;i+=2)
        if(prime[i])
            for(int j=i*i;j<=16000000;j+=2*i)
                prime[j]=false;
}


int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int m,x,n,y,z,k,mx,one,gd,two,mn=1e9,l,r,pos,t,a[300003];string s,s2;vector<int>v2;long long ans,num,num2,num3;char ch;
vector<pair<int,int>>r1,r2;char chrs[1006][1006];bool used=false;

bool check(int x,int y)
{ bool see=true;
if(chrs[x][y]=='.')see=false;
    for(int i=x;i<x+3;i++)//
        for(int j=y;j<y+3;j++)
        if(i!=x+1||j!=y+1)if(chrs[i][j]!='#')see=false;
        if(see&&!used)r1.push_back(make_pair(x+1,y+1));
        //if(see)cout<<"left top  "<<x<<" "<<y<<" "<<chrs[x+1][y]<<endl;
    if(!see)
    {  see=true;
    if(chrs[x][y]=='.')see=false;
        for(int i=x;i<x+3;i++)//
        for(int j=y-1;j<y+2;j++)
        if(i!=x+1||j!=y)if(chrs[i][j]!='#')see=false;
        if(see&&!used)r1.push_back(make_pair(x+1,y));
        //if(see)cout<<"middle top  "<<x<<" "<<y<<endl;
    }
    if(!see)
      {  see=true;
      if(chrs[x][y]=='.')see=false;
        for(int i=x;i<x+3;i++)//
        for(int j=y-2;j<y+1;j++)
        if(i!=x+1||j!=y-1)if(chrs[i][j]!='#')see=false;
        if(see&&!used)r1.push_back(make_pair(x+1,y-1));
        //if(see)cout<<"right top  "<<x<<" "<<y<<endl;
    }
    if(!see){
     see=true;
     if(chrs[x][y]=='.')see=false;
    for(int i=x-1;i<x+2;i++)//
        for(int j=y;j<y+3;j++)
        if(i!=x||j!=y+1)if(chrs[i][j]!='#')see=false;
       if(see&&!used)r1.push_back(make_pair(x,y+1));
       //if(see)cout<<"left middle  "<<x<<" "<<y<<endl;
       }

       if(!see)
      {
          see=true;
          if(chrs[x][y]=='#')see=false;
        for(int i=x-1;i<x+2;i++)//
        for(int j=y-1;j<y+2;j++)
        if(i!=x||j!=y)if(chrs[i][j]!='#')see=false;
        //if(see)cout<<"middle middle  "<<x<<" "<<y<<endl;
        //if(see&&!used)r1.push_back(make_pair(x,y));
    }
    if(!see)
      {  see=true;
      if(chrs[x][y]=='.')see=false;
        for(int i=x-1;i<x+2;i++)//
        for(int j=y-2;j<y+1;j++)
        if(i!=x||j!=y-1)if(chrs[i][j]!='#')see=false;
        if(see&&!used)r1.push_back(make_pair(x,y-1));
        //if(see)cout<<"right middle  "<<x<<" "<<y<<endl;
    }
    if(!see){
     see=true;
     if(chrs[x][y]=='.')see=false;
    for(int i=x-2;i<x+1;i++)//
        for(int j=y;j<y+3;j++)
        if(i!=x-1||j!=y+1)if(chrs[i][j]!='#')see=false;
        if(see&&!used)r1.push_back(make_pair(x-1,y+1));
        //if(see)cout<<"left bot  "<<x<<" "<<y<<endl;
        }
    if(!see)
    {  see=true;
    if(chrs[x][y]=='.')see=false;
        for(int i=x-2;i<x+1;i++)//
        for(int j=y-1;j<y+2;j++)
        if(i!=x-1||j!=y)if(chrs[i][j]!='#')see=false;
        if(see&&!used)r1.push_back(make_pair(x-1,y));
        //if(see)cout<<"middle bot  "<<x<<" "<<y<<endl;
    }
    if(!see)
      {  see=true;
         if(chrs[x][y]=='.')see=false;
        for(int i=x-2;i<x+1;i++)
        for(int j=y-2;j<y+1;j++)
        if(i!=x-1||j!=y-1)if(chrs[i][j]!='#')see=false;
        if(see&&!used)r1.push_back(make_pair(x-1,y-1));
        //if(see)cout<<"right bot  "<<x<<" "<<y<<endl;
    }
    return see;
}
int main()
{
ios_base::sync_with_stdio(false);
cin>>n>>m;
for(int i=0;i<1005;i++)for(int j=0;j<1005;j++)chrs[i][j]='.';
for(int i=2;i<=n+1;i++)
for(int j=2;j<=m+1;j++)cin>>chrs[i][j];


 for(int i=2;i<=n+1;i++)
        for(int j=2;j<=m+1;j++)
        if(chrs[i][j]=='#')
 {
     if(!check(i,j))return cout<<"NO",0;
 }
 used=true;
 for(auto it=r1.begin();it!=r1.end();it++)
 {int i=(*it).first;
 int j=(*it).second;
 //cout<<i<<" "<<j<<endl;
     if(!check(i,j))return cout<<"NO",0;

 }
cout<<"YES";
return 0;
}