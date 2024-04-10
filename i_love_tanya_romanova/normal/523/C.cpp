/*
Trapped in a prison that's built on belief
Playing the victim, consumed by my grief
Tricks my mind plays using old memories
Painting them blacker than when they were real
After a while I get unsatisfied
I will get out of these knots I have tied

This pain I hold lives in my soul
Yet I must learn to let it go
I must go on, I must be strong
It's always darkest right before dawn

Hostile imagery inside my head
focused on anger, defeat and regret
Inaction is an action in itself
This is the darkest that I've ever felt
Impending change is a must to survive
I'm just existing, not really alive

I'm just going through the motions, but no living
I must take back what I've lost and fight my demons
I embrace my darker side
Knowing that it's part of life
Even with my war inside
I will rise again

This pain I hold lives in my soul
Yet I must learn to let it go
I must go on, I must be strong
It's always darkest right before dawn
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
#define right adsgasgadsg
#define free adsgasdg
#define count adsgasdgasdg

using namespace std;

string st,st1;
long L,R,ptr;

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st;


cin>>st1;

ptr=0;

for (int i=0;i<st1.size();i++)
{
 if (st1[i]==st[ptr]){++ptr;if (ptr==st.size()){L=i;break;}}
}

ptr=st.size()-1;
for (int i=st1.size()-1;i+1;--i)
{
 if (st1[i]==st[ptr]){--ptr;if (ptr<0){R=i;break;}}
}
if (L<R)
 cout<<R-L<<endl;
 else cout<<0<<endl;
 
cin.get();cin.get();
return 0;}