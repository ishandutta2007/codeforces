/*
You never sing for pleasure
You only make the sounds
You never feel the magic
'Cause you think the world is round

And you never dance in moonlight
You run but you never move
You don't believe in someday
And the truth is what you prove

But it's alright
Well, it's alright
Just another day

Too many chains around you
You laugh but you never smile
You don't belong in heaven
But you're here all the while

And it's alright
Well, it's alright
Just another day
Another day
Another day

Another day to let you down
Another way that they have found
Yes, another day, another way
Another way, another day

You never sing for pleasure
You only make the sounds
You never feel the magic
'Cause you think the world is spinning round for you

But it's alright
Yes, it's alright
Well, it's alright
Just another day
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

using namespace std;

int n,val,cnt[1<<20];
set<int> was;
map<int, int> memo;

int dfs(int mask)
{
    if (was.find(mask)!=was.end())
     return memo[mask];
    int S[40];
    for (int i=0;i<40;i++)
    S[i]=0;
    
    for (int i=0;i<29;i++)
     if (mask&(1<<i))
     {
        int tmask=mask;
        for (int j=i;j<29;j+=(i+1))
            if (tmask&(1<<j))
                tmask-=(1<<j);
        int q=dfs(tmask);
        S[q]=1;
     }
    int res=0;
    while (S[res])++res;
    was.insert(mask);
    memo[mask]=res;
    return res;
}
int nim[50];

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=29;i;--i)
{
    int val=pow(n+0.5,1.0/i);
    val-=1;
    for (int j=i+1;j<=29;j++)
     val-=cnt[j]*(j/i);   
    cnt[i]=val;
}

cnt[1]++;

/*for (int i=1;i<=29;i++)
 cout<<i<<" "<<cnt[i]<<endl;
 */
 
/*dfs((1<<29)-1);

for (int i=1;i<=29;i++)
 cout<<"nim["<<i<<"]="<<memo[(1<<i)-1]<<";"<<endl;
 */

nim[1]=1;
nim[2]=2;
nim[3]=1;
nim[4]=4;
nim[5]=3;
nim[6]=2;
nim[7]=1;
nim[8]=5;
nim[9]=6;
nim[10]=2;
nim[11]=1;
nim[12]=8;
nim[13]=7;
nim[14]=5;
nim[15]=9;
nim[16]=8;
nim[17]=7;
nim[18]=3;
nim[19]=4;
nim[20]=7;
nim[21]=4;
nim[22]=2;
nim[23]=1;
nim[24]=10;
nim[25]=9;
nim[26]=3;
nim[27]=6;
nim[28]=11;
nim[29]=12;

int res=0;
for (int i=1;i<=29;i++)
 if (cnt[i]%2)
  res^=nim[i];
if (res)cout<<"Vasya"<<endl;
else cout<<"Petya"<<endl;

//cin.get();cin.get();
return 0;}