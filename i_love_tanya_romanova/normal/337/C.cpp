/*
Now I see his face, I've seen him smile
Such in a lonely place, no golden mile
His eyes tell morbid tales, of his black heart
His deeds through ages past, tell of his part

See his face, see his smile
Time to die

An angel from below, change my dreams
I want for glory's hour, for wealth's esteem
I wish to sell my soul, to be reborn
I wish for earthly riches, don't want no crown of thorns

See his face, see his smile
Time to die

I was born a fool, don't want to stay that way
Devil take my soul, with diamonds you repay
I don't care for heaven, don't you look for me to cry
And I will burn in Hell, from the day I die

See his face, see his smile
Time to die
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 4
#define ttl 4888888
#define clone agsdahfaassdg

using namespace std;

long long n,m,k,l,r,mid;
long long gans,ques;

bool can(long bblocks)
{
 long long last,hgood;
 
// if (bblocks*k>n)return false;
// if (bblocks*k>m)return false;
 gans=m;
 ques=n;
 gans-=bblocks*k;
 ques-=bblocks*k;
// cout<<bblocks<<" "<<gans<<" "<<ques<<endl;
 
 
 last=ques%k;
 
 hgood=ques/k*(k-1);
 hgood+=last;
 //cout<<bblocks<<" "<<hgood<<" "<<gans<<endl;
 if (hgood>=gans)return true;
 return false;
}

long long pw(long long a,long long b)
{ 
     if (b==0)return 1;
     if (b&1)return (a*pw(a,b-1))%bs;
     return pw(a*a%bs,b/2);
}

long long solve(long long blocks)
{
 long long res=0;
 
 /*long long res1=0;
 
 for (int i=1;i<=blocks;i++)
 res1=(res1+k*pw(2,i))%bs;
 */
 long long aa=pw(2,blocks+1);
 aa--;--aa;
 if (aa<0)aa+=bs;
 res=aa*k%bs;
 
/* for (int i=1;i<=blocks;i++)
 {res=(res+k)*2;}
 */
 //cout<<res<<" "<<res1<<endl;
 //cout<<res<<endl;
 res+=m-blocks*k;
 res%=bs;
 return res;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

long x;
/*cin>>x>>k;
cout<<solve(x)<<endl;
*/
cin>>n>>m>>k;

long l,r;

l=0;
r=n;
while (l<r)
{
      mid=l+r;
      mid/=2;
   //   cout<<l<<"  "<<r<<" "<<mid<<endl;
      if (can(mid)){r=mid;} else l=mid+1;

}
//cout<<l<<endl;
//cout<<l<<endl;
cout<<solve(l)<<endl;

cin.get();cin.get();
return 0;}