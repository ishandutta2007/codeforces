/*
Shade, stay, know all
But they communicate
Try, fade
The leverage of space

Star, jay
The fall dawn aim to place
With shades on
The leverage of...

Shade, shade, shade
The leverage of, the leverage of

Space, shade, shade
The leverage of, the leverage of

Hate breaks down
Mountains that we
Make so tame
Oh, the leverage of...

Shade, shade, shade
The leverage of, the leverage of

Space, shade, shade
The leverage of, the leverage of

When I was down upon myself
I walked a road that's always there
You and I were everywhere
And I'm alone

She would never know the reason
That I loved to come and see her
Where she sits, I'll never go
You know it's always there

The leverage of, the leverage of
*/

//#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
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
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

long long p,k;
vector<long long> ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>p>>k;

	long long cur_sign=1;
	while (p!=0){
		long long cur_rem=p%k;
		if (cur_sign==1)
			ans.push_back(cur_rem);
		else
			ans.push_back((k-cur_rem)%k);
		if (cur_rem==0)
			p/=k;
		else
		{
			if (cur_sign==-1)
				p=p/k+1;
			else
				p=p/k;
		}
		cur_sign*=-1;
	}

	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++){
		if (i)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}