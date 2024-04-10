/*
Hate your goddamn, motherfucking, shitty ass band
Hate the way you've got my back while you're holding out your hand
Hate the way you pussies talk shit, hiding on the web
Just the fact you think you know me makes me fucked up in the head
Hate your nails, hate your hair, hate the fact I even care
Hate the way you said you loved me but you fucking weren't there
Hate your friends, hate your folks, it's a stupid fuckin' hoax
Hate the way I tried to change when the whole thing was a joke

I... hate... you...
That's an understatement
I... hate... you...
For who you are

I hate you
And all you stand for
I don't care
Anymore
I gave you
100 chances
You gave me
A hundred ways to hate

Hate your face, hate your lies and the blank look in your eyes
Hate your needs, hate your wants, hate the way you love to taunt
Hate your voice, makes me cringe every time I hear you speak
It's uncomfortable to know you share the same air as me
Hate your lack of common sense and I'm tired of compromising
Take a good look in the end, 'cause it's just on the horizon
I've been wrong about a lot of shit, this I know is true
There's a hundred fucking things that I hate about you

I... hate... you...
That's an understatement
I... hate... you...
For who you are

I hate you
And all you stand for
I don't care
Anymore
I gave you
100 chances
You gave me
A hundred ways to hate

I hate you
100 ways
I don't care
100 ways to hate
I gave you
A million chances
You gave me
A hundred ways to hate

A hundred ways
A hundred ways to hate
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
 
#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009
#define bsize 256

using namespace std;

long n,s,ar[2000];

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>s;
for (int i=0;i<n;i++)
 cin>>ar[i];
 sort(ar,ar+n);
 for (int i=0;i<n;i++){
  if (i+1<n)s-=ar[i];}
 // cout<<s<<endl;
  
  if (s>=0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  
cin.get();cin.get();
return 0;}