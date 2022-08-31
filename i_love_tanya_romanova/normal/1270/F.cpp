/*
We remember, no surrender
Heroes of our century

3 men stood strong, and they held out for long
Going into the fight, to their death that awaits
Crazy or brave, will it end in the grave?
As they're giving their lives
As their honor dictates

Far, far from home, to a war
Fought on foreign soil and
Far, far from known, tell their tale,
Their forgotten story
Cobras fumantes, eterna  sua vitria

Rise from the blood of your heroes
You, were the ones who refused to surrender
The 3, rather died than to flee,
Know that your memory,
Will be sung for a century

3 took the blow, while impressing their foe
Throwing dice, with their lives
As they're paying the price
Sent to raise hell, hear the toll of the bell
It is calling for you as the Wehrmacht devised

Sent over seas to be cast into fire
Fought for a purpose with pride and desire
Blood of the brave they would give to inspire
Cobras fumantes, your memory lives!
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
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery

#define eps 1e-9
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 200031;

string st;
long long ans;
int cnt;

const int MAGIC=200;
//const int MAGIC = 1;

vector<int> V;
long long S;
int n;
int pref[N];
vector<int> ones;
int ar[N];

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
   // ios_base::sync_with_stdio(0);
 //   cin.tie(0);

	cin>>st;
	n=st.size();

	// no zeros at all
	for (int i=0;i<st.size();i++){
		if (st[i]=='1')
			++cnt;
		else
		{
			ans+=1ll*cnt*(cnt+1)/2;
			cnt=0;
		}
	}
	ans+=1ll*(cnt)*(cnt+1)/2;

	// small ratios
	for (int rat=1;rat<MAGIC;rat++){
		V.clear();
		V.push_back(0);
		S=0;
		for (int i=0;i<n;i++){
			if (st[i]=='0')
				S--;
			else
				S+=rat;
			V.push_back(S);
		}
		sort(V.begin(),V.end());
		cnt=0;
		for (int i=0;i<V.size();i++){
			if (V[i]!=V[i-1]){
				ans+=1ll*cnt*(cnt-1)/2;
				cnt=0;
			}
			cnt++;
		}
		ans+=1ll*cnt*(cnt-1)/2;
	}

	//cout<<ans<<endl;

	for (int i=1;i<=st.size();i++){
		if (st[i-1]=='0')
			ar[i]=0;
		else
			ar[i]=1;
	}

	for (int i=1;i<=n;i++){
		pref[i]=pref[i-1]+ar[i];
	}

	for (int i=1;i<=n;i++){
		if (ar[i]==1)
			ones.push_back(i);
	}

	ones.push_back(n+1);

	for (int start=1;start<=n;start++){
		int total_before=pref[start-1];
		int bound=total_before+n/MAGIC+5;
		bound=min(bound,pref[n]);
		for (int i=total_before+1;i<=bound;i++){
			int pos_to_look=ones[i-1];
			int upper_limit=ones[i]-1;
			int low_len=pos_to_look-start+1;
			int hi_len=upper_limit-start+1;
			// ans increases by count of multiples
			int cnt_ones=i-total_before;
			int lowest_multiple=(low_len-1)/cnt_ones+1;
			int highest_multiple=(hi_len)/cnt_ones;
			// multiple here is for length, therefore rat=MAGIC-1 covered MAGIC in part above - shouldn't count it here.
			lowest_multiple=max(lowest_multiple,MAGIC+1);
			if (lowest_multiple<=highest_multiple)
				ans+=highest_multiple-lowest_multiple+1;
		}
	}

	cout<<ans<<endl;

    //    cin.get(); cin.get();
    return 0;
}