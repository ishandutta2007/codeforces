/*
You lived the life you dreamed the dream
You built the wall that stands between
Blocked out the light that gave you hope
Withdrew your words before you spoke
You watched the world slip out of your hands

And you laughed and you cried
And that made it all worthwhile
And you hoped and you prayed
That your world would never change
But all that it's become 
Is Avalon

You made your home where kings have died
There's no romance now you've seen the light
You thought you'd found the land of dreams
Sometimes a paradise is not what it seems
You watched the world slip out of your hands

And you laughed and you cried
And that made it all worthwhile
And you hoped and you prayed
That your world would never change
But all that it's become 
Is Avalon

All that remains are memories and lies
Nothing stays the same

And you laughed and you cried
And that made it all worthwhile
And you hoped and you prayed
That your world would never change
But all that it's become 
Is Avalon
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
//#define bs 1000000007
#define bsize 256

using namespace std;

long long bs;
long long n,k,l,p,ans;

long long pw(long long a,long long b)
{
    if (b==0)return 1;
    if (b%2) return a*pw(a,b-1)%bs;
    return pw(a*a%bs,b/2);
}

vector<vector<long long> > one()
{
    vector< vector<long long> > res;
    res.resize(2);
    res[0].resize(2);
    res[1].resize(2);
    for (int i=0;i<2;i++)
     for (int j=0;j<2;j++)
      res[i][j]=(i==j);
    return res;
}

vector<vector<long long> > mult(vector<vector<long long> > a,vector<vector<long long> > b)
{
    vector<vector<long long> > res=one();
    for (int i=0;i<res.size();i++)
     for (int j=0;j<res[i].size();j++)
      res[i][j]=0;
    for (int k=0;k<2;k++)
     for (int i=0;i<2;i++)
      for (int j=0;j<2;j++)
       res[i][j]+=(a[i][k]*b[k][j]),
       res[i][j]%=bs;
    return res;
}
vector<vector<long long> > fib;

vector<vector<long long> > pw(vector<vector<long long> > a,long long b)
{
    if (b==0) return one();
    if (b%2) return mult(a,pw(a,b-1));
    return pw(mult(a,a),b/2);
}

void show (vector<vector<long long> > v)
{
    for (int i=0;i<v.size();i++)
    {
        for (int j=0;j<v[0].size();j++)
         cout<<v[i][j]<<" ";
        cout<<endl;
    }
}

long long get_fib(long long x)
{
    vector<vector<long long> > v=pw(fib,x);
//  cout<<"^"<<x<<endl;
//  show(v);
    return v[0][1];
}

long long solve1(long long x)
{
    return get_fib(x+2);
}
long long solve2(long long x)
{
    return (pw(2,x)-get_fib(x+2)+bs)%bs;
}

int main(){
//freopen("towers.in","r",stdin);
//freopen("towers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k>>l>>bs;

fib=one();
fib[1][0]=fib[0][1]=1;
fib[1][1]=0;
ans=1;
for (int i=0;i<l;i++)
{
    if (k&(1ll<<i))
        ans*=solve2(n);
    else ans*=solve1(n);
    ans%=bs;
}
for (int i=l;i<60;i++)
 if (k&(1ll<<i))
    ans=0;
    
cout<<ans%bs<<endl;

//cin.get();cin.get();
return 0;}