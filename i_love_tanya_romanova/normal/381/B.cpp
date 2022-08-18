/*
Attacked in the cold,
I lay to the ground
And I'm starting to freeze
Touched by the dark
I travelled the desert

In the days of bad dreams,
Bullets redeem
And I saw the black rain
Hunted by demons
I was touched by an angel

I'm going down, down,
It's getting dark
And I'm awake till the morning

The beat of black wings under red skies
The place where demons and angels will die
Out of torment there's no tomorrow
A sacred heart, an unholy lie
The place where demons and angels will die
I'm left out alone, there's no tomorrow

As the night goes by,
I'm facing the truth
And a ghost holds my hand
A candle, a flame
And I'm fighting the evil
My time has come, religion was gone
And no mercy in sight, a prayer in vain
And I welcome my enemy

I'm going down, down
I'm facing the hell
And rise the prophecy

The beat of black wings under red skies
The place where demons and angels will die
Out of torment there's no tomorrow
A sacred heart, an unholy lie
The place where demons and angels will die
I'm left out alone, there's no tomorrow
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
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,q,calc[20000],temp;
deque<long> ans;

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>q;
calc[q]++;
}

temp=5000;

while (calc[temp]==0)--temp;
ans.push_back(temp);
--temp;
for (;temp;--temp)
{
 if (calc[temp]==0)continue;
 if (calc[temp]>0){ans.push_back(temp);}
 if (calc[temp]>1)ans.push_front(temp);
}

cout<<ans.size()<<endl;
long q=ans.size();
for (int i=0;i<q;i++)
{
    if (i)cout<<" ";
    cout<<ans.front();
    ans.pop_front();
}
cout<<endl;

cin.get();cin.get();
return 0;}