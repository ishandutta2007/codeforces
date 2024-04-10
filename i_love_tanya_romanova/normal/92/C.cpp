/*
When I see my brother
What I see is like no other
What we had forever lost
Can't deny our friendship
Feeling like it's time to end this
bad relation ripped apart

When we're young
and disarranged
We didn't know it
any other way
Now were grown
He's still the same
People see him suffering

I am not about to run away
Turn my back to him
In his darkest hour
Give him will to fight
Antagonize his thoughts
See him thew his thoughest times
Purify his weakened heart

All the friends
We feel the same
the way it was
back in the day
The more we change
He stays the same
Will we ever see our friend again

I... feel that...
I can't protect my friend from himself

All I've got
are these lessons learned in life
The lessons I've been taught
They still remain
inside me thoughts
Even as we speak
as troubled as it seems
He'll always be a friend of mind
That's the way it was
and always will be

When we're young
and disarranged
We didn't know it
any other way
Now were grown
He's still the same
People see him suffering

I... feel...
I cannot help my friend
help him self

You... can't hear what I say
Never going away...
still friends down for life...
can you still fight...

All I've got
are these lessons learned in life
The lessons I've been taught
They still remain
inside me thoughts
Even as we speak
as troubled as it seems
He'll always be a friend of mind
That's the way it was
and always will be

Now in the end
it plain to see
what kind of friend
He has been for me
all along he could never see
Who he was
and always be

I... feel...
I cannot help my friend
help him self
*/

#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
string st1,st2;
long l,nx[200000][30],ls[100],ps,ans;
int main(){
    cin>>st1;getline(cin,st2);
    getline(cin,st2);
    l=st1.length();
    
    for (int i=1;i<=26;i++)
  {  nx[l][i]=1000000;ls[i]=1000000;}
    for (int i=l;i;--i)
    {
    for (int j=1;j<=26;j++)
     nx[i][j]=ls[j];
      ls[st1[i-1]-'a'+1]=i;
    }
   
   for (int i=1;i<=26;i++)
   nx[0][i]=ls[i];
      
ps=0;ans=0;l=st2.length();
/*for (int i=1;i<=26;i++)
cout<<nx[0][i]<<endl;
*/
for (int i=1;i<=l;i++)if (nx[0][st2[i-1]-'a'+1]>100000){cout<<-1<<endl; return 0;}
ans=1;
for (int i=1;i<=l;i++)
{if (ps>100000){ps=0;ans++;}
 if (ps==0){ps=nx[ps][st2[i-1]-'a'+1];}
 if (i<l){ps=nx[ps][st2[i]-'a'+1];}
;}
 cout<<ans<<endl;
 
cin.get();cin.get();
return 0;
}