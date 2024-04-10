/*
Jealousy's an ugly word, but you don't seem to care
Converse behind my back, but now I'm here
Need no one to comply with me though everyone that I defeat
Don't need you, fuck camaraderie, this rage will never go away

Hatred fuels my blood, I'll burn ya down (you can't help me)
One king to watch the horsemen fall, I'll fight 'til the end (I won't help you)
I can't trust anyone, see it in my eyes
Now I can understand, it's sorrow that feeds your lies

You're on my back when the water gets too deep for you to breath
A crutch for you that won't always be there
Hide in the dark another day, the fear in you is here to stay
So get the fuck away from me, and learn to trust the words I say.

Hatred fuels my blood, I'll burn ya down (you can't help me)
One king to watch the horsemen fall, I'll fight 'til the end (I won't help you)
I can't trust anyone, witness and see it in my eyes
Now I can understand, put faith in you for the last time
It's sorrow that feeds your lies

Run from me before I tear you down (be afraid)
You chose the wrong side (it feels so right)
I won't help you, let you rot away
Run towards the light exposing your soul (we won't be there by your side)
Salvation's dying (somebody's crying)
We're all gone in the end, sweet child we'll miss you
No, so far away

I can't trust anyone, witness and see it in my eyes
Now I can understand, put faith in you for the last time
It's sorrow that feeds your lies

Falling away, can't turn back time
Burn it down anyway
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
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-6
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000002013
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n;
double t1,t2,k,a,b;
vector<pair<double, int> >v;
int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>t1>>t2>>k;
k=1.0-k*0.01;

for (int i=1;i<=n;i++)
{
    cin>>a>>b;
    v.push_back(make_pair(max(a*t1*k+b*t2,b*t1*k+a*t2),-i));
}sort(v.begin(),v.end());

reverse(v.begin(),v.end());

cout.precision(2);
for (int i=0;i<v.size();i++)
cout<<-v[i].second<<" "<<fixed<<v[i].first<<endl;

cin.get();cin.get();
return 0;}