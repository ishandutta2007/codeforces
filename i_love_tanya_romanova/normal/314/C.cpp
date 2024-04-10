/*
     .
  ?   .
- ,  ,
      .
  !
   
  !..
 ,    .
    ,
  ,   ,   

:
   ,
    
     !
   ,
       ,
    ,   !

,  ,   ,
  ,    .
   ,
    ,  !
  
  !
  !
    ,
    ,
  ,   ,   

.

  ,   ,
     .
  ,   ,
       .

. (2)
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
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long t[5000000];
long long n,q,res,qurr;
long long temp;

long long sum (long long v, long long tl, long long tr, long long l, long long r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v]%bs;
  long long tm = (tl + tr) / 2;
    return (sum (v*2, tl, tm, l, min(r,tm))
        + sum (v*2+1, tm+1, tr, max(l,tm+1), r))%bs;
}

void update (long long v,long long tl,long long tr, long long pos,long long new_val) {
    if (tl == tr)
        t[v] = new_val%bs;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
        if (t[v]>=bs)t[v]-=bs;
    }
}


int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;

update(1,0,(1<<20)-1,0,1);

for (int i=1;i<=n;i++)
{
    cin>>q;
    res=sum(1,0,(1<<20)-1,0,q-1);
    res=res*q%bs;
    
    temp=sum(1,0,(1<<20)-1,q,q);
    update(1,0,(1<<20)-1,q,0);
    
   //cout<<res<<" "<<temp<<endl;
    res+=temp*q%bs;
    res%=bs;
    update(1,0,(1<<20)-1,q,res);
}
res=sum(1,0,(1<<20)-1,1,1000000);
cout<<res%bs<<endl;

cin.get();cin.get();
return 0;}