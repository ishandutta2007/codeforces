/*
I could not breath against the wall
The clash of light against the floor
They held me up against the wall
Too young to be ignored

Standing by a building
Leaks out information
Passive death of freedom gets me
Where's my security
Behind my back it goes
Early morning's coming
The risk that I am taking
Recall a song that I heard as a child
No more false immunity
Inside the blistering cold

My youth unknown to me
I'm walking by a wire
What's left from me to breathe
Cold smell of fire
One day I will be free
I was born to be no one
My youth unknown to me
I walked behind the sun

Emptiness within me
Exit signs within me
The one you're looking for is not here
Had no security
He will not come back
*/

#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <memory.h>
#include <stdio.h>

#include <algorithm>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

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

#define eps 1e-12
#define M_PI 3.141592653589793
#define bsize 1024

#define ldouble long double
using namespace std;

#define bs 998244353

const int N = 610031;

map<string,int> mapp;
queue<string> qu,emp;

string mutate(string st,int l,int r){
	string ret;
	for (int i=0;i<l;i++){
		ret+=st[i];
	}
	ret+=st[r];
	for (int i=l;i<st.size();i++){
		if (i!=r)
			ret+=st[i];
	}
	return ret;
}

int solve(string st1,string st2){
	mapp.clear();
	mapp[st1]=0;
	qu=emp;
	qu.push(st1);
	while (qu.size()){
		string S=qu.front();
		qu.pop();
		for (int i=0;i<S.size();i++){
			for (int j=i+1;j<S.size();j++){
				string temp=mutate(S,i,j);
				if (mapp.find(temp)!=mapp.end())
					continue;
				mapp[temp]=mapp[S]+1;
				qu.push(temp);
			}
		}
	}
	return mapp[st2];
}

string get_random_string(int len,int alph){
	string ret;
	for (int i=0;i<len;i++){
		int here=rand()%alph;
		ret+=char(here+'a');
	}
	return ret;
}

int dp[2031][2031];
int cnt1[2031][100],cnt2[2031][100],imba[2031];

bool is_good(int l,int r){
	for (int i=0;i<26;i++){
		if (cnt2[r][i]<cnt1[l][i])
			return false;
	}
	return true;
}

int smart_solve(string st1,string st2){

	for (int i=0;i<st1.size();i++){
		for(int j=0;j<26;j++){
			cnt1[i][j]=0;
			cnt2[i][j]=0;
		}
		imba[i]=0;
	}
	for (int i=0;i<st1.size();i++){
		for (int j=0;j<26;j++){
			cnt1[i+1][j]=cnt1[i][j];
			cnt2[i+1][j]=cnt2[i][j];
		}
		cnt1[i+1][st1[i]-'a']++;
		cnt2[i+1][st2[i]-'a']++;
	}


	for (int i=0;i<=st1.size();i++){
		for (int j=0;j<=st2.size();j++){
			dp[i][j]=-1e9;
		}
	}

	dp[0][0]=0;

	if (!is_good(st1.size(),st1.size()))
		return -1;
	for (int i=0;i<st1.size();i++){
		for (int j=0;j<st2.size();j++){
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
				dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
			if (st2[j]==st1[i]&&is_good(i,j))
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
		}
	}

	/*for (int i=0;i<=st1.size();i++){
		for (int j=0;j<=st2.size();j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/

	int ret=0;
	for (int i=0;i<=st1.size();i++){
		for (int j=0;j<=st2.size();j++){
			ret=max(ret,dp[i][j]);
		}
	}
	return st1.size()-ret;
}


int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

 // cout<<smart_solve("abc","cba")<<endl;
 // cout<<smart_solve("aabab","abaab")<<endl;
/*
  while (true);

  while (true){
	  int len,alph;
//	  cin>>len>>alph;
	  len=rand()%10+1;
	  alph=rand()%6+1;

	  string S=get_random_string(len,alph);
	  string s1,s2;
	  s1=S;
	  random_shuffle(S.begin(),S.end());
	  s2=S;
	  cout<<s1<<" "<<s2<<" "<<solve(s1,s2)<<" "<<smart_solve(s1,s2)<<endl;
	  if (solve(s1,s2)!=smart_solve(s1,s2)){
		  cout<<"CRAP"<<endl;
		  while (true);
	  }
  }*/

  int tests;

  cin>>tests;
  for (;tests;--tests){
	  int n;
	  cin>>n;
	  string st1,st2;
	  cin>>st1>>st2;
	  cout<<smart_solve(st1,st2)<<endl;
  }
  cin.get(); cin.get();
  return 0;
}