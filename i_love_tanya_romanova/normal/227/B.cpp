/*
Such a lonely day
And it's mine
The most loneliest day of my life

Such a lonely day
Should be banned
It's a day that I can't stand

The most loneliest day of my life
The most loneliest day of my life

Such a lonely day
Shouldn't exist
It's a day that I'll never miss
Such a lonely day
And it's mine
The most loneliest day of my life

And if you go, I wanna go with you
And if you die, I wanna die with you

Take your hand and walk away

The most loneliest day of my life
The most loneliest day of my life
The most loneliest day of my life
Life

Such a lonely day
And it's mine
It's a day that I'm glad I survived
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

long long n,q,ps[200000],ans1,ans2,t;

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>q;
ps[q]=i;
}

cin>>q;
for (int i=1;i<=q;i++)
{
    cin>>t;
    ans1+=ps[t];
    ans2+=n-ps[t]+1;
}
cout<<ans1<<" "<<ans2<<endl;

cin.get();cin.get();
return 0;}