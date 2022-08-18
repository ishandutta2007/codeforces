/*
Shadows dance, in the moonlight
A chanting dance, in the dark night
A chanting hum, to summon the wind
To summon her, and the spell she brings

"Come now", the wind calls
"Come into the netherworld
Come now, come within
Into the land of the cold blowing wind"

She comes in the dark, a voice in her glimpse
"I am the silence, and the whispering wind
Come, come to me, come and take my hand
Come, come with me, into shadowland..."

Hand in hand, on a dark and devious path
Through the misty land, where shadows walk
"Come into shadowland, to where the wind blows cold
And become a shadow, of the netherworld..."
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 200000;

using namespace std;

long long need;
set<pair<long long, long long> > ans;
set<pair<long long, long long> > ::iterator it;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
//	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	
	// n^2*m-n*sum(i)-m*sum(i)+1*sum(i^2)
	//6*x=3*n^2*m-3*m*n-n^3+n
	
	cin>>need;
	need*=6;
	
	for (long long i=1;i<=2200000;i++)
	{
		long long rem=need+i*i*i-i;
		long long D2=i*i+i;
		D2*=3;
		if (rem%D2)
			continue;
		long long val2=rem/D2;
		if (val2<i)
			continue;
		ans.insert(make_pair(i,val2));
		ans.insert(make_pair(val2,i));
//		cout<<i<<" "<<val2<<endl;
	}
	
	cout<<ans.size()<<endl;
	for (it=ans.begin();it!=ans.end();it++)
	{
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	
	return 0;
}