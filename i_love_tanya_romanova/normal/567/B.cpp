/*
Looks like I'm 'a do everything myself
Maybe I could use some help
But hell, you want something done right
You gotta do it yourself

Maybe life is up and down
But my life's been what to now?
I crawled up your butt from hell
And that's when things got turned around

It used to be a lie and now it feels pathetic and now I get it
What's done is done, you just leave it alone and don't regret it
Sometimes some things turn into dumb things
And that's when you put your foot down

Why did I have to go and meet somebody like you?
Why do you have to go and hurt somebody like me?
How could you do somebody like that?
Hope you know that I'm never coming back

Looks like I'ma do everything myself
Maybe I could use some help
But hell, if you want something done right
You just do it yourself, got it?

Maybe life is up and down
But, but my life's been what to now? Got it?
I crawled up your butt somehow, got it?
And that's when shit got turned around, got it

It used to be a lie, so pathetic but now I get it
What's done is done, I know, you just leave it alone and don't regret it
But sometimes some things turn into dumb things
And that's when you put your foot down

Why did I have to go and meet somebody like you?
Why do you have to go and hurt somebody like me?
How could you do somebody like that?
Hope you know that I'm never coming back

Why did I have to go and meet somebody like you?
Why do you have to go and hurt somebody like me?
How could you do somebody like that?
Hope you know that I'm never coming back

Depending on you is done
Giving to you is done
No more eating, no sleeping, no living
It's all just what giving to you and I'm done

Depending on you is done
And giving to you is done
No more eating, no sleeping, no living
It's all just what giving to you and I'm done

The hiding from you is done
The lying from you is done
No more eating, no sleeping, no living
It's all just what giving to you and I'm done

Why did I have to go and meet somebody like you?
Why do you have to go and hurt somebody like me?
How could you do somebody like that?
Hope you know that I'm never coming back

Why did I have to go and meet somebody like you?
Why do you have to go and hurt somebody like me?
How could you do somebody like that?
Hope you know that I'm never coming back

But why?
Why?
Why?
Why?

Ladies and gentlemen
What you are experiencing is in fact
An inner lie man
I would like you to kick back
And think about everything you've just heard
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int n;
string st;
int id;
set<int> have;
int open,b;
int ans;
int val[1<<20];

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>st;
    if (st=="+")
    {
        cin>>id;
        open++;
        have.insert(id);
    }
    else
    {
        cin>>id;
        if (have.find(id)!=have.end())
        {
            open--;
            have.erase(id);
        }
        else
            for (int j=1;j<=i;j++)
                val[j]++;
    }
    val[i]+=open;
}
ans=0;
for (int i=1;i<=n;i++)
    ans=max(ans,val[i]);
cout<<ans<<endl;

//cin.get();cin.get();
return 0;}