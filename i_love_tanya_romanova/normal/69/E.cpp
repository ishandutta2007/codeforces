/*
Thunder touched my soul
I heard a call all should know
Its my time im alive
Some will come some will go
But most will never know
That greatness lives inside
Like the night turns into day
Doesnt matter what they say
My will is strong as a mountains high
I feel so tall i can touch the sky
Speak your mind, put me down
Say your prayers when im around
I live the life im not passing by
Shorn of hopes and dreams
I dont buy their foolish schemes
I just walk on by
I was born with a heros soul
If you got one then you know
Reach my hand where the eagles fly
I feel so tall i can touch the sky
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

set<long> ones;
map<long, long> calc;
long n,m,a,b;
long ar[200000];
set<long>:: iterator it;

void add(long p)
{
     if (calc[p]==0){ones.insert(p);}
     if (calc[p]==1){ones.erase(p);}
     calc[p]++;
}

void del(long p)
{  
     if (calc[p]==2){ones.insert(p);}
     if (calc[p]==1){ones.erase(p);}
     calc[p]--;
}

void solve()
{
     if( ones.size()==0)cout<<"Nothing"<<endl;
     if (ones.size()==0)return;
     it=ones.end();
     --it;
     cout<<(*it)<<endl;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>ar[i];
for (int i=1;i<=m;i++)
{
    add(ar[i]);   
}
solve();

for (int i=m+1;i<=n;i++)
{
    del(ar[i-m]);add(ar[i]);
    solve();
}

cin.get();cin.get();
return 0;}