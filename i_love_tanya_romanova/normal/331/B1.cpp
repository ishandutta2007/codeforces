/* 
I came into this world
A screaming infant
Forced entry into this life
As I grow the pain sustains
Deep inside my soul
Visions come and visions go
But hate will never leave me
As I grow the pain sustains
Deep inside my soul
Visions come and visions go
But hate will never leave me
Life and death never again
I shall not return
Soul sucking pious man
I shall not return
The reflection, an aging soul
My body's old and cracked
Death soon will be with me
Coldness, inactive pain
Soul sucked at the speed of light
Trapped in someone else
No please not again
Evil reincarnated
The cycle's spun once more
Soul sucked at the speed of light
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 0.001
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define clone agsdahfaassdg
using namespace std;

long n,ar[500000],ps[500000],q,tp,a,b,bd[500000],sb[500000];
long res,fb;

long gs(long v)
{
     fb=v/bsize;
     res=0;
     for (int i=0;i<fb;i++)
     res+=sb[i];
     for (int i=fb*bsize;i<=v;i++)
     res+=bd[i];
     return res;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>ar[i];
    ps[ar[i]]=i;
}

for (int i=2;i<=n;i++)
if (ps[i]<ps[i-1]){bd[i]=1;sb[i/bsize]++;}

cin>>q;
for (;q;--q)
{
    cin>>tp;
    if (tp==1)
    {
              cin>>a>>b;
              cout<<gs(b)-gs(a)+1<<endl;
    }
    else
    {
        cin>>a>>b;
        swap(ar[a],ar[b]);
        ps[ar[a]]=a;ps[ar[b]]=b;
        a=ar[a];b=ar[b];
        
        sb[a/bsize]-=bd[a];
        sb[b/bsize]-=bd[b];
        bd[a]=0;
        bd[b]=0;
        sb[(a+1)/bsize]-=bd[a+1];
        sb[(b+1)/bsize]-=bd[b+1];
        
        bd[a]=bd[b]=bd[a+1]=bd[b+1]=0;
        
        if (a>1&&ps[a]<ps[a-1])
        {
         bd[a]=1;sb[a/bsize]++;
        }
        if (a<n&&ps[a]>ps[a+1])
        {
         bd[a+1]=1;sb[(a+1)/bsize]++;
        }
        
        if (b>1&&ps[b]<ps[b-1])
        {
        sb[b/bsize]+=1-bd[b];bd[b]=1;
        }
        if (b<n&&ps[b]>ps[b+1])
        {
         sb[(b+1)/bsize]+=1-bd[b+1];bd[b+1]=1;
        }
    }
}

cin.get();cin.get();
return 0;}