/*
I can't run away from the thing in me
I'm weakening down another now developing
Within

I can feel it it's inside my head
Connected to my brain this other me is
Slowly taking over deep beneath the
Eye that
All can see energetic visions of the one
I know myself to be

Look into my eyes don't listen to their lies

How can i stop this from being real
No my life will be no longer what it always
Used to be

Life neglected infected by strain
I fall into the smothering the even
Flow of
Ravaging pain this my temple of selfcaged
Contempt a body slowly pierced by
Inevitable me

Do i differ from yourself am i like
They say
The truth eventually i'm the one you
Wanna be
Can you feel the same as i another inside
Pushing to free itself from the chains
Of the soul

Turn your eyes toward the inside
Dig deep within i'm sure you'll find
A different self a different soul
To put you in peace with mind
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

const int N = 100031;

vector<int> starts;
int g[500][500],gr[500][500];
string st[N];
int n,cnt_in[N],cnt_out[N];
vector<int> ans;
int need[N];
int ent_here[N];
int used[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n;

	for (int i=1;i<=n;i++){
		cin>>st[i];
		for(int j=0;j<26;j++){
			ent_here[j]=0;
		}

		for (int j=0;j<st[i].size();j++){
			int id=st[i][j]-'a';
			ent_here[id]++;
			need[id]=1;
			if (ent_here[id]>1){
				cout<<"NO"<<endl;
				return 0;
			}
		}

		for (int j=0;j+1<st[i].size();j++){
			char a=st[i][j];
			char b=st[i][j+1];
			a-='a';
			b-='a';
			g[a][b]=1;
			gr[b][a]=1;
		}
	}

	for (int i=0;i<26;i++){
		for (int j=0;j<26;j++){
			if (g[i][j]){
				cnt_in[j]++;
				cnt_out[i]++;
			}
		}
	}

	for (int i=0;i<26;i++){
		if (cnt_in[i]>1||cnt_out[i]>1)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}

	for (int i=0;i<26;i++){
		if (cnt_in[i]==0&&(cnt_out[i]>0||need[i]>0))
			starts.push_back(i);
	}

	for (int i=0;i<starts.size();i++){
		int cur=starts[i];
		while (true){
			used[cur]=1;
			ans.push_back(cur);
			if (cnt_out[cur]==0)
				break;
			int nxt=-1;
			for (int q=0;q<26;q++){
				if (g[cur][q])
					nxt=q;
			}
			cur=nxt;
		}
	}

	for (int i=0;i<26;i++){
		if (need[i]>used[i])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}

	for (int i=0;i<ans.size();i++){
		cout<<char(ans[i]+'a');
	}
	cout<<endl;

//	cin.get(); cin.get();
	return 0;
}