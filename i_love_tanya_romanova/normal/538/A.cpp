/*
No doubts!
You're the result of the chances you take
Face the circumstance!

Have you become who you wished to be?
Resigning to what you loved and cared

There's no way out!
Memories will come to remind you some day
How it could have been

Through every door you will step in
Another choice you're stuck between
Don't look back. Just make your way ahead

A window to nowhere
The void in which I stare
Now that I've come so far where do I go from here?

Decision just came in time
A new door is open
You have to go again decide!

You finally realize
The whole world you're facing
The window of your life good bye!

A window to nowhere
Wide-eyed in great despair
Now that I've come so far where do I go from here?

Life is drowned in fears
The river of my tears
Please hold my trembling hands before I go insane all again
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

string st,temp;
long ans;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
cin>>st;
for (int l=0;l<st.size();l++)
    for (int r=l;r<=st.size();r++)
    {
        temp="";
        for (int j=0;j<st.size();j++)
         if (j<l||j>=r) temp+=st[j];
        if (temp=="CODEFORCES")ans=1;
        
    }
if (ans)cout<<"YES"<<endl;
else cout<<"NO"<<endl;

cin.get();cin.get();
return 0;}