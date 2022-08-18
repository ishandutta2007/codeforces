/*  
So wake up sleepy one...
It's time to save your world...

Steal dreams and give to you
Shoplift a thought or two
All children touch the sun
Burn fingers one by one, by one...

Will this earth be good to you
Keep you clean or stain through....

So wake up sleepy one...
It's time to save your world...
You're where the wild things are...
Yeah, toy soldiers off to war...

Big eyes to open soon
Believing all under sun and moon
But does heaven know you're here?
And did they give you smiles or tears?
No, no tears

Will this earth be good to you?
Keep you clean or stain through....

So wake up sleepy one...
It's time to save your world...
You're where the wild things are...
Yeah, toy soldiers off to war...

You swing your rattle down
Call to arms the trumpets sound
Toy horses start the charge
Robots, chessmen standing guard
We Shall Never Surrender!!!!
Hand puppets storm the base
Flags up now cannons rage
Hand puppets storm the base
Flags up now cannons rage
All clowns head for the rear
Slingshots fire to the air
All clowns head for the rear
Slingshots fire to the air
Slip into the edge of death
Crossfire to the marionettes
Slip into the edge of death
Crossfire to the marionettes
We Shall Never Surrender!!!!

All children touch the sun
Burn your fingers one by one
Will this earth be good to you?
Keep you clean or stain through....

So wake up sleepy one...
It's time to save your world...
You're where the wild things are...
Yeah, toy soldiers off to war...

So close your little eyes...
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
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long qc,fl,ans;
long n,m;

bool check(long x,long y,long qc,long fl)
{
 if (x==qc&&fl==0&&y==-x)return false;
 if (abs(x)>=abs(y)&&x==qc&&fl==0)return true;
 if (abs(y)>=abs(x)&&y==qc&&fl==1)return true;
 if (y<0&&x>0&&x==-qc+1&&fl==1&&y==-x+1)return true;
 return false;
}

void move()
{
 if (fl==0){fl=1;} else {if (qc<=0)qc=-qc+1;
 else qc=-qc;fl=0;}    
}

long solve(long x,long y)
{
 if (x==0&&y==0)return 0;
 if (x==1&&y==0)return 0;
 if (x==1&&y==-1)return 4;
 qc=0;
 fl=1;
 ans=0;
 while (!check(x,y,qc,fl))
 {
  ++ans;
  move();
  //cout<<qc<<" "<<fl<<endl;cin.get();
 }
 return ans;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

cout<<solve(n,m)<<endl;

cin.get();cin.get();
return 0;}