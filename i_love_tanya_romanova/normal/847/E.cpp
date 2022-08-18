/*
He said "Son, have you seen the world?
Well, what would you say if I said that you could?
Just carry this gun and you'll even get paid"
I said "That sounds pretty good"

Black leather boots
Spit-shined so bright
They cut off my hair but it looks alright
We marched and we sang
We all became friends
As we learned how to fight

A hero of war
Yeah that's what I'll be
And when I come home
They'll be damn proud of me
I'll carry this flag
To the grave if I must
Because it's a flag that I love
And a flag that I trust

I kicked in the door
I yelled my commands
The children, they cried
But I got my man
We took him away
A bag over his face
From his family and his friends

They took off his clothes
They pissed in his hands
I told them to stop
But then I joined in
We beat him with guns
And batons not just once
But again and again

A hero of war
Yeah that's what I'll be
And when I come home
They'll be damn proud of me
I'll carry this flag
To the grave if I must
Because it's a flag that I love
And a flag that I trust

She walked through bullets and haze
I asked her to stop
I begged her to stay
But she pressed on
So I lifted my gun
And I fired away

And the shells jumped through the smoke
And into the sand
That the blood now had soaked
She collapsed with a flag in her hand
A flag white as snow

A hero of war
Is that what they see
Just medals and scars
So damn proud of me
And I brought home that flag
Now it gathers dust
But it's a flag that I love
It's the only flag I trust

He said, "Son, have you seen the world?
Well what would you say, if I said that you could?"
*/

#pragma GCC optimize("O3")
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

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

int n;
string st;
vector<int> packmans,stars;

bool can_reach(int start,int ps1,int ps2,int t){
	int  need=min(abs(start-ps1)+abs(ps1-ps2),abs(start-ps2)+abs(ps1-ps2));
	return (need<=t);
}

bool can_solve(int span){

	int covered=0;
	for (int i=0;i<packmans.size();i++)
	{
		int ptr=covered;
		while (ptr<stars.size()&&can_reach(packmans[i],stars[covered],stars[ptr],span))
			++ptr;
		covered=ptr;
	}
	return (covered==stars.size());
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;
	cin>>st;
	for (int i=0;i<st.size();i++)
	{
		if (st[i]=='P'){
			packmans.push_back(i);
		}
		if (st[i]=='*'){
			stars.push_back(i);
		}
	}

	int l,r;
	l=0;
	r=1e9;
	while (l<r){
		int mid=l+r;
		mid/=2;
		if (can_solve(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<l<<endl;

	cin.get(); cin.get();
	return 0;
}