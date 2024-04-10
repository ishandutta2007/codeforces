/*
This romeo is bleeding 
But you can't see his blood 
It's nothing but some feelings 
That this old dog kicked up 

It's been raining since you left me 
Now I'm drowning in the flood 
You see I've always been a fighter 
But without you I give up 

Now I can't sing a love song 
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

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793

//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back

using namespace std;
long n,cr;
double l,v1,v2,x[200000],prob[200000];
pair <double, long> p;
vector <pair <double, long> > ev;

int main(){
//freopen("C:/aver.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
cin>>n>>l>>v1>>v2;

for (int i=0;i<n;i++)
{cin>>x[i];
 if (x[i]<l-v1*l/(v1+v2))cr++;
 p=make_pair(2*l-x[i],1);
 ev.push_back(p);
 if (x[i]<l-v1*l/(v1+v2))
 {p=make_pair(l-v1*l/(v1+v2)-x[i],-1);
  ev.push_back(p);
  }
 else
 {
     p=make_pair(2*l+l-v1*l/(v1+v2)-x[i],-1);
     ev.push_back(p);
 } 
}

p=make_pair(2*l,0);
ev.push_back(p);

p=make_pair(0,0);
ev.push_back(p);
//cout<<cr<<endl;

sort(ev.begin(),ev.end());
//for (int i=0;i<ev.size();i++)
//cout<<ev[i].first<<" "<<ev[i].second<<endl;

for (int i=1;i<ev.size();i++)
{
    prob[cr]+=(ev[i].first-ev[i-1].first)/2/l;
    cr+=ev[i].second;
}
cout.precision(12);
for (int i=0;i<=n;i++)
cout<<fixed<<prob[i]<<endl;

cin.get();cin.get();
return 0;}