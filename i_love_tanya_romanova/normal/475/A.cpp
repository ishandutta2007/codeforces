/*
No fear
No fear

Girl
You lived your life like a sleeping sword
Your time has come
To go deeper

Girl
Your final journey's just begun
Your destiny
Chose the weapon

No fear
Destination darkness
No fear
Destination darkness
No fear

Girl
Rain falls down from the coldest skies
Like poisoned knifes
With no mercy

Girl
Close your eyes for the one last time
Sleepless nights
From here to eternity

No fear
Destination darkness
No fear
Destination darkness
No fear

Destination darkness

Destination darkness

No fear
Destination darkness
No fear
Destination darkness

No fear
Destination darkness
No fear
Destination darkness
No fear
*/

//#pragma comment(linker, "/STACK:16777216")
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,found;
vector<string> ans;

int main(){
//freopen("dial.in","r",stdin);
//freopen("dial.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

ans.push_back("+------------------------+");
ans.push_back("|#.#.#.#.#.#.#.#.#.#.#.|D|)");
ans.push_back("|#.#.#.#.#.#.#.#.#.#.#.|.|");
ans.push_back("|#.......................|");
ans.push_back("|#.#.#.#.#.#.#.#.#.#.#.|.|)");
ans.push_back("+------------------------+");
cin>>n;
for (;n;--n){
 found=0;
 for (int j=0;j<100&&found==0;j++)
  for (int i=0;i<ans.size()&&found==0;i++)
  {
   if (ans[i][j]=='#'&&found==0)
   {
    found=1;
    ans[i][j]='O';
   }
  }
}
for (int i=0;i<ans.size();i++)
cout<<ans[i]<<endl;

cin.get();cin.get();
return 0;}