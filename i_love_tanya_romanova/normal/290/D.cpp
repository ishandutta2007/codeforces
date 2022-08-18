/*
There's a light in the sky
That hangs on the edge of illusion
Something very fine but it's something
You know is there
Mystery of time hidden by a man of confusion
But the hand is quicker than the eye

Only the stranger knows why
'Cos it's magic
You know it's magic that you'll find
You see it's magic
I know who you are there's magic in you

Keep your eye on the man
And don't look away for a moment
How is it done how does he make me see
Something up his sleeve when he speaks you want
To believe him

But the hand is quicker than the eye
Only stranger knows why
'Cos it's magic
Can't you see it's magic that you'll find
You know it's magic
I know who you are 'cos there's magic in you

Driven by a force
Moving in another dimension
Here for today, gone for eternity
Seeking for truth
hidden by the word of his wisdom

But the hand is quicker than the eye
Only the stranger knows why
Can't you feel it's magic
You know it's magic that you'll find
I said it's magic
I know who you are 'cos there's magic in you
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n;
string st;

int main(){
//freopen("stars.in","r",stdin);
//freopen("stars.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st;
cin>>n;
for (int i=0;i<st.size();i++)
if (st[i]>='A'&&st[i]<='Z')
st[i]=st[i]-'A'+'a';
for (int i=0;i<st.size();i++)
if (st[i]>='a'&&st[i]<'a'+n)
st[i]=st[i]-'a'+'A';
cout<<st<<endl;

cin.get();cin.get();
return 0;}