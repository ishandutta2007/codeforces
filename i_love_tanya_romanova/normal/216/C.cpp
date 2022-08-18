/*
Here they stand brothers them all
All the sons divided they'd fall
Here await the birth of the son
The seventh, the heavenly, the chosen one.

Here the birth from an unbroken line
Born the healer the seventh, his time
Unknowingly blessed and as his life unfolds
Slowly unveiling the power he holds

[Chorus:]
Seventh son of a seventh son [x8]

Then they watch the progress he makes
The Good and the evil which path will he take
Both of them trying to manipulate
The use of his powers before it's too late

[Chorus]

Today is born the seventh one
Born of woman the seventh son
And he in turn of a seventh son
He has the power to heal
He has the gift of the second sight
He is the chosen one
So it shall be written
So it shall be done
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
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long n,m,k,w[100000];
vector<long long> ans;
long long nday[100000];

void add_guy(long d)
{
     ans.push_back(d);
long     qur=d;

//     for (int i=d;i<d+n;i++)
 //    key[i]=1;
     
     while (qur<10000)
     {
      for (int i=qur;i<qur+n+m;i++)
      {if (i<qur+n)w[i]++;if (i+1<qur+n)nday[i]=1;}
      qur=qur+n+m;
     }
}

int main(){
//freopen("funny.in","r",stdin);
//freopen("funny.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m>>k;
for (int day=1;day<=5000;day++)
{
    while (w[day]<k)
    {
     add_guy(day);
    }
    if (nday[day]==0)add_guy(day);
}

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}