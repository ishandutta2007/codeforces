/*
Don't give me names, you've got it all
You took it all away, drove me insane
Who'd come down to earth
Releasing me?

Healing my wounds
Why don't you close the door
When you're leaving me?
Now you'll run, running all the way
Back to me again

It's not to end in shame
To fight an endless lie
I'm not to play a game
I won't be on your side

Found a way, to reach myself again
And all I saw was shame
Drive me away
There's something deep in me

Waiting to escape
You think you know me
So why don't you close the door
When you're here with me?

I'm here to end the game
I'm living in a lie
It's hard to give the same
I won't be on your side
Won't be on your side

I love you a lot, to need you a lot
I leave you alone
I love you a lot, to need you a lot
I leave you alone

I'm here to end the game
I'm living in a lie
It's hard to give the same
I won't be on your side
Won't be on your side

I love you a lot, to need you a lot
I leave you alone
I love you a lot, to need you a lot
I leave you alone

Yea, to need you a lot
I love you a lot
To need you a lot
I love you a lot
To need you a lot
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

int n,pr[1<<20];
vector<int> ans;
void add(int x)
{
	int prod=1;
	while (true)
	{
		prod*=x;
		if (prod<=n)
			ans.push_back(prod);
		else
			break;
	}
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
pr[1]=1;
for (int i=2;i<=1000;i++)
{
	if (pr[i]==0)
	{
		add(i);
		for (int j=i*2;j<=1000;j+=i)
			pr[j]=1;
	}
}

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
	if (i)
		cout<<" ";
	cout<<ans[i];
}
cout<<endl;

//cin.get();cin.get();
return 0;}