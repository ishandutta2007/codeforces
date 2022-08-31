//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 201004
//#define szz 400
//#define pb push_back
using namespace std;

long n,m,e,ppp,h,q,w,a[210000],b[210000],aa,bb,usd[210000];

set <long> s[1000];

string tp;
long long ans;

long gcd(long a,long b)
{while (a&&b)a>b?a%=b:b%=a;
return a+b;
 }
 
int main(){
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin>>h>>m>>n;
map <long,long> ss,sss;
set<long> ::iterator it;

q=gcd(h,m);
if (q>100)
{

for (int i=0;i<n;i++)
{
    cin>>tp;
    if (tp=="+")
    {
     cin>>w>>e;
//     if (usd[e]==1)ans++;
     q=e;
     while (usd[q]==1)
     {ans++;q=q+m;if (q>=h)q-=h;}
     ss[w]=q;
     usd[q]=1;
                }
    else
    {
        cin>>w;
        usd[ss[w]]=0;
    }
}
}

else

{
 for (int i=0;i<q;i++)
 {
     for (int j=0;j<h/q;j++)
     {
         a[(i+1ll*j*m)%h]=i;
         b[(i+1ll*j*m)%h]=j;
     }
 }    
 
 for (int i=0;i<q;i++)
 for (int j=0;j<h/q;j++)
 {
     s[i].insert(j);
     s[i].insert(j+h/q);
 }
 
 
for (int i=0;i<n;i++)
{
    cin>>tp;
    if (tp=="+")
    {
     cin>>w>>e;
     aa=a[e];
     bb=b[e];
     
     --bb;
     it=s[aa].upper_bound(bb);
     ans+=(*it)-bb-1;
     ppp=*it;if (ppp>=h/q)ppp-=h/q;
     ss[w]=ppp;sss[w]=aa;
     s[aa].erase(ppp);
     s[aa].erase(ppp+h/q);
     }
    else
    {
        cin>>w;
        aa=sss[w];
        bb=ss[w];
        
   //  cout<<aa<<" "<<bb<<" "<<ss[w]<<endl;
     s[aa].insert(bb);
     s[aa].insert(bb+h/q);
        
    }
    //cout<<ans<<endl;
}
 
}

cout<<ans<<endl;
cin.get();cin.get();
return 0;}