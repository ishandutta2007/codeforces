/*
Beauty is what eyes behold
And you burn brighter than most
I chased you through the midnight streets
To be where I could speak freely

I didn't care what tomorrow held
I felt the world turning only for us
Only bliss now for you and me
Rise up let life's kiss send us reeling

And unlike the times before
From yesterday comes tomorrow
When life comes alive, the past moves aside
No regrets and no remorse
Come on, come on, come on

We have more than everything
More than man or machine
More than luck, more than fiction
Higher than any religion

And not like the times before
From yesterday comes tomorrow
When life comes alive, the past moves aside
No regrets and no remorse

We'll squeeze the blood out of life
And say goodnight to the silver of old
N' even when wrong, we're right
Far beyond the world of diamonds and gold

I've come to realize
Where happiness lies
I want you to know, I know
Come on, come on, come on

And not like the times before
From yesterday comes tomorrow
When life comes alive, the past moves aside
No regrets and no remorse
Come on, come on, come on
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

int n,x,ans;

int main(){
//	freopen("path2.in","r",stdin);
//	freopen("path2.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>x;
	for (int i=1;i<=n;i++)	
		if (x%i==0&&x/i<=n)
			++ans;
	cout<<ans<<endl;
	
	return 0;
}