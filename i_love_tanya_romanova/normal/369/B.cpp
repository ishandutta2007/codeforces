/*
Never hunger 
Never prosper 
I have fallen prey to failure 

Struggle within 
Triggered again 
Now the candle burns at both ends 

Twisting under schizophrenia 
Falling deep into dementia 

Old habits reappear 
Fighting the fear of fear 
Growing conspiracy 
Everyone's after me 
Frayed ends of sanity 
Hear them calling 
Hear them calling me 

Birth of terror 
Death of much more 
I'm the slave of fear, my captor 

Never warnings 
Spreading it's wings 
As I wait for the horror she brings 

Loss of interest, question, wonder 
Waves of fear, they pull me under 

Old habits reappear 
Fighting the fear of fear 
Growing conspiracy 
Everyone's after me 
Frayed ends of sanity 
Hear them calling 
Hear them calling me 

Into ruin, I am sinking 
Hostage of this nameless feeling 

Hell is set free 
Flooded I'll be 
Feel the undertow inside me 

Height, hell, time, haste, terror, tension 
Life, death, want, waste, mass depression 

Old habits reappear 
Fighting the fear of fear 
Growing conspiracy 
Myself is after me 
Frayed ends of sanity 
Hear them calling 
Frayed ends of sanity 
Hear them calling 
Hear them calling me
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
//#include <memory.h>

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
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,k,l,r,sa,sb,dwn,ta,tb,sk,ans[20000];

int main(){
//freopen("virus.in","r",stdin);
//freopen("virus.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k>>l>>r>>sa>>sk;

dwn=sa-sk;

if (n!=k)
{
 ta=dwn/(n-k);
 tb=dwn%(n-k);
for (int i=1;i<=n-k;i++)
{
    if (i<=tb)ans[i]=ta+1;
    else ans[i]=ta;
}
}

ta=sk/k;
tb=sk%k;

for (int i=1;i<=k;i++)
{
 if (i<=tb)ans[n-k+i]=ta+1;
 else ans[n-k+i]=ta;
}
for (int i=1;i<=n;i++)
{
    if (i-1)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}