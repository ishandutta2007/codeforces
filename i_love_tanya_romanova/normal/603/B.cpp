/*
President's bullet-ridden body
In the street, ride, Johnny ride
Kennedy's shattered head
Hits concrete, ride, Johnny ride

Johnny's wife is floundering
Johnny's wife is scared, run, Jackie run

Texas is an outrage when your husband is dead
Texas is an outrage when they pick up his head
Texas is the reason that the president's dead
You gotta suck, suck, Jackie suck

President's bullet-ridden body
In the street, ride, Johnny ride
Kennedy's shattered head
Hits concrete, ride, Johnny ride

Texas is an outrage when your husband is dead
Texas is an outrage when they pick up his head
Texas is the reason that the president's dead
You gotta suck, suck, Jackie suck

Arise Jackie O, Jonathon of Kennedy
Well, arise and be shot down
The dirt's gonna be your dessert
My cum be your life source

And the only way to get it
Is to suck or fuck or be poor and devoid
And masturbate me, masturbate me
Then slurp it from your palm

Like a dry desert soaking up rain, soaking up sun
Like a dry desert soaking up rain, soaking up sun
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

const int N = 1000005;

using namespace std;

int p,k;
long long ans;
int used[N];

void trace(int x)
{
	if (used[x])
		return;
	used[x]=1;
	trace(1ll*x*k%p);
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>p>>k;
	ans=1;
	for (int i=1;i<p;i++)
	{
		if (used[i])
			continue;
		ans=1ll*ans*p%bs;
		trace(i);
	}
	
	if (k==1)
		ans=1ll*ans*p%bs;
		
	cout<<ans<<endl;
	
	return 0;
}