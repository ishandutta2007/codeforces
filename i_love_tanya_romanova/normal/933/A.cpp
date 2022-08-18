/*
I am a man
Cut from the know
Rarely do friends
Come and then go
She was a girl
Soft but estranged
We were the two
Our lives rearranged
Feeling so good that day
A feeling of love that day

[Chorus:]
Twisting and turning
Your feelings are burning
You're breaking the girl
She meant you no harm
Think you're so clever
But now you must sever
You're breaking the girl
He loves no one else

Raised by my dad
Girl of the day
He was my man
That was the way
She was the girl
Left alone
Feeling the need
To make me her home
I don't know what when or why
The twilight of love had arrived

[Chorus]
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

const int N = 2031;

int n,ar[N],dp_pref[N][N],dp_suf[N][N];
int dp_rev[N][N][3][3];

int ans;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}

	for (int i=1;i<=n;i++){
		for (int old=1;old<=2;old++){
			dp_pref[i][old]=max(dp_pref[i][old],dp_pref[i-1][old]);
			if (ar[i]<old)
				continue;
			dp_pref[i][ar[i]]=max(dp_pref[i][ar[i]],dp_pref[i-1][old]+1);
		}
	}

	for (int i=n;i>=1;--i){
		for(int old=1;old<=2;old++){
			dp_suf[i][old]=max(dp_suf[i][old],dp_suf[i+1][old]);
			if (ar[i]>old)
				continue;
			dp_suf[i][ar[i]]=max(dp_suf[i][ar[i]],dp_suf[i+1][old]+1);
		}
	}

	for (int start=n;start>=1;--start){
		for (int i=start;i>=1;--i){
			for (int old=1;old<=2;old++){
				for (int fi=1;fi<=2;fi++){
				if (old<fi)
					continue;
					dp_rev[start][i][old][fi]=max(dp_rev[start][i][old][fi],dp_rev[start][i+1][old][fi]);
				if (ar[i]<old)
					continue;
				dp_rev[start][i][ar[i]][fi]=max(dp_rev[start][i][ar[i]][fi],dp_rev[start][i+1][old][fi]+1);
				}
			}
		}
	}

	ans=max(dp_pref[n][1],dp_pref[n][2]);

	for (int l=1;l<=n;l++){
		for (int r=l;r<=n;r++){
			for (int p1=1;p1<=2;p1++){
				for (int p2=p1;p2<=2;p2++){
					for (int p3=p2;p3<=2;p3++){
						for (int p4=p3;p4<=2;p4++){
							// mid starts at r,ends at l, fi after rev becomes p2, last after rev becomes p3
							int here=dp_pref[l-1][p1]+dp_rev[r][l][p3][p2]+dp_suf[r+1][p4];
							ans=max(ans,here);
						}
					}
				}
			}
		}
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}