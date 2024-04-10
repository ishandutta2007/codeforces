/*
After the war and now that they've sent us homeward
I can't help but feel that I'm on my own
No one can see just what this conflict has done to
The minds of the man who are on their way home

I'm scared for life but it's not my flesh that's wounded
So how can I face the torment alone
The vivid scenes and all the recurring nightmares
I lay there and sweat until it gets light...

People say "Don't worry"
Say that time's a perfect healer
That the nightmares they will come to pass
Can't hear what they're saying
I am living in my own world
And I'm feeling trance like all the time

I hear voices in my head
Could I really be going crazy
In the night the visions seem so real
Do you care if you live or die
When you laugh are you really crying
You're not sure what's real anymore

Fortunes of war
Fortunes of war no pain anymore

Sometimes I wake
I feel that my spirit's broken
I wonder if I've the strenght... to carry on.
*/

//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
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
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
const int MAXN = 120000; 

long long n,m,bs;

long long pw(long long a,long long b)
{
     if (b==0)return 1;
     if (b%2)return pw(a,b-1)*a%bs;
     return pw(a*a%bs,b/2)%bs;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
bs=m;
cout<<(pw(3,n)+m-1)%m<<endl;
cin.get();cin.get();
return 0;}