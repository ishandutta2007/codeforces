/*
Your insecurities makes me feel
So helpless, feel like letting go
Your insincerities, it makes a world
Of difference, you will never know

Another voiced rejection
Throw it at me, please just let me go
Another selfish reason
Throw it at me, please just let me go

It's all too much for me, I cannot hide
The sickness you bring on in me
Free of sympathy, you'll never know
How it hurts, you will never know

Another voiced rejection
Throw it at me, please just let me go
Another selfish reason
Throw it at me, please just let me go

Throw it at me, please just let me go
Another selfish reason
Throw it at me, please just let me go
Another voiced rejection
Throw it at me, please just let me go

Another selfish reason, throw it at me
Please just let me go, let me go
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

string st;
int cnt[N];
deque<char> qu;
vector<int> odd;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>st;
	for (int i=0;i<st.size();i++)
	{
		cnt[st[i]]++;
	}
	
	for (int i='a';i<='z';i++)
		if (cnt[i]%2)
			odd.push_back(i);
	
	sort(odd.begin(),odd.end());
	/*
	if (odd.size()%2)
	{
		for (int i=2;i<odd.size();i++)
		{
			cnt[odd[i]]--;
			cnt[odd[0]]++;
		}
	}
	else
	
	for (int i=1;i<odd.size();i++)
	{
		cnt[odd[i]]--;
		cnt[odd[0]]++;
	}
	*/
	
	int sz=odd.size();
	int l=0;
	int r=sz-1;
	while (l<r)
	{
		cnt[odd[l]]++;
		cnt[odd[r]]--;
		++l;
		--r;
	}
	
	int op=-1;
	
	for (int i='a';i<='z';i++)
	{
		if (cnt[i]%2)
		{
			cnt[i]--;
			qu.push_back(i);
		}
	}
	for (int i='z';i>='a';i--)
	{
		while (cnt[i])
		{
			qu.push_back(i);
			qu.push_front(i);
			cnt[i]-=2;
		}
	}
	
	while (qu.size())
	{
		cout<<qu.front();
		qu.pop_front();
	}
	cout<<endl;
	
	return 0;
}