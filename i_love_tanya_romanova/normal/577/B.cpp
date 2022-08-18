/*
Help me I don't know what I'm doin'
Help me before I fall to ruin
And if I'm blind, I will lead you on
Come follow me now before our time is gone

And as you're laughing at this fool tonight
Let me rid myself of any line that I might choose to trip you up
And as I'm howling at the moonlight, don't you kid yourself
I will be your luck and never be your curse, never be your curse

Help me I don't know what I'm saying
Sometimes this tongue can be betraying
And if I'm wrong, is that such a crime?
And if you want, you can set my words to right

So as you're laughing at this fool tonight
Let me rid myself of any line that I might choose to trip you up
And as I'm howling at the moonlight, don't you kid yourself
I will be your luck, yeah

And if your eyes forget to well
And if your lies forget to tell
And if our paths forget to cross
It doesn't mean you're lost

So if you're laughing at this fool tonight
Let me rid myself of any line that I might choose to trip you up
And as I'm howling at the moonlight, don't you kid yourself
Even at my worst

As you're laughing at this fool tonight
Let me rid myself of any line that I might choose to trip you up
And as I'm howling at the moonlight, don't you kill yourself
I will be your luck, even at my worst
I will be your luck, never be your curse
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

int n,m,ar[N];
int reach[3000][3000];
int found;

int main(){
//	freopen("path2.in","r",stdin);
//	freopen("path2.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>ar[i];
	}
	
	if (n>=m)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	
	for (int i=1;i<=n&&found==0;i++)
	{
		reach[i][ar[i]%m]=1;
		for (int val=0;val<m;val++)
			if (reach[i-1][val])
			{
				reach[i][val]=1;
				int to=(val+ar[i])%m;
				reach[i][to]=1;
			}
	}
	if (reach[n][0])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
}