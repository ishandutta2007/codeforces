/*
Crossing paths defending faith
Face the truth I'm balancing a razorblade
Time has come the game is on

Step inside a world of pain
I'm divine I fight so I can break these chains
Let me be the enemy
The rules will never change

Nothing will stand in my way
Adrenaline runs in my veins
Justice prevails and my name's
Has entered the scene I

Going up to the top
Never stop
Never give it up never fall never drop
You gotta give it up to the beat of your heart
And if you don't we take it from the start
Going up to the top
Never stop
Never gonna fail if you fall you get up
Surrender to the beat
From the pulse of your heart
And if you don't we take it from the start

Ticking clock a life in vain
Left alone the die is thrown a clashing pain
Just a brick a false charade

Crushing down like heavy rain
Time has come the ticket to eternal fame
Against all odds I rule this play
There's a darkness in my veins

Nothing will stand in my way
Adrenaline runs in my veins
Justice prevails and my name's
Has entered the scene I

Going up to the top
Never stop
Never give it up never fall never drop
You gotta give it up to the beat of your heart
And if you don't we take it from the start
Going up to the top
Never stop
Never gonna fail if you fall you get up
Surrender to the beat
From the pulse of your heart
And if you don't we take it from the start

See through the endless array
With the light's that are guiding our way

Going up to the top
Never stop
Never gonna fail if you fall you get up
Surrender to the beat
From the pulse of your heart
And if you don't we take it from the start

Going up to the top
Never stop
Never give it up never fall never drop
You gotta give it up to the beat of your heart
And if you don't we take it from the start
Going up to the top
Never stop
Never gonna fail if you fall you get up
Surrender to the beat
From the pulse of your heart
And if you don't we take it from the start
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
#define ry asdgasdg
#define rx iqowputtew

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 2010;

using namespace std;

int n,h,x[N];
int L[N],R[N];
double p;
bool was[N][N][2][2];
double memo[N][N][2][2];

double solve(int l,int r,int state1,int state2)
{
	if (l>r)
		return 0;
	if (was[l][r][state1][state2])
		return memo[l][r][state1][state2];
	
	was[l][r][state1][state2]=1;
	
	//l, l
	double res1=solve(l+1,r,0,state2)*p/2;
	int reach=x[L[l]]-h;
	int covered=(state1==1?x[l-1]+h:x[l-1]);
	if (reach<covered)
		reach=covered;
	res1+=fabs(x[l]-reach)*p/2;
	
//	cout<<reach<<"@"<<covered<<" "<<res1<<endl;
	
	//r,r
	res1+=solve(l,r-1,state1,1)*(1.0-p)/2;
	reach=x[R[r]]+h;
	covered=(state2==1?x[r+1]:x[r+1]-h);
	if (reach>covered)
		reach=covered;
	res1+=fabs(x[r]-reach)*(1.0-p)/2;
	
//	cout<<reach<<"@"<<covered<<" "<<res1<<" "<<endl;
	
	//l,r
	res1+=solve(R[l]+1,r,1,state2)*(1.0-p)/2;
	reach=x[R[l]]+h;
	covered=(state2==1?x[r+1]:x[r+1]-h);
	if (reach>covered)
		reach=covered;
	res1+=fabs(x[l]-reach)*(1.0-p)/2;
	
	//cout<<reach<<"!"<<covered<<" "<<res1<<endl;
	
	//r,l
	res1+=solve(l,L[r]-1,state1,0)*p/2;
	reach=x[L[r]]-h;
	covered=(state1==1?x[l-1]+h:x[l-1]);
	if (reach<covered)
		reach=covered;
	res1+=fabs(x[r]-reach)*p/2;
	
	//cout<<reach<<"%"<<covered<<" "<<res1<<endl;
	
	//cout<<l<<"%"<<r<<" "<<state1<<" "<<state2<<" "<<res1<<endl;
	memo[l][r][state1][state2]=res1;
	return res1;
}

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>h;
	
	x[0]=-1e9;
	x[n+1]=1e9;
	
	cin>>p;
	
	for (int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	
	sort(x+1,x+n+1);
	
	for (int i=1;i<=n;i++)
	{
		int ptr=i;
		while (x[ptr-1]>x[ptr]-h)
			--ptr;
		L[i]=ptr;
		ptr=i;
		while (x[ptr+1]<x[ptr]+h)
			++ptr;
		R[i]=ptr;
	}
	/*
	for (int i=1;i<=n;i++)
		cout<<x[i]<<" ";
	cout<<endl;
	for (int i=1;i<=n;i++)
		cout<<L[i]<<" ";
	cout<<endl;
	for (int i=1;i<=n;i++)
		cout<<R[i]<<" ";
	cout<<endl;
	*/
	cout.precision(12);
	cout<<fixed<<solve(1,n,1,0)<<endl;
	
	return 0;
}