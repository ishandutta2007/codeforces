/*
Walking down some highway
Midnight North Dakota
Somewhere 'round late fall
I knew that the time

Has come for me, I'm willing
A million stars above me
I tried to catch their fall
I tried to catch their fall

Inside I felt so empty
A stranger to this world so lost
And as the winter draws
I'm turning north

I'm leaving things behind, I just don't need
The only things in life of worth are free
To anyone's who's heard the call
And turned and walked away

I've traveled too long on my own
I've got a dream of home
Safe at last

Where are all the answers
And visionary wisdom
From the stately and esteemed?
Just as I thought

Disconsolate, I ponder
The evil human nature
And what it really means
For the ones who paved the way

No bag of gold can save their souls
It's like they never feared
But now their end is near
The flames start leaping

Baby, don't it drop you to your knees?
The only thing in life of worth is free
To anyone's who's heard the call
And turned and run away

Despite this nasty world, I roam
Imagine going home
Ghost of a chance
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

long n;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
if (n<3)
 {
  cout<<1<<endl<<1<<endl;
 }
else if (n==3)
{
 cout<<2<<endl;
 cout<<1<<" "<<3<<endl;
}
else if (n==4)
{
     cout<<4<<endl;
     cout<<2<<" "<<4<<" "<<1<<" "<<3<<endl;
 }
else 
{
     cout<<n<<endl;
     for (int i=1;i<=n;i+=2)
     {
         if (i>1)cout<<" ";
         cout<<i;
     }
     for (int i=2;i<=n;i+=2)
      cout<<" "<<i;
      cout<<endl;
 }
cin.get();cin.get();
return 0;}