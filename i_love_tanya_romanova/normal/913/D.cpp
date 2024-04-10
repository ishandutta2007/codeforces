/*
Hello,
Is there anybody in there?
Just nod if you can hear me.
Is there anyone at home?

Come on now
I hear you're feeling down
Well, I can ease your pain
And get you on your feet again

Relax
I'll need some information first
Just the basic facts
Can you show me where it hurts?

There is no pain, you are receding
A distant ship smoke on the horizon
You are only coming through in waves
Your lips move but I can't hear what you're saying
When I was a child I had a fever
My hands felt just like two balloons
Now I've got that feeling once again
I can't explain, you would not understand
This is not how I am
I have become comfortably numb

I have become comfortably numb

O.K.
Just a little pin prick
There'll be no more aaaaaaaah!
But you may feel a little sick

Can you stand up?
I do believe it's working, good
That'll keep you going through the show
Come on, it's time to go.

There is no pain you are receding
A distant ship smoke on the horizon
You are only coming through in waves
Your lips move but I can't hear what you're saying
When I was a child
I caught a fleeting glimpse
Out of the corner of my eye
I turned to look but it was gone
I cannot put my finger on it now
The child is grown
The dream is gone
I have become comfortably numb.
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

int n,T,a[N],t[N];
vector<int> ans;
vector<pair<int,int> > candidates;

bool check(int l){
	candidates.clear();
	for (int i=1;i<=n;i++){
		if (a[i]>=l)
			candidates.push_back(make_pair(t[i],i));
	}
	if (candidates.size()<l)
		return false;
	sort(candidates.begin(),candidates.end());
	ans.clear();
	int t_used=0;
	for (int i=0;i<l;i++){
		ans.push_back(candidates[i].second);
		t_used+=candidates[i].first;
	}
	return (t_used<=T);
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>T;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		scanf("%d",&t[i]);
	}

	int l,r;
	l=0;
	r=n;
	while (l<r){
		int mid=l+r+1;
		mid/=2;
		if (check(mid))
			l=mid;
		else
			r=mid-1;
	}

	check(l);

	sort(ans.begin(),ans.end());

	printf("%d\n",l);
	printf("%d\n",(int)ans.size());
	for (int i=0;i<ans.size();i++){
		if (i)
			printf(" ");
		printf("%d",ans[i]);
	}

	cin.get(); cin.get();
	return 0;
}