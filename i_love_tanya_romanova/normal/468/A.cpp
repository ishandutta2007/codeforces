/*
Polly wants a cracker
I think I should get off her first
I think she wants some water
To put out the blow torch

Isn't me, we have a seed
Let me clip your dirty wings
Let me take a ride, don't cut yourself
Want some help to please myself

Got some rope, you have been told
I promise you, I have been true
Let me take a ride, don't cut yourself
Want some help to please myself

Polly wants a cracker
Maybe she would like some food
She asked me to untie her
A chase would be nice for a few

Isn't me we have some seed
Let me clip dirty wings
Let me take a ride, don't cut yourself
Want some help to please myself

Got some rope, you have been told
Promise you, I have been true
Let me take a ride don't cut yourself
Want some help to please myself

Polly said

Polly says her back hurts
She's just as bored as me
She caught me off my guard
Amazes me the will of instinct

Isn't me we have some seed
Let me clip your dirty wings
Let me take a ride, don't cut yourself
Want some help to please myself

Got some rope, you have been told
Promise you, I have been true
Let me take a ride, don't cut yourself
Want some help to please myself
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long n;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
if (n<4)
{
 cout<<"NO"<<endl;
}
else
{
    cout<<"YES"<<endl;
    if (n%2==0)
    {
               for (int i=n-1;i>=5;i-=2)
               {
                cout<<i+1<<" - "<<i<<" = 1"<<endl;
                cout<<i-1<<" * 1 = "<<i-1<<endl;
               }
               cout<<"4 * 3 = 12"<<endl;
               cout<<"12 * 2 = 24"<<endl;
               cout<<"24 * 1 = 24"<<endl;
    }
    else
    {
                for (int i=n-1;i>=6;i-=2)
               {
                cout<<i+1<<" - "<<i<<" = 1"<<endl;
                cout<<i-1<<" * 1 = "<<i-1<<endl;
               }
               cout<<"1 - 5 = -4"<<endl;
               cout<<"2 - 4 = -2"<<endl;
               cout<<"-2 * -4 = 8"<<endl;
               cout<<"3 * 8 = 24"<<endl;
    }
}

cin.get();cin.get();
return 0;}