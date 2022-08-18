/*
It is to see a traitor go free
It is to feel a filter in me
It is to leave the lights that I saw
It is to ask: is it easy to go

In this dead hour
Here with you
Seconds are worthless
In this dead hour
When all is blank
Minutes are worthless

How long will it take until
There will be room enough for hope
It is so sad to see
Dispossession
It has become my obsession

It is to have a knife in my back
It is to say my soul got a crack
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
#define bsize 256

using namespace std;

int n,k,have;
string board[200][200];

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
        if (i%2==j%2)
            board[i][j]='L',
            ++have;
        else
            board[i][j]='S';
    }

if (have<k)
    cout<<"NO"<<endl;
else
{
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (k==0)
                cout<<"S";
            else
            {
                cout<<board[i][j];
                if (board[i][j]=="L")
                --k;
            }
        }
        cout<<endl;
    }
}

//cin.get();cin.get();
return 0;}