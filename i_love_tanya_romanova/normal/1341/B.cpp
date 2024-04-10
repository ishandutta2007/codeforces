/*
Tic toc, time is up
Tic toc, time is up!

(I know you!)
You're the one on the magazine covers and everyone loves ya
(Such a star!)
You're the one everyone wants to be like, but no one can be

Mother may I have a moment?
Feel I've come undone
Can you stop me from this spinning?
Nowhere left to run

Special's a term they use to describe someone when they're afraid to admit that they're right!

(I see you!)
You're the one that's in all of the movies, on everyone's TVs
(Such a farce!)
You're convinced that your shit doesn't stink and we all should adore you

Father can you stop this bleeding?
Hate what we've become
I've turned my cheek so many times
Fear I'm almost done!

Death is a term that they use to describe something they can't accept because it comes with a price!

Tic toc
Tic toc

Grant me the serenity to accept the things I cannot change, the courage to change the things I can and the wisdom to know the difference

Father can you stop this bleeding?
Hate what we've become
I've turned my cheek so many times
Fear I'm almost done!
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

const int N = 200031;

int tests,n,k,ar[N];
int S[N];
int peak[N];
int ans_ps;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	 cin>>n>>k;
	 for (int i=1;i<=n;i++){
		 cin>>ar[i];
	 }
	 for (int i=1;i<=n;i++){
		 if (i>1&&ar[i]>ar[i-1]&&i<n&&ar[i]>ar[i+1])
			 peak[i]=1;
		 else
			 peak[i]=0;
	 }
	 for (int i=1;i<=n;i++){
		 S[i]=S[i-1]+peak[i];
	 }
/*	 for (int i=1;i<=n;i++){
		 cout<<S[i]<<" ";
	 }
	 cout<<endl;
*/
	 ans_ps=1;
	 for (int i=2;i+k-1<=n;i++){
		 if (S[i+k-2]-S[i]>S[ans_ps+k-2]-S[ans_ps])
			 ans_ps=i;
	 }
	 cout<<S[ans_ps+k-2]-S[ans_ps]+1<<" "<<ans_ps<<endl;
  }

  cin.get(); cin.get();
  return 0;
}