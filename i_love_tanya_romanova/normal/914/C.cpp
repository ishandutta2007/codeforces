/*
Hey... Look around you
Everything's helter-skelter
Listen up... I warn you
Run for cover, run
Bang... It happened
Time's up, Armageddon
Fire... Meltdown
The sky is crumbling in

Black Curtains... Never ending

Escape... You're joking
Can't find no place to run
Hair... Is burning
My flesh is bubbling up
Blood... Is boiling
Taste copper on my tongue
Fate... Is coming
Welcome it with a smile

Black Curtains... Never ending, fall

Am I dreaming? My heart pounds my chest
Held for ransom in spider's web
Suffocating, no one hears my calls
Never ending, till the black curtains falls

Snakes... Surround me
Offering their death kiss to me
Down... I'm drowning
How long, I hold my breath
Dogs... Are chasing
My legs are paralyzed
Pray... Don't find me
My life is fading fast
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

string st;
int k;
long long dp[1031][2][1031];
long long ans;

int count_iters(int x){
	if (x==1)
		return 0;
	int c=0;
	while (x){
		c+=x%2;
		x/=2;
	}
	return count_iters(c)+1;
}

int good[1031];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>st;
	cin>>k;

	if (k==0){
		cout<<1<<endl;
		return 0;
	}

	for (int i=1;i<=1000;i++){
		int Q=count_iters(i);
		if (Q+1==k){
			good[i]=1;
		}
	}

	dp[0][0][0]=1;
	for (int i=0;i<st.size();i++){
		for (int flag=0;flag<=1;flag++){
			for (int cnt1=0;cnt1<st.size();cnt1++){
				for (int ad=0;ad<=1;ad++){
					if (ad==1&&st[i]=='0'&&flag==0)
						continue;
					dp[i+1][flag|(ad<st[i]-'0')][cnt1+ad]+=dp[i][flag][cnt1];
					dp[i+1][flag|(ad<st[i]-'0')][cnt1+ad]%=bs;
				}
			}
		}
	}

	for (int i=0;i<=1000;i++){
		for (int j=0;j<=1;j++){
			if (good[i])
				ans+=dp[st.size()][j][i];
			ans%=bs;
		}
	}

	if (k==1){
		ans=ans+bs-1;
		ans%=bs;
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}