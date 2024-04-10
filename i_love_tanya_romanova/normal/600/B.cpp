/*
Mass inclination will fuel my frustration
And keep all redemption at bay
All indications prove your all mutations
And you all have nothing to say

Hate
Down on me
Break
Down on me
Slave
Down on me
Plague
Down on me

I can't believe everything you believe perceive
Is rightfully coming your way

Take me back to where I need to go (Inside me)
Show me how to question all I know (Excite me)
You'll come around (And reveal yourself)
You come down (In this best education)
I'll fall down (As we kill ourselves)
When it all goes down (Are you ready to suffer it all?)

My aggravation is manifestation
Of all of the shit that you say
This complication will lead to this damnation
Of all those who stand in my way

Hate
Down on me
Break
Down on me
Slave
Down on me
Plague
Down on me

I can't believe everything you believe perceive
Is rightfully coming your way

Take me back to where I need to go (Inside me)
Show me how to question all I know (Excite me)
You'll come around (And reveal yourself)
You come down (In this best education)
I'll fall down (As we kill ourselves)
When it all goes down (Are you ready to suffer it all?)

Take me back to where I need to go (Inside me)
Show me how to question all I know (Excite me)
You'll come around (And reveal yourself)
You come down (In this best education)
I'll fall down (As we kill ourselves)
When it all goes down (Are you ready to suffer it all?)

I'll be ready to suffer it all
I'll be ready to suffer it all
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

const int N = 200005;

using namespace std;

int ar[N];
int n,m;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	sort(ar,ar+n);
	
	for (int i=0;i<m;i++)
	{
		int val;
		cin>>val;
		int cnt=lower_bound(ar,ar+n,val+1)-ar;
		if (i)
			cout<<" ";
		cout<<cnt;
	}
	cout<<endl;
	return 0;
}