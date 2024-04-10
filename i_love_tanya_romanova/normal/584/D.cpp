/*
Some folks
Love to see red
Some folks
Never talk about it
Some folks
Crave a blue lady
Some folks
Know and still they doubt it

I'm just no good without it
I'm not a man at all
It makes me skin crawl

Baby, baby
Come on and save me, save me
My, my baby, baby
Come on and save me now

Some folks
Love to feel pain
Some folks
Wake up every mornin'
Some folks
Live for no reason
Some folks
Die without a warning

I'm just no good without it
I'm not a man at all
It makes me skin crawl

Baby, baby
Come on and save me, save me
My, my baby, baby
Come on and save me, save me
My, my baby, baby
Come on and save me now

I can't live without it
Just can't live without it
I don't wanna think about it
Don't wanna think about it
I just, I just can't live without it
I think I can't, I can't live without it
I just can't, no I can't live
I can't live

I'm just no good without it
I'm not a man at all
It makes me skin crawl

Baby, baby
Come on and save me, save me
My, my baby, baby
Come on and save me, save me
My, my baby, baby
Come on and save me, save me
My, my baby, baby
Come on and save me now

'Cause I just can't live without it
I just can't live without it night
I don't wanna think about it
I don't wanna think about it now
I just can't live without it
I don't wanna, don't wanna think about it now
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

int n;

bool prime(int x)
{
	for (int i=2;i*i<=x;i++)
		if (x%i==0)
			return false;
	return true;
}

vector<int> ans,ve;
int pr[1<<21];

void backtrack(int val,int dep)
{
	if (val==0)
	{
		ans=ve;
		return;
	}
	if (dep>3)
		return;
	for (int i=2;i<=val;i++)
	{
		if (pr[i]==0)
		{
			ve.push_back(i);
			backtrack(val-i,dep+1);
			ve.pop_back();
		}
	}
}

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

pr[1]=1;
for (int i=2;i<=1000000;i++)
	if (pr[i]==0)
		for (int j=i*2;j<=1000000;j+=i)
			pr[j]=1;

cin>>n;
if (n<=20)
{
	backtrack(n,0);
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++)
	{
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}

for (int i=2;i<=1000;i++)
	for (int j=2;j<=1000&&j+i<n;j++)
		if (pr[i]==0&&pr[j]==0&&prime(n-i-j))
		{
			cout<<3<<endl;
			cout<<i<<" "<<j<<" "<<n-i-j<<endl;
			return 0;
		}

//cin.get();cin.get();
return 0;}