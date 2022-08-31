/*
Dear Mother
Dear Father
what is this Hell you have put me through?
Believer
Deceiver
Day in, Day out live me life through you
Pushed onto me what's wrong or right
Hidden from this thing that they call life

Dear Mother
Dear Father
Every thought I'd think you'd disapprove
Curator
Dictator
Always censoring my every move
Children are seen but are not heard
Tear out everything inspired

Innocence
Torn from me without your shelter
Barred reality
I'm living blindly

Dear Mother
Dear Father
Time has frozen still what's left to be
Hear Nothing
Say Nothing
Cannot face the fact I think for me
No guarantee, it's life as-is
But damn you for not giving me my chance

Dear Mother
Dear Father
You've clipped my wings before I learned to fly
Unspoiled
Unspoken
I've outgrown that ... lullaby
Same thing I've always heard from you
Do as I say, not as I do

Innocence
Torn from me without your shelter
Barred reality
I'm living blindly

I'm in hell without you
Cannot cope without you two
Shocked at the world that I see
Innocent victim, please rescue me

Dear Mother
Dear Father
Hidden in your world you've made for me
I'm seething
I'm bleeding
Ripping wounds in me that never heal
Undying spite I feel for you
Living out this hell you always knew

No!
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
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;
long n,ans,sx,sy,fx,fy,nx,ny;
char c;

long gd(long x,long y)
{
     return abs(x-fx)+abs(y-fy);
}

void gc(long x,long y,char dir)
{
 nx=x;ny=y;
 if (dir=='N')++ny;
 if (dir=='S')--ny;
 if (dir=='W')--nx;
 if (dir=='E')++nx;    
}

int main(){
//freopen("sumdist.in","r",stdin);
//freopen("sumdist.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
ans=n+1000;
cin>>sx>>sy>>fx>>fy;

for (int i=0;i<n;i++)
{
 cin>>c;
 gc(sx,sy,c);
 if (gd(nx,ny)<gd(sx,sy))
 {
  sx=nx;sy=ny;
 }   
 if (sx==fx&&sy==fy)
 {
                    ans=min(ans,ans-ans+i+1);}
}
if(ans>n)ans=-1;
cout<<ans<<endl;
cin.get();cin.get();
return 0;}