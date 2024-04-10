/*
Nothing in this world
Could make me think
Differently...
Your Selfishness
Insults me
How can cruel somebody be
I know one day I'll rise
Only the strong survive...
You jealousy portrays
Your insecurity
No wonder your so sensitive
Unfold your true identity
I know one day I'll rise You try to manipulate who I am!
Don't try to change
What you don't understand.
Only in your head
Caged In
Is a perfect world...
Only in America
Caged In
These dreams are sold
Caged In
Welcome to the city of sin
You think you know it all
So tell me why you're miserable
Nothing lasts forever
Your eyes are lying
So my conscience is crystal clear
You tried to manipulate who I am!
Don't try to change
What you don't understand.
Only in your head
Caged In
Is a perfect world...
Only in America
Caged In
These dreams are sold
I'm a man
In another man's land
Just trying to survive
With my daily bread,
But you gotta
Understand why life
Can be so bad,
In a world where no one cares
If you live or die!
Coz' you and me,
Were Victims of this Fuckin' World...
Ain't nobody gonna save your ass...
But yourself!
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

using namespace std;

long n,m,k,q,bst,onemove,pmove;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
bst=1e9;

for(int i=1;i<=n;i++)
{
        cin>>q;
        if (q<bst&&i%2==1)bst=q;
}

if (n%2==0)
{
 cout<<0<<endl;
 return 0;
}
else
{
 onemove=n+1;
 onemove/=2;
 pmove=m/onemove;
 if (pmove==0)bst=0;
 else 
 if (bst/pmove>=k)bst=pmove*k;
 cout<<bst<<endl;
}

cin.get();cin.get();
return 0;}