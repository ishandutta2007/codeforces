/*
This romeo is bleeding 
But you can't see his blood 
It's nothing but some feelings 
That this old dog kicked up 

It's been raining since you left me 
Now I'm drowning in the flood 
You see I've always been a fighter 
But without you I give up 

I can't sing a love song 
Like the way it's meant to be 
Well, I guess I'm not that good anymore 
But baby, that's just me 

And I will love you, baby - Always 
And I'll be there forever and a day - Always 
I'll be there till the stars don't shine 
Till the heavens burst and 
The words don't rhyme 
And I know when I die, you'll be on my mind 
And I'll love you - Always 

Now your pictures that you left behind 
Are just memories of a different life 
Some that made us laugh, some that made us cry 
One that made you have to say goodbye 
What I'd give to run my fingers through your hair 
To touch your lips, to hold you near 
When you say your prayers try to understand 
I've made mistakes, I'm just a man 

When he holds you close, when he pulls you near 
When he says the words you've been needing to hear 
I'll wish I was him 'cause those words are mine 
To say to you till the end of time 

Yeah, I will love you baby - Always 
And I'll be there forever and a day - Always 

If you told me to cry for you 
I could 
If you told me to die for you 
I would 
Take a look at my face 
There's no price I won't pay 
To say these words to you 

Well, there ain't no luck 
In these loaded dice 
But baby if you give me just one more try 
We can pack up our old dreams 
And our old lives 
We'll find a place where the sun still shines 

And I will love you, baby - Always 
And I'll be there forever and a day - Always 
I'll be there till the stars don't shine 
Till the heavens burst and 
The words don't rhyme 
And I know when I die, you'll be on my mind 
And I'll love you - Always 
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256
#define clone agsdahfaassdg

using namespace std;

long long n,ar[200000],m,l,r,veds,bad;

int main(){
//freopen("virtualfriends.in","r",stdin);
//freopen("virtualfriends.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];

l=0;r=100000000000ll;
while (l<r)
{
      m=l+r;
      m/=2;
      veds=0;
      bad=0;
      for (int i=1;i<=n;i++)
      {if (ar[i]>m)bad=1;
       veds+=m-ar[i];
      }
      if (bad)veds=m-1;
      if (veds>=m)r=m;
      else l=m+1;
//      cout<<m<<" "<<veds<<" "<<l<<endl;
}

cout<<l<<endl;
cin.get();cin.get();
return 0;}