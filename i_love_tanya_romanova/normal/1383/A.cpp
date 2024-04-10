/*
Strut on by like a king
Telling everybody they know nothing
And long live what you thought you were
And time ain't on your side anymore (anymore)

And so you tell me I
Can't take my chances
But I told you one too many times
And you were crying like a bitch

I'm tougher than nails
I can promise you that
Step out of line
And you get bitch-slapped back
And you can run
Your little mouth all day
But the hand of god
Just smacked you back into yesterday

And so you tell me I
Can't take my chances
But I told you one too many times
And you were crying like a bitch

And you wonder why
No one can stand you
And there's no denying
You were crying like a bitch
You were crying like a bitch

Blinded by your sacred faded past times
Only time is your enemy
Granted a second chance
To prove that your arrogance
Is stronger than you'll ever be
Is stronger than you can be

Oh stronger than you can be
Oh stronger than you can (be)

And so you tell me I
Can't take my chances
But I told you one too many times
And you were crying like a bitch

And you wonder why
No one can stand you
And there's no denying
You were crying like a bitch

You were crying like a bitch
You were crying like a bitch
You were crying like a bitch

Oh Bitch
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

#define bs 1000000007

const int N = 500031;

int tests,ar[100][100],closure[100][100];
string st1,st2;
int ans;
int n;
int mask_have[100];
int mask_need[1000];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	 cin>>n;
	 for (int i=0;i<26;i++){
		 mask_need[i]=0;
		 for (int j=0;j<26;j++){
			 ar[i][j]=0;
			 closure[i][j]=0;
		 }
	 }
	 cin>>st1;
	 cin>>st2;
	 bool shit=0;
	 for (int i=0;i<st1.size();i++)
	 {
		 if (st1[i]>st2[i])
			 shit=1;
		 ar[st1[i]-'a'][st2[i]-'a']=1;
	 }


	 if (shit)
	 {
		 cout<<-1<<endl;
		 continue;
	 }

	 for (int i=0;i<26;i++){
		 mask_have[i]=(1<<i);
		 for (int j=i+1;j<26;j++){
			 if (ar[i][j])
				 mask_need[i]|=(1<<j);
		 }
	 }


	 int res=0;
	 for (int i=25;i>=0;--i){
		 for (int j=i+1;j<26;j++){
			 if (mask_need[i]&mask_have[j]){
				 res++;
				 mask_have[i]|=mask_have[j];
				 for (int q=0;q<26;q++){
					 if ((mask_need[i]&(1<<q))&&(mask_have[j]&(1<<q))){
						 mask_need[i]^=(1<<q);
					 }
				 }
			 }
		 }
	 }

	 cout<<res<<endl;

  }

  cin.get(); cin.get();
  return 0;
}