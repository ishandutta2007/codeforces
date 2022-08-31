/*
Oh!

Time in arguments will end
Flames of preparation
Fingers felt the whipping
Hand that feeds the flame

Escalate the droughts
Itching to join the fray

Wishing that darkness was sound
Shutting desires out
Wishing that darkness was sound
But as moths to the flame we go

You the ignorant
Take sides in these three dimensions
Nullify importance
Confined within the page

Scan for rapture again
Look for an instant save, uoh
Wishing that darkness was sound
Shutting desires out
Wishing that darkness was sound
But as moths to the flame we go

Mere moments pass and still it seems
Detached from insight, thought and word
Oh, ever since it lost its edge
Lost in the noise forever be
In the blur of information
The nail that never sticks
The nail that never sticks

White noise is the sound
The clarity, uh

White noise - black silence

Ih-ah!
Venting a foul stench
Purging the fevered self
Behind a traitor's name

Face the consequence
Taken back in the eyes of fairness
A nobody forever
Hidden and locked away

Working the boards again
Giving the wrath away, uh-ah

Wishing that darkness was sound
Shutting desires out
Wishing that darkness was sound
But as moths to the flame... we go
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

string st;
string res;
int cnt1;
int flag;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>st;

	for (int i=0;i<st.size();i++){
		if (st[i]=='1')
			cnt1++;
	}

	for (int i=0;i<st.size();i++){
		if (st[i]=='0')
			res+='0';
		else if (st[i]=='1'){
			continue;
		}
		else
		{
			if (st[i]=='2'){
				if (flag==0){
					for (int j=0;j<cnt1;j++){
						res+='1';
					}
				}
				flag=1;
				res+=st[i];
			}
		}
	}
	if (flag==0)
		for (int i=0;i<cnt1;i++){
			res+='1';
		}

	cout<<res<<endl;

//	cin.get(); cin.get();
	return 0;
}