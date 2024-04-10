/*
I am but a farce, a satire of stability
Insecurity is an uphill struggle, it's me versus the world
The shore still starves,
For another,

Novel of my shipwrecked being tied up dried alive still breathing
The sands of time, from me are running out,
my hands shake, in apprehension,
Of every action I'm guilty of playing the victim,
The shore still starves,
For another,

Novel of my shipwrecked being tied up dried alive still breathing
The sands of time, for me are running out.

Just like the embrace of arms that made you
They'll surely destroy you.
Just like the embrace of arms that made you
They'll surely destroy you.

It's time for your panic,
Then it kills and makes, you manic,

Making its way inside - relax, it's alright,
Making its way inside - relax, it's alright
Panic grips your frantic breathing
I can't breathe, I can't breathe,i cant breathe!

Just like the embrace of arms that made you
They'll surely destroy you.
Just like the embrace of arms that made you
They'll surely destroy you.

Just like the embrace of arms that made you
They'll surely destroy you.
Just like the embrace of arms that made you
They'll surely destroy you.
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
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAGIC 47
#define count adsgasdgasdg

using namespace std;

long n,m,k;
string st,t;
char letter;
long ar[1<<20];
long lent;
long ans;
long good[1<<20];
long T[1<<20];
vector<int> v1,v2;

typedef complex<double> base;
int rev (int num, int lg_n) {
    int res = 0;
    for (int i=0; i<lg_n; ++i)
        if (num & (1<<i))
            res |= 1<<(lg_n-1-i);
    return res;
}
 
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
    int lg_n = 0;
    while ((1 << lg_n) < n)  ++lg_n;
 
    for (int i=0; i<n; ++i)
        if (i < rev(i,lg_n))
            swap (a[i], a[rev(i,lg_n)]);
 
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*M_PI/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1);
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}

vector<int> multiply (const vector<int> & a, const vector<int> & b) {
    vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    size_t n = 1;
    while (n < max (a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize (n),  fb.resize (n);
  vector<int> res;
    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);
 
    res.resize(n);
    for (size_t i=0; i<n; ++i)
        res[i] = int (fa[i].real() + 0.5);
        return res;
}

char gc(int x)
{
 if (x==0)
  return 'A';
 if (x==1)
  return 'C';
  if (x==2)
   return 'T';
   if (x==3)
    return 'G';
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
cin>>st;
cin>>t;
/*
for (int i=0;i<n;i++)
{
 st+=gc(rand()%4);
 t+=gc(rand()%4);
}*/

    
for (int iter=0;iter<4;iter++)
{
 if (iter==0)
  letter='A';
 else if (iter==1)
  letter='C';
  else if (iter==2)
   letter='T';
   else
   letter='G';
 for (int i=0;i<n;i++)
  ar[i]=1;
  lent=-1000000000;
 
 // tol 
 for (int i=0;i<st.size();i++)
 {
  if (st[i]==letter)lent=i;
  if (lent+k>=i)ar[i]=0;
 } 
 // tor
 lent=1000000000;
 for (int i=st.size()-1;i+1;--i)
 {
  if (st[i]==letter)lent=i;
  if (lent-k<=i)ar[i]=0;
 }
 
 // rev
 for (int i=0;i<n-i-1;i++)
 {
  swap(ar[i],ar[n-i-1]);
 }
 for (int i=0;i<n;i++)
 T[i]=0;
 
 for (int i=0;i<t.size();i++)
 {
  if (t[i]==letter)
   T[i]=1;
 }
 
/* for (int i=0;i<n;i++)
  cout<<ar[i]<<" ";
  cout<<endl;
  
 for (int i=0;i<n;i++)
  cout<<T[i]<<" ";
  cout<<endl;*/
 v1.clear();
 v2.clear();
 for (int i=0;i<n;i++)
 {
  v1.push_back(ar[i]);
  v2.push_back(T[i]);
 }
 vector<int> v3=multiply(v1,v2);
/* for (int i=0;i<v3.size();i++)
  cout<<v3[i]<<" ";
  cout<<endl;*/
 for (int i=0;i<n;i++)
 {
//  cout<<v3[i]<<" ";
  if (v3[i]==0)
   good[n-1-i]++;
 }
// cout<<endl;
// cout<<"%"<<endl;
}

for (int i=0;i<=(n-m);i++)
 if (good[i]==4)
 {
//  cout<<i<<endl;
  ++ans;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}