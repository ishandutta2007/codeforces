/*
What do you do when something dies
A life together ended, your living a lie
When did this act become reality?
Hello conscience, do I laugh or do I cry

Nothings ever perfect
This is just a test

Imagine, imagine saying what can be said
Imagine, imagine each word a bullet 'til you're dead
Imagine, imagine killing something you love
Imagine, just think about living inside

Blood on your hands, blood in my eyes
Blood I can't keep, blood circumscribes
Blood on your hands, blood in my eyes
Blood I can't keep, blood circumscribes

Blood on your hands turns into blood in my eyes
And with the blood I can't keep
Our lives, blood circumscribes

Blood on your hands turns into blood in my eyes
And with the blood I can't keep
Our lives, blood circumscribes

Brother on, brother on, brother on, brother on
Brother on, brother on
Brother on, brothers in blood

A wave of hatred comes like the flood
Brother on brother on
Brothers in blood

A wave of hatred comes like the flood
Brother on brother on, brother
Brothers in blood

Hate is so much easier to feel than love
Brother on brother on
Brothers in blood

A wave of hatred comes like the flood
Brother on brother on, brother
Brothers in blood

Misery can be so attractive
When making yourself happy is the only alternative
At the expense of someone eases life
Do it for yourself, damn it, do what's right

Nothings ever perfect
This is just a test

Imagine, think about living your life
Imagine, think about being stabbed with a dull knife
Imagine, think how sane you'll be when it's through
Imagine, think real hard then do what ya gotta do

Blood on your hands, blood in my eyes
Blood I cant keep, blood circumscribes
Blood on your hands, blood in my eyes
Blood I cant keep, blood circumscribes

Blood on your hands turns into blood in my eyes
And with the blood I cant keep
Our lives, blood circumscribes

Blood on your hands turns into blood in my eyes
And with the blood I cant keep
Our lives, blood circumscribes

Brother on, brother on, brother on, brother on
Brother on, brother on
Brother on, brothers in blood

A wave of hatred comes like the flood
Brother on, brother on
Brothers in blood

A wave of hatred comes like the flood
Brother on brother on, brother
Brothers in blood

Hate is so much easier to feel than love
Brother on, brother on
Brothers in blood

A wave of hatred comes like the flood
Brother on brother on, brother
Brothers in blood

How do you get the blood off?

Imagine, imagine saying what can be said
Imagine, imagine each word a weight off your head
Imagine, imagine killing something your hate
Imagine, just think about living inside

Brother on, brother on, brother on, brother on
Brother on, brother on
Brother on, brothers in blood

A wave of hatred comes like the flood
Brother on brother on
Brothers in blood

A wave of hatred comes like the flood
Brother on brother on, brother
Brothers in blood

Hate is so much easier to feel than love
Brother on brother on
Brothers in blood

A wave of hatred comes like the flood
Brother on brother on, brother
Brothers in blood

My brother, my brother
My brother, my brother
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
  
  string st;
  long t[10000];
  
  long rev(long q)
  {
     //  cout<<q<<endl;
   long r=0;
   for (int i=0;i<8;i++){
   r=r*2+q%2;q/=2;}    
   return r;
//   cout<<r<<endl;
  }
  
int main(){
//freopen("dkl.in","r",stdin);
//freopen("dkl.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

getline(cin,st);

for (int i=1;i<=st.size();i++)
{
 t[i]=rev(st[i-1]);   
 cout<<(t[i-1]-t[i]+256)%256<<endl;
}

cin.get();cin.get();
return 0;}