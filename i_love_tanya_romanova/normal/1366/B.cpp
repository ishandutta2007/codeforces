/*
The doom, the doom
The doom of all fires
The ghost, the ghost
The ghost of all martyrs
The dust, the dust
The dust of empires
The roar, the roar
The roar of the lion
The crash, the trash
The crash of the west
The grind, the mind
The grind of all life
The horror, the sorrow
The horror of all sorrows
The pain, the hate
The song remains insane

Unrest, the last retaliation is red
The few, the youth
And now you must kill
The roar, the war
The roar of the war
The sick, the weak
Awaken in their sleep
The fallen not forgotten
Shall inherit this earth
The blood, the flood
The blood and the fire
The hate, the fate
The hate of the land
Incinerate the hate
Apocalyptic rage
Beyond, beyond
Will thrash and burn
The call, the call
The call of the unknown
The fall, the fall
The fall of Babylon
Inflikted, inflikted
Muthafuckin' wicked
Slaughter, slaughter,
Slay without sorrow
Tomorrow, tomorrow
Will bring the new order
The storm, the storm
I follow the storm
Ta'foda, ta'foda, detona mixhell
They tell me about a place, another race
Another life, another world without a trace
A world without name
They tell me about a place
Where they don't stab you in the back
They don't spit in your face
They don't shame on your name
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

const int N = 610031;

int tests,n,x,m,l[N],r[N];
int cur_l,cur_r;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", sttextdout);
  ios_base::sync_with_stdio(0);
  // cin.tie(0);

  cin>>tests;
  for (;tests;--tests){
	 cin>>n>>x>>m;
	 for (int i=1;i<=m;i++){
		 cin>>l[i]>>r[i];
	 }
	 cur_l=x;
	 cur_r=x;
	 for (int i=1;i<=m;i++){
		 if (max(cur_l,l[i])<=min(cur_r,r[i])){
			 cur_l=min(cur_l,l[i]);
			 cur_r=max(cur_r,r[i]);
		 }
	 }
	 cout<<cur_r-cur_l+1<<endl;
  }

  cin.get(); cin.get();
  return 0;
}