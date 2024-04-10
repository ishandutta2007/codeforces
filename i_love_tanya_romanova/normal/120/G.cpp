/*
Yeah, rock you to hell
Rock you to hell

What's wrong with our society
Is it fear or apathy?
Don't let other people run your life

So those with power don't use it
They simply abuse it
And believe me that cuts me like a knife

Gotta make sure that this don't happen
'Cause to me and you it just ain't right
Gonna make damn sure it don't happen
This is what I'm gonna do

Rock you to hell
Packin' up and shippin' out
Rock you to hell
Hear them scream and shout

Rock you to hell
But I'm never giving out
Rock you to hell
Rock you to hell

Did you always do what momma said?
Brush your teeth and go to bed
'Cause that way never worked for me

Now they wanna censor music
And if we don't fight we'll lose it
It's only entertainment, can't they see?

We gotta make sure that this don't happen
'Cause to me and you it just ain't right
Gonna make damn sure it don't happen
This is what I'm gonna do

Rock you to hell
Packin' up and shippin' out
Rock you to hell
Oh hear them scream and shout

Rock you to hell
I'm never giving out
Rock you to hell
Rock you to hell

Is this the beginning of a future?
No books, no sound, no rock 'n' roll
With only a few to fight the many
This is why rock 'n' roll will never die

We gonna make sure that this don't happen
'Cause to me and you it just ain't right
Gonna make damn sure it don't happen
This is what I'm gonna do

Rock you to hell
Packin' up and shippin' out
Rock you to hell
Hear them scream and shout

Rock you to hell
But I'm never giving out
Rock you to hell

Rock you to hell
Rock you to hell
Rock you to hell
Oh, rock you to hell
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int n,t,a[1000][5],b[1000][5];
int comp[1<<10];
string word[1000];
int m;
queue<int> qu;
int cur;
vector<int> ans[200];
int d[200][200];
int need[200][200];

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>t;

for (int i=0;i<n;i++)
{
    cin>>a[i][1]>>b[i][1]>>a[i][2]>>b[i][2];
}

cin>>m;
for (int i=1;i<=m;i++)
{
    cin>>word[i];
    cin>>comp[i];
}

for (int i=0;i<n;i++)
{
    for (int j=1;j<=m;j++)
    {
        int temp=comp[j]-(a[i][1]+b[i][2]);
        need[i][j]=temp;
        temp=comp[j]-(a[i][2]+b[i][1]);
        need[i+n][j]=temp;
        /*if (need[i][j]<1)
            need[i][j]=1;
        if (need[i+n][j]<1)
            need[i+1][j]=1;
            */
    }
}

for (int i=1;i<=m;i++)
{
        qu.push(i);
}

cur=0;

while (qu.size())
{
    int turn=t;
    while (true)
    {
        if (qu.size()==0)
            break;
        if (turn==0)
            break;
        int val=qu.front();
        qu.pop();
        int Ntime=need[cur][val]-d[cur%n][val];
        if (Ntime<1)
            Ntime=1;
        //cout<<Ntime<<" "<<turn<<" "<<cur<<endl;
        if (Ntime<=turn)
        {
            ans[cur%n].push_back(val);
            turn-=Ntime;
        }
        else
        {
            qu.push(val);
            d[cur%n][val]+=turn;
            break;
        }
    }
    cur++;
    cur%=(n*2);
}

for (int i=0;i<n;i++)
{
    cout<<ans[i].size();//<<endl;
    for (int j=0;j<ans[i].size();j++)
    {
        int id=ans[i][j];
    //  if (j)
            cout<<" ";
        cout<<word[id];
    }
    cout<<endl;
}

//cin.get();cin.get();
return 0;}