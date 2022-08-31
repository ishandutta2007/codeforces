/*
Bury all your secrets in my skin
Come away with innocence, and leave me with my sins
The air around me still feels like a cage
And love is just a camouflage for what resembles rage again...

So if you love me, let me go.
And run away before I know.
My heart is just too dark to care.
I can't destroy what isn't there.
Deliver me into my fate -
If I'm alone I cannot hate
I don't deserve to have you...
My smile was taken long ago
If I can change I hope I never know

I still press your letters to my lips
And cherish them in parts of me that savor every kiss
I couldn't face a life without your light
But all of that was ripped apart...
when you refused to fight

So save your breath, I will not hear.
I think I made it very clear.
You couldn't hate enough to love.
Is that supposed to be enough?
I only wish you weren't my friend.
Then I could hurt you in the end.
I never claimed to be a saint...
My own was banished long ago
It took the death of hope to let you go

So break yourself against my stones
And spit your pity in my soul
You never needed any help
You sold me out to save yourself
And I won't listen to your shame
You ran away - you're all the same
Angels lie to keep control...
My love was punished long ago
If you still care, don't ever let me know
If you still care, don't ever let me know...
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

double n,R,r,rr;

int main(){
//freopen("deques.in","r",stdin);
//freopen("deques.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>R>>r;
rr=(R-r)*sin(M_PI/n);
if (n==1)
{if (r<=R)cout<<"YES"<<endl;
else cout<<"NO"<<endl;}
else if (n==2)
{if (r*2<=R)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
else
{cout.precision(9);
//cout<<fixed<<rr<<" "<<r<<endl;
if (rr+1e-8<r)cout<<"NO"<<endl;
else cout<<"YES"<<endl;
}
cin.get();cin.get();
return 0;}