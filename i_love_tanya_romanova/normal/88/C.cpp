/*
There's a secret place I like to go
Everyone is there but their face don't show
If you get inside, you can't get out
There's no coming back, I hear them shout

Welcome to my hide away, my secret place
How I arrived I can't explain
You're welcome to, if you want to stay
But everyone just runs away

Oh there's a secret place I like to go
Everyone is there but their face don't show
If you get inside you can't get out
There's no coming back, I hear them shout

Let me in, get me out
Can't do more then twist and shout
Lost my soul without a trace
Found it again in my secret place

Let me in, get me out
Can't do more then twist and shout
Lost my soul without a trace in disgrace

I hide from those that try to find me
Scary things that's right behind me
I lost myself, I must confess
I can't explain how I got this mess

Welcome to my hide away, my secret place
How I arrived I can't explain
You're welcome to, if you wanna stay
But everyone just runs away

My secret place, there's a secret place
My secret place, there's a secret place
I like to go, my secret place
There's a secret place, just runs away
My secret place
*/

#include <iostream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
long a,b,q,r,i,fl,ans;
long gcd(long a,long b)
{while (a&&b)a>b?a%=b:b%=a;
return a+b;}

int main()
{cin>>a>>b;
q=gcd(a,b);
a/=q;b/=q;
if (a>b){swap(a,b);fl=1;}
long r=0;
for (int i=1;i<=b;i++)
{r+=a;if (r<b&&i>1)ans=1;if (r>b)r-=b;}
if (ans==0)cout<<"Equal"<<endl;
else {if (fl)cout<<"Masha"<<endl; else cout<<"Dasha"<<endl;}

cin.get();cin.get();
return 0;
}