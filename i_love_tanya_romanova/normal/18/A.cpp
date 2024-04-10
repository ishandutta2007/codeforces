/*
No hears a word I say
And my prayers are never answered
But you'll never see the pain inside of me
Stabbing me over and over and over
I trusted you and I loved you
And you spit back in my face
How could you do this to me?
When will you stop trying to hurt me?
I've walked a minefield for you
A career in hell with you
I have made it through the things
Others would surely die just watching
And the oath I take on this day
Is to know that you will be repaid
One day the the sun will die and the night will crawl
Until then, until I see your world implode
I wish you death and suffering
Misery to spare
Time to release your pain
Face the last enemy
I am the last thing you will know
The last thing you will see
I see your death surrounding me
I know you, yes I do
I know you

When no words are spoken and please are ignored
Your tears go unnoticed, will you say enough?
When prayers are unanswered and your calls are unheard
The pain cuts right through you, have you seen enough?

It all seems so deceitful and the verdict is lies
A black cloud of indecision compromised your life

When judgement has failed you
When your own heart's impaled you
Your wandering mind has destroyed you
Will you ever know when?

When you give everything and the feeling is gone
All the giving is fake, did you fake enough?
When you take everything and you stay too long
When there's nothing left, did you take enough?

It all seems so deceitful and the verdict is lies
A black cloud of indecision compromised your life

When judgement has failed you
When your own heart's impaled you
Your wandering mind has destroyed you
Will you ever know when?
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
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long long x1,y1,x2,y2,x3,y3,fl;
bool solve(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
     vector<long> v;
     v.push_back((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
     v.push_back((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
     v.push_back((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
     sort(v.begin(),v.end());
     if (v[0]==0)return false;
     if (v[0]+v[1]==v[2])return true;
     return false;
}
int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>x1>>y1>>x2>>y2>>x3>>y3;
if (solve(x1,y1,x2,y2,x3,y3))cout<<"RIGHT"<<endl;
else
{
    fl=0;
    if (solve(x1+1,y1,x2,y2,x3,y3))fl=1;
    if (solve(x1-1,y1,x2,y2,x3,y3))fl=1;
    if (solve(x1,y1-1,x2,y2,x3,y3))fl=1;
    if (solve(x1,y1+1,x2,y2,x3,y3))fl=1;
    
    if (solve(x1,y1,x2+1,y2,x3,y3))fl=1;
    if (solve(x1,y1,x2-1,y2,x3,y3))fl=1;
    if (solve(x1,y1,x2,y2+1,x3,y3))fl=1;
    if (solve(x1,y1,x2,y2-1,x3,y3))fl=1;
    
    if (solve(x1,y1,x2,y2,x3-1,y3))fl=1;
    if (solve(x1,y1,x2,y2,x3+1,y3))fl=1;
    if (solve(x1,y1,x2,y2,x3,y3-1))fl=1;
    if (solve(x1,y1,x2,y2,x3,y3+1))fl=1;
    
    if (fl)cout<<"ALMOST"<<endl;
    else cout<<"NEITHER"<<endl;
}
cin.get();cin.get();
return 0;}