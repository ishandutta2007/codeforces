/*
Everyday they wear me down
And scar my soul day in day out
This burden, I cannot bear
Living in this nightmare
Voices of emotion, chaos in my head
A voice from the commotion
Screams above the rest
Despair turns into pain
Anger turns into hate
Revenge calls my name
Spellbound by my rage

All this pain, takes its toll
And it makes the heart grow cold
The descent of a blackened soul

I replace reality with comforts of insanity
I can't go back for it's too late
To the dream world I escape
Voices of emotion no longer crying out
Desire your destruction, I long to take you down
What's real? What is not?
The line has been crossed
Darkness killed my empathy
Fire consuming me

All this pain, takes its toll
And it makes the heart grow cold
The descent of a blackened soul

As the fog clears, the haze wears off
The rush subsides
What have I done?
I stand before your lifeless shell
Now you understand my hell
I descend in the abyss
Deeper now I start to drift
To the sweet slumber of madness
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

long long a,b;

long long solve(long long a,long long b)
{
 if (a<b)swap(a,b);
 if (b==0)return 0;
// cout<<a<<" "<<b<<endl;
 return a/b+solve(a%b,b);
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>a>>b;
cout<<solve(a,b)<<endl;

cin.get();cin.get();
return 0;}