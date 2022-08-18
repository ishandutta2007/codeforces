/*
Alone is to feel death crawling beneath your skin
We must remember the dead
I look down to the ground before me
Worried no longer, we were free for the first time
Now more lonely than we ever been
Around the fire we wonder; if they are alone as we are
The lonely dead lonely
Alone is to feel death crawling beneath your skin
We must remember the dead
Around the fire we wonder; if they are alone as we are
The lonely dead lonely
Dead we are the lonely dead, dead we are the lonely dead
When we speak we speak of the new age
And we realize the dead
Our lives in the ruin of change
Our first choice was to bury them
Our first choice was to bury them
Dead we are the lonely dead, dead we are the lonely dead
When we speak we speak of the new age
And we realize the dead
Our lives in the ruin of change
Dead we are the lonely dead, dead we are the lonely dead
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int tests;
long long l,r;
vector<long long> digs;

char was[20][200][2522];
long long memo[20][200][2522];
int T;
int mp[5000];
int LC[2522][11];
int mov[2522][11];

int states;

int gcd(int a,int b)
{
    while (a&&b)a>b?a%=b:b%=a;
    return a+b;
}

int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

long long dfs(int ps,int lcm,int rem)
{
    ++states;
    
    if (was[ps][mp[lcm]][rem]==T)
        return memo[ps][mp[lcm]][rem];
    
    was[ps][mp[lcm]][rem]=T;
    
    if (ps==19)
    {
        memo[ps][mp[lcm]][rem]=(rem%lcm==0);
    //  cout<<ps<<"   "<<lcm<<" "<<rem<<" "<<smal<<endl;
        if (rem%lcm)return 0;
        return 1;
    }
    
    long long res=0;
    for (int dig=0;dig<10;dig++)
    {
        int nlcm,nrem,nsmal;
        nlcm=lcm;
        nrem=rem;
        if (dig>0)
            nlcm=LC[nlcm][dig];
    /*  if (nlcm==0)
            cout<<"@"<<lcm<<" "<<dig<<endl;
    */      
        nrem=mov[rem][dig];
//      nrem=rem*10+dig,nrem%=2520;
        res+=dfs(ps+1,nlcm,nrem);
    }
    
    memo[ps][mp[lcm]][rem]=res;
    return res;
}

long long check(long long x)
{
    long long flag=0;
    long long n=x;
    while (x)
    {
        long long rem=x%10;
        x/=10;
        if (rem>0&&n%rem>0)
            return 0;
    }
    return 1;
}

long long solve(long long x)
{
    if (x==0)return 0;
    digs.clear();
    
    long long X=x;
    
    for (int i=1;i<=19;i++)
    {
        digs.push_back(x%10);
        x/=10;
    }
    reverse(digs.begin(),digs.end());
    
    ++T;
    long long res=0;
    
    for (int pref=0;pref<19;pref++)
    {
        long long L=1;
        long long rem=0;
        for (int i=0;i<pref;i++)
        {
            if (digs[i]>0)
            {
                L=lcm(L,digs[i]);
            }
            rem=rem*10+digs[i];
            rem%=2520;
        }
        for (int nw=0;nw<digs[pref];nw++)
        {
            int nL=L;
            if (nw)
                nL=lcm(nL,nw);
            int nrem=rem*10+nw;
            nrem%=2520;
            res+=dfs(pref+1,nL,nrem);
        //  cout<<nw<<" "<<pref<<" "<<res<<" "<<nL<<" "<<nrem<<" "<<rem<<endl;
        }
    }
    if (X>0)res+=check(X);
    --res;
//  cout<<"@"<<res<<endl;
    return res;
}

long long brute(long long r)
{
    long long res=0;
    for (int i=1;i<=r;i++)
        if (check(i))++res;
    return res;
}
int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for(int i=0;i<=2520;i++)
    for (int j=1;j<=9;j++)
    {
        LC[i][j]=lcm(i,j);
    }

for (int i=0;i<=2520;i++)
    for (int j=0;j<10;j++)
        mov[i][j]=(i*10+j)%2520;
        
vector<int> dif;
for (int mask=0;mask<512;mask++)
{
    int res=1;
    for (int i=0;i<9;i++)
        if (mask&(1<<i))
            res=lcm(res,i+1);
    dif.push_back(res);
}

int cnt=0;
sort(dif.begin(),dif.end());
for (int i=0;i<dif.size();i++)
{
    if (i==0||dif[i]!=dif[i-1])
        {
            mp[dif[i]]=cnt++;
//          ++cnt;
//          cout<<mp[dif[i]]<<" % "<<dif[i]<<endl;
        }
}

cin>>tests;
for (;tests;--tests)
{
    cin>>l>>r;
    cout<<solve(r)-solve(l-1)<<endl;
    //cout<<brute(r)-brute(l-1)<<endl;
    //0cout<<states<<endl;
}

//cin.get();cin.get();
return 0;}