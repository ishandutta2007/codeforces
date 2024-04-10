/*
Out of body
High above ground
I feel nothing
Is there a way

Will I bend or will I break
There's no way down until I'm broken
Pain I feel is no mistake
So much hangs on me unspoken
Hard to say I will find a way to turn this back around

Out of body
High above ground
I feel nothing
Is there a way to bring me down

Out of body
High above ground
I feel nothing
Is there a way to bring me down

Is this a dream
Or am I awake
Either way it hurts to swallow
Everything that I can take
I'm so full, why am I hollow
Hard to say I will find a way to turn this back around

Out of body
High above ground
I feel nothing
Is there a way to bring me down

Out of body
High above ground
I feel nothing
Is there a way to bring me down
down
down
down
down

Out of body
High above ground
I feel nothing
Is there a way to bring me down

Out of body
High above ground
I feel nothing
Is there a way to bring me down

Out of body
High above ground
I feel nothing
Is there a way to bring me down

Out of body
High above ground
I feel nothing
Is there a way to bring me down
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
int val;
multiset<int> S;
multiset<int> ::iterator it;

int gcd(int a,int b)
{
	while (a&&b)a>b?a%=b:b%=a;
	return a+b;
}
vector<int> ans;

int main(){
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
	for (int j=1;j<=n;j++)
	{
		cin>>val;
		S.insert(val);
	}
}

for (int i=1;i<=n;i++)
{
	it=S.end();
	--it;
	int val=(*it);
	ans.push_back(val);
	for (int j=0;j<ans.size();j++)
	{
		int q=gcd(ans[j],val);
		S.erase(S.find(q));
		if (j+1<ans.size())
			S.erase(S.find(q));
	}
	//cout<<"@"<<val<<" "<<S.size()<<endl;
	
}

for (int i=1;i<=n;i++)
{
	if (i>1)
		cout<<" ";
	cout<<ans[i-1];
}

cout<<endl;

//cin.get();cin.get();
return 0;}