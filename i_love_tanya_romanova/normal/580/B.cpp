/*
And we're at it again, I turn around another fucking war, man
I don't know where to begin, but I'll start with the radical leaders
Their steps we're followin'

Running, don't go back and fight, too many you'll lose
(And as clowns you follow suit behind the blood between the red and white and blue but it's too deep for you to see and everyone eventually will take the step cause it's in sight you take the left I'll take the right I fell the hate you've built for me and I say pay attention baby)

As they thank the Lord the blind can't see
Like a plague fed to the brain, deadly disease

But it wasn't a sin, a sorry life in judging every action
And as they're feeding your mind with this shit you forget
How to speak how to ask all the questions

The business at hand tonight, make the people choose
(I see another side in you but there's not much more I can do from on the outside looking in your government is listenin' to push you on the story of immortal father mortal son give them your mind and all your wealth the cycle will rebirth itself)
If they had it their way, I'd burn in Hell and your future's a fuckin' disaster, can't you see
Don't give them all the power when your future's in desperate trouble, baby

As they thank the Lord the blind can't see
Like a plague fed to the brain, deadly disease
I'd run away tonight with my mind still intact, you gotta make it alright
Easier said than done with no place to hide and having no place to...
Running away from condition, I see you but you're running away from
Your scared, seducive system

Most would claim I live a lie (I live a lie) when pointing out it's easy to predict these things
Every color has its side (I have a side), they live together vote and most embrace the same dark times
Please help us, please save us, of course they have control we're all the same
Up on the cross, crucified their problem, drove the nail and let Him rot
Family and friends, it won't matter in the end I'm sure they'll understand
Now look at the world and see how the humans bleed
As I sit up here and wonder 'bout how you sold your mind, body and soul
Looking at the fields so green I know this sounds obscene
I see you're living for tomorrow but decisions you have made will leave you empty

As they thank the Lord the blind can't see
Like a plague fed to the brain, deadly disease
I'd run away tonight with my mind still intact, you gotta make it alright
Easier said than done with no place to hide and having no place to...

You've fallen asleep in denial
Look at the way we're dyin'
How it ends I'll never know
Just live your life blind like me
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

int n,d;
long long S;
long long ans;
vector<pair<int, int> > v;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>d;
for (int i=0;i<n;i++)
{
	int a,b;
	cin>>a>>b;
	v.push_back(make_pair(a,b));
}

sort(v.begin(),v.end());

int ptr=-1;

for (int i=0;i<n;i++)
{
	while (ptr+1<v.size()&&v[ptr+1].first<v[i].first+d)
	{
		++ptr;
		S+=v[ptr].second;
	}
	ans=max(ans,S);
	S-=v[i].second;
}

cout<<ans<<endl;

//cin.get();cin.get();
return 0;}