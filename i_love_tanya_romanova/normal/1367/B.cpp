/*
A fistful of fear in my hands
A bullet of betrayal in my brain
No progress comes from pleasure
We smile in ignorance and learn in pain

Willful deceit was your plan
Desperately avoid the blame
Who will you answer to now?
Sharpened your shovels just to dig your grave

Stand up because the ground is in your way
I won't give you any peace!
Yet still you talk
Try to fight but I will watch you fall

This is a sweet revenge
And karma's a bitch
You glutton for punishment
What did you expect?

Sick, sick, sick
I'm sick of being your martyr
Your inflated ego is just dead weight
Bask in all the eyes upon you
Before you know it they'll have turned away

Stand up as the whole world turns away
I won't give you any peace
Wait and see
Cry yourself a lonesome creek
Your decaying corpse can feed the roots of my towering tree
Wait and see
You're dead to me
Yet still you speak
Trying to justify what you're doing to me
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

#define bs 1020202009

const int N = 100031;

int tests,n,c[N];

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	 cin>>n;
	 c[0]=c[1]=0;
	 for (int i=0;i<n;i++){
		 int val;
		 cin>>val;
		 if (val%2==i%2)
			 continue;
		 c[val%2]++;
	 }
	 if (c[0]!=c[1])
		 cout<<-1<<endl;
	 else
		 cout<<c[0]<<endl;
  }


  cin.get(); cin.get();
  return 0;
}