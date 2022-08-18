/*
My angel she falls
Deserted down from heaven
In darkness she came to me

You stripped down my shields
You heard all my weeps
Your own heart broken
Laid down my burden

All sins forgiven
We'll find our haven
We'll heal our hearts
Each other's arms
My broken angel
All pain forgotten
Will you be here,
When gone is the night?
Here in my arms
My broken angel

My angel she falls
Deserted down from heaven
In darkness she came to me

My home my haven
Here in my arms
My little angel
Here in my arms

My sweet angel
Safe from all harms
So gently I'm waken
Here in your arms

You stripped down my shields
You heard all my weeps
To have it healing
To feel it burning

All sins forgiven
We'll find our haven
We'll heal our hearts
In each other's arms
My broken angel
All pain forgotten
Will you be here,
When gone is the night?
Here in my arms...
My broken angel.
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

int X,Y,x[10],y[10],tx[10],ty[10],found;

void solve()
{
    if (max(tx[0],tx[1])<=X&&ty[0]+ty[1]<=Y)
        found=1;
    if (max(ty[0],ty[1])<=Y&&tx[0]+tx[1]<=X)
        found=1;
}
int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>X>>Y;
for (int i=0;i<2;i++)
{
    cin>>x[i]>>y[i];
}
for (int mask=0;mask<4;mask++)
{
    for (int i=0;i<2;i++)
        if (mask&(1<<i))
            tx[i]=y[i],
            ty[i]=x[i];
        else
            tx[i]=x[i],
            ty[i]=y[i];
    solve();
}

if (found)
    cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;
    
//cin.get();cin.get();
return 0;}