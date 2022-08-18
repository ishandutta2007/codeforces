/*
The killer woke before dawn
He put his boots on
He took a face from the ancient gallery
And he walked on down the hall

He went into the room
Where his sister lived and he
He paid a visit to his brother and then he
He walked on down the hall, yeah

And he came to a door and he looked inside
"Father?", "Yes, son?", "I want to kill you"
He said, "What?"
And mother? I want to

I want to fuck you
For what you put me through
So what you got, so fuck you
It's coming back to you so what you got

The other night I was out riding in a friend's car
And out there on the side of the road there was this snake
This snake had eyes of fire and fangs from another world
But he was selling something

He was selling devotion
He was selling dreams, he was selling lifestyles
And I said, "Sure man what you got?"
"I'm interested in anything that's gonna get me off"
And the snake just stood there and smiled
With the spit in his eye and cried

Fuck you
For what you put me through
So what you got, so fuck you
It's coming back to you, so what you got

He was selling dreams and he was selling lies
I met the prisoner of my own device
He was selling love, he was selling bliss
He sold me anything, I could not resist

Ride with me, ride with me
Ride with me, ride with me

I had the freedom to live how I wanted
To take what I wanted to take
From anyone at any time, forever in heartache
As the snake just stood there and smiled at my demise
I wasn't scared

So fuck you
For what you put me through
So what you got, so fuck you
For what you put me through, so what you got
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
#define move adsfasdfasd

#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long xp,yp,xv,yv;

long move;

bool canmove(long x,long y)
{
 if (x==xp&&y==yp)return false;
 if (x==xv&&y==yv)return false;
 if (x<0||y<0)return false;
 return true;
}

long get_score(long x,long y)
{
 if (!canmove(x,y))return 1e9;
 return abs(x-y-xv+yv);
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>xp>>yp>>xv>>yv;

move=1;

while (true)
{
// cout<<xp<<" "<<yp<<" "<<xv<<" "<<yv<<endl;
 if (xv==0&&yv==0)
 {
  cout<<"Vasiliy"<<endl;
  break;
 }
 if (xp==0&&yp==0)
 {
  cout<<"Polycarp"<<endl;
  break;
 }
 
 move^=1;
 if (move==1)
 {
 if (canmove(xv-1,yv-1))
  {xv--,yv--;continue;}
 if (canmove(xv-1,yv))
  {xv--;continue;}
 if (canmove(xv,yv-1))
  {yv--;continue;}
  continue;
 }
 
 long val1=get_score(xp-1,yp);
 long val2=get_score(xp,yp-1);
 if (val1>1e7&&val2>1e7)continue;
 if (val1<val2)--xp;
 else --yp;
}

cin.get();cin.get();
return 0;}