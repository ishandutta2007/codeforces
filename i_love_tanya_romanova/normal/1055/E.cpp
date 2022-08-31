/*
Every time I see your grinning face
I realize you're a pitiful disgrace
So many fingers pointing down at you
Talking behind your back and you don't have a clue
Parading around like you think you're god
You're just a cheap imitation, a complete and total fraud
I'm sick of hearing all your bragging and your lies
A real born loser and that's no surprise

You said your father died in Vietnam
But you're a bastard son with a whore for a mom
Mirror magnet, smelling like a rose
You plastic motherfucker, all you do is pose
Conceited, self-righteous, and arrogant
Your head is so hollow there's enough room to rent
Little big man, so full of shit
Just shut up, you damn hypocrite

Verbal razors - cut you down to size
I'm sick of wading through your bullshit
I see through your disguise
Verbal razors - slice you to the bone
You've been abandoned
And now you're all alone

You lost your job because you're incompetent
Everybody hates you, your friends all came and went
The facade is getting old, we're hip to your charade
You mother has disowned you, your wife's out getting laid
Evicted from your condo, now you're living in a shack
Sitting on your ass shooting up and smoking crack
Now look in the mirror, and tell me what you see
A strung-out junkie with a college degree!

Nobody cares if you're alive or dead
We've had enough of being used and misled
You've pissed on everyone you've ever met
Now you're digging through the trash looking for a cigarette
No one's there to lend you a hand
You better help yourself, 'cause I hope you understand
Self-centered, back-stabbing egotist
Don't fuckin' ask for favors, 'cause you're on my blacklist
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
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600000;

int n,s,m,k;
int ar[N];
int L[N],R[N];

vector<int> ends_at[N];

int val[1531];
int S[1531];
int max_taken[1531][1531],min_missed[1531][1531];

int sparse_min[50][1531],sparse_max[50][1531];

int LG[1531];

// max taken
int sparse_taken(int l,int r){
	int span=r-l+1;
	span=LG[span];

	return max(sparse_max[span][l],sparse_max[span][r-(1<<span)+1]);
}

// min missed
int sparse_missed(int l,int r){
	int span=r-l+1;
	span=LG[span];
	return min(sparse_min[span][l],sparse_min[span][r-(1<<span)+1]);
}

void build_sparse(int lvl){

	for (int i=0;i<=n;i++){
		sparse_max[0][i]=max_taken[lvl][i];
		sparse_min[0][i]=min_missed[lvl][i];
	}

	for (int lev=1;lev<=11;lev++){
		for (int i=0;i+(1<<lev)-1<=n;i++){
			sparse_max[lev][i]=max(sparse_max[lev-1][i],sparse_max[lev-1][i+(1<<lev)/2]);
			sparse_min[lev][i]=min(sparse_min[lev-1][i],sparse_min[lev-1][i+(1<<lev)/2]);
		}
	}

}
int solve(int thold){
	for (int i=1;i<=n;i++){
		if (ar[i]<=thold)
			val[i]=1;
		else
			val[i]=0;
	}

	for (int i=1;i<=n;i++){
		S[i]=S[i-1]+val[i];
	}

	for (int i=0;i<=m;i++){
		for (int j=0;j<=n;j++){
			max_taken[i][j]=-1e9;
			min_missed[i][j]=1e9;
		}
	}

	max_taken[0][0]=min_missed[0][0]=0;

	int ret=0;

	for (int lev=1;lev<=m;lev++){

		build_sparse(lev-1);

		for (int i=0;i<=n;i++){
			max_taken[lev][i]=max_taken[lev-1][i];
			min_missed[lev][i]=min_missed[lev-1][i];
		}

		// no point in taking segment within other segment, so this should work

		for (int i=1;i<=n;i++){
			for (int j=0;j<ends_at[i].size();j++){
				int id=ends_at[i][j];

				// doesn't intersect : max_taken

				int not_intersect=sparse_taken(0,L[id]-1);
				int this_covers=S[R[id]]-S[L[id]-1];
				max_taken[lev][i]=max(max_taken[lev][i],not_intersect+this_covers);
				min_missed[lev][i]=min(min_missed[lev][i],S[i]-max_taken[lev][i]);

				// does intersect: min_missed

				int does_intersect=sparse_missed(L[id],R[id]);
				min_missed[lev][i]=min(min_missed[lev][i],does_intersect);
				max_taken[lev][i]=max(max_taken[lev][i],S[i]-min_missed[lev][i]);
			}
		}
	}

	for (int i=0;i<=n;i++){
		ret=max(ret,max_taken[m][i]);
	}
	return ret;
}

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	for (int i=2;i<=1500;i++){
		LG[i]=LG[i/2]+1;
	}

	cin>>n>>s>>m>>k;

	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}

	for (int i=1;i<=s;i++){
		cin>>L[i]>>R[i];
		ends_at[R[i]].push_back(i);
	}

	int l,r;

	l=0;
	r=1e9+1e6;

	while (l<r){
		int mid=l+r;
		mid/=2;
		int best=solve(mid);
		if (best>=k){
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	if (l>1e9+1e5)
		l=-1;

	cout<<l<<endl;



//	cin.get(); cin.get();
	return 0;
}