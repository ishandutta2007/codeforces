/*
Sweet berries ready for two ghosts are no different than you.
Ghosts are now waiting for you.
Are you...
Sweet berries ready for two ghosts are no different than you.
Ghosts are now waiting for you.
Are you...
Dreaming! Dreaming the night! Dreaming all right!

Do we! Do we know, when we FLY?
When we, when we go
Do we die?

Sweet berries ready for two ghosts are no different than you.
Ghosts are now waiting for you.
Are you...
Sweet berries ready for two ghosts are no different than you.
Ghosts are now waiting for you.
Are you...
Dreaming! Dreaming the night! Dreaming all right!

Do we! Do we know, when we FLY?
When we, when we go
Do we die

LALALALALALLALAALALALALALAALALALALA

Do we, do we know
When we fly
When we, when we go 
Do we die
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
 
#define  INF 100000000
#define eps 1e-11
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

long n,k;

int main(){
//freopen("bees.in","r",stdin);
//freopen("bees.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>k;
if (k>n){cout<<-1<<endl;}
else if (k==1&&n>1)cout<<-1<<endl;
else
    if (n==k)
    {
             for (int i=1;i<=n;i++)
             cout<<char(i+'a'-1);
             cout<<endl;
    }   
    else
    {
        for (int i=1;i<=n-k+2;i++)
        {
            if (i%2)cout<<"a";
            else cout<<"b";
        }
        char temp='c';
        for (int i=n-k+3;i<=n;i++){
        cout<<temp;++temp;}
        cout<<endl;
    }
cin.get();cin.get();
return 0;}