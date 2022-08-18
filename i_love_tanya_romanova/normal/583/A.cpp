/*
Ah, damn, we got a lot of stupid people
Doing a lot of stupid things
Thinking a lot of stupid thoughts
And if you want to see one, just look in the mirror

Gotta kill Captain Stupid, can't you see him?
Today we start the new way, we're Suicidal
Got to kill the old way, we'll make it better
Won't you join our mission, don't be stupid

Got to kill Captain Stupid
I gotta kill Captain Stupid

Brothers killing brothers, what up with that?
Can't you see they're laughing, that ain't funny
Babies making babies, that ain't love
You just got screwed over, get some respect

Got to kill Captain Stupid
Got to kill Captain Stupid
Got to kill Captain Stupid
Got to kill Captain Stupid

(Kill him, kill him, kill him)
Gotta kill Captain Stupid
(Kill him, kill him, kill him)
Gotta kill Captain Stupid
(Kill him, kill him, kill him)
Gotta kill Captain Stupid
(Kill him, kill him, kill him)

And I don't understand why
People be bringin' Captain Stupid in there lives
Treating him like a super-hero

Glorifying him when he ain't nothing but a super-punk
And you see, you're the one who's gonna have to stop him
'Cause you're the one that started him

Oh, what's that?
So, now you say life sucks
Well, ninety-nine percent of it's what you make of it
So if your life sucks, you suck

What's that crap you're smoking, playing the fool
Waste your life for nothing, when your something
What the hell you thinking, mind pollution
Got to get back control, it's your life fool

Got to kill Captain Stupid
Got to kill Captain Stupid
Got to kill Captain Stupid
Got to kill Captain Stupid

(Kill him, kill him, kill him)
Gotta kill Captain Stupid
(Like I gotta, you gotta, we all gotta)
Gotta kill Captain Stupid
(Kill him, kill him, kill him)
Gotta kill Captain Stupid
(Like I gotta, you gotta, we all gotta, gotta kill Captain Stupid)

What's that now?
Ah, so you're scared to do something about it
Well, you better be scared not to do something about it

Because if you don't kill Captain Stupid
Captain Stupid gonna kill you
Got to kill Captain Stupid, fool
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

const int N = 1200000;

using namespace std;

int n,used1[N],used2[N];
vector<int> ans;

int main(){
//	freopen("path2.in","r",stdin);
//	freopen("path2.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n*n;i++)
	{
		int a,b;
		cin>>a>>b;
		if (used1[a]==0&&used2[b]==0)
		{
			ans.push_back(i);
			used1[a]=used2[b]=1;
		}
	}
	
	for (int i=0;i<ans.size();i++)
	{
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	
	return 0;
}