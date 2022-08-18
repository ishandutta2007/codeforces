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

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh

#define  INF 100000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

/*
void build () {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2],t[v*2+1]);
    }
    for (int i=0;i<=300000;i++)
    t[i]=0;
    for (int i=0;i<=300000;i++)
    ans[i]=0;
    
}

int sum (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return max(sum (v*2, tl, tm, l, min(r,tm)),sum (v*2+1, tm+1, tr, max(l,tm+1), r));
}

void update (int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2],t[v*2+1]);
    }
}
*/

long long n,q,v[200000],c[200000],a,b,ans[200000],bsty,bstn,bp1,bp2,b1,b2;
long long answ;

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>q;

for (int i=0;i<n;i++)
cin>>v[i];
for (int i=0;i<n;i++)
cin>>c[i];


for (int test=0;test<q;test++)
{
 cin>>a>>b;
 for (int i=1;i<=n+5;i++)
 ans[i]=-1000000000ll*1000000000ll;
 
 bp1=1;bp2=2;
 b1=b2=ans[1];
 
 for (int i=0;i<n;i++)
 {
    if (bp1==c[i])bstn=b2; else bstn=b1;
    bsty=ans[c[i]];
    bstn+=b*v[i];
    bsty+=a*v[i];
   //if (bsty<-1000000000ll*10000)bsty=b*v[i];
    bstn=max(bstn,b*v[i]);
    bstn=max(bsty,bstn);
  //  cout<<bstn<<" "<<bsty<<" "<<b1<<" "<<b2<<" @@@ "<<endl;
    if (ans[c[i]]<bstn)
    {
                       ans[c[i]]=bstn;
                       if (bstn>b1)
                       {
                                   if (bp1==c[i])
                                   {b1=bstn;}
                                   else
                                   b2=b1;bp2=bp1;b1=bstn;bp1=c[i];
                       }
                       else
                       if (bstn>b2&&c[i]!=bp1)
                       {
                                   b2=bstn;bp2=c[i];
                       }
    }
  
 /*for (int i=1;i<=n;i++)
 cout<<ans[i]<<"  -  ";
 cout<<endl<<endl;   
 */
 }
 answ=0;
 for (int i=1;i<=n;i++)
 answ=max(answ,ans[i]);
 
 cout<<answ<<endl;
 
}

cin.get();cin.get();
return 0;}