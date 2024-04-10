/*
I believe... Nothing ever comes to light -
Chasing shadows in the night
In a starless sky and I wonder why

I believe... We will never find a way -
That darkness lights the day
We never question why, still I wonder why?

I close my eyes lost in a memory
Just like a candle in the wind
What could have been, with just one kiss goodbye
You spread your wings to fly
Far away, somehow, someday you will understand
I hope you'll understand... someday

Silent pictures speak like ghosts in the machine
Haunting my reflection in the frame
Chasing down the hopeful child inside of me
Where'd it all go wrong and who's to blame

We pass the time away
With empty lives, the laughter dies

Is this all we have to show?
Is this all they'll ever know? Can they find their way?
What went wrong? Where have all the heroes gone?
Trading futures for a song we gave away

Thinking only of myself, I forged ahead
No regrets, no apologies
Bitter tears reward the life that I have led
A world of lies brings me to my knees

I took the road with every twist and every turn
The words of wisdom is the lesson never learned
Lose your fear and free your soul or
The mysteries of life you'll truly never know
Youll never know

Is this all we have to show?
Is this all they'll ever know? Can they find their way?
What went wrong? Where have all the heroes gone?
Trading futures for a song we gave away
Just gave it away

I close my eyes, lost in that memory
Like a candle in the wind
What could have been, with just one kiss goodbye
You spread your wings to fly far away
I hope you'll understand one day

We pass the time away
With empty lives the laughter dies
And the colors fade  fade away

Is this all we have to show?
Is this all they'll ever know? Can they find their way?
What went wrong? Where have all the heroes gone?
Trading futures for a song we gave away

What went wrong?
Where have all our heroes gone?
Trade our future for a song,
We gave it all away...
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
#define bsize 256

using namespace std;

set<pair<int, int> > ::iterator it;
int n;
set<pair<int, int> > g;
int offset;

void add_edge(int a,int b)
{
    g.insert(make_pair(a+offset,b+offset));
}
void remove_edge(int a,int b)
{
    g.erase(make_pair(a+offset,b+offset));
}

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;

if (n==1)
{
    cout<<"YES"<<endl;
    cout<<2<<" "<<1<<endl;
    cout<<1<<" "<<2<<endl;
}
else 
if (n%2==0)
{
    cout<<"NO"<<endl;
}
else
{
    cout<<"YES"<<endl;
    
    cout<<(n+2)*2<<" ";
    offset=0;
    int N=n+2;
    for (int i=1;i<N;i++)
    {
        for (int j=i+1;j<=N;j++)
        {
            add_edge(i,j);
        }
    }
    remove_edge(1,N);
    remove_edge(2,N);
    for (int i=3;i<N;i+=2)
     remove_edge(i,i+1);
    
    offset=N;
    
    for (int i=1;i<N;i++)
    {
        for (int j=i+1;j<=N;j++)
        {
            add_edge(i,j);
        }
    }
    remove_edge(1,N);
    remove_edge(2,N);
    for (int i=3;i<N;i+=2)
     remove_edge(i,i+1);
    offset=0;
    add_edge(N,N*2);
    cout<<g.size()<<endl;

    for (it=g.begin();it!=g.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<"\n";
    }
}
//cin.get();cin.get();
return 0;}