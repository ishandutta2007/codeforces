/*
Feel so good I feel so fine
Love that little lady always on my mind
She gives me lovin' every night and day
Never gonna leave her
Never going away
Someone to love me
You know she makes me feel alright
Someone who needs me
Love me every single night
Feel so happy since I met that girl
When we're making love
It's something out of this world
Feels so good to know that she's all mine
Going to love that woman till the end of time
Someone to live for
Love me till the end of time
Makes me feel happy
Good to know that she's all mine
Lovely lady make love all night long
Lovely lady never do me no wrong
I don't wanna leave ya
I never wanna leave ya
Anymore no more
Lovely lady
Mystifying eyes
Lovely lady
She don't tell me no lies
I know I'll never leave ya
I'm never gonna leave ya
Anymore no more
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

using namespace std;
long long x,y,m,n,ans,span;

long long solve(long long x,long long y,long long m)
{
     if (max(x,y)>=m)return 0;
     if (x<=0&&y<=0)return -1;
     
     if (x>y)swap(x,y);
     ans=0;
     if (x<0){span=-x;
     ans=span/y;
     x+=ans*y;}
     
     while (x<m&&y<m)
     {
           if (x<y){x+=y;} else y+=x;
           ++ans;
     }
     return ans;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>x>>y>>m;

cout<<solve(x,y,m)<<endl;

cin.get();cin.get();
return 0;}