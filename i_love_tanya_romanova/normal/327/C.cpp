/*
This is the end of all life's suffering
This is the end of all life's pain
Fear, destruction, greed, exists no longer
Nothings left now nothing can remain

It's getting closer
Follow my friend
Endorama is crushing you
This is the end
Expect no mercy
Just understand
Endorama comes for you
This is the end

This is the end of your false paradise
This is the end of mankinds pride
Masques of selfishness needed no longer
All forgotten dark illusions died

It's getting closer
Follow my friend
Endorama is crushing you
This the end
Expect no mercy
Just understand
Endorama comes for you
This is the end

As long as you're alive you've got to suffer
Death will take you from this labyrinth
Open up you'll see
This life just can't be real
Don't look back just let it all go
Into eden or inferno

This is the end of all your struggling
This is the end of this domain
Hate, regression, lies, exist no longer
As earth becomes the epitaph of cain

It's getting closer
Follow my friend
Endorama is crushing you
This is the end
Expect no mercy
Just understand
Endorama comes for you
This is the end
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define N 4000005
using namespace std;

string st;
long long n,k,t;
long long pw(long long a,long long b)
{
     if (b==0)return 1;
     if (b%2==0)return pw(a*a%bs,b/2)%bs;
     return a*pw(a,b-1)%bs;
}

long long inv(long long q)
{
 return pw(q,1000000005);
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
cin>>k;
long long ans=0;
t=pw(2,st.size()*k);
t-=1;t+=bs;
t%=bs;
//cout<<t<<endl;
t*=inv(pw(2,st.size())-1);
t%=bs;
//cout<<t<<endl;

for (int i=0;i<st.size();i++)
if (st[i]==48||st[i]==53)ans+=pw(2,i)*t%bs;
cout<<ans%bs<<endl;

cin.get();cin.get();
return 0;}