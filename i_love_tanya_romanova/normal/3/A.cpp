/*
Blank stares from broken men
So withered from the poisons they can't remember when
There were once honest reasons.
It's all a lie, it died 100,000 miles ago.
Pretending I'm still here.
Justify what I've become, sanctify what I've become.
Amazing disgrace... (how) sweet the sound that saved a wretch like me.
Better lost if this is found, best blinded never to see.
The race to save face, nothing now is what we meant it to be.
Pretending I'm still here.
It's a system now, intertwined.
Take your place in the line to be ground by the gears of the masterpiece.
Betrayal.
Suffered consequence
It's been so long since any piece of this made any kind of sense.
You anoint the king, I'll burn everything down to ashes.
You giveth, I taketh away.
It's a system now, intertwined.
Take your place in the line to be ground by the gears of the masterpiece.
Betrayal.
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

string st1,st2;
vector<string> ans;
pair<long, long> s,t;

pair<long, long> parse(string st)
{
 pair<long, long> temp;
 temp.first=st[0]-'a'+1;
 temp.second=st[1]-'0';
 return temp;
}

int main(){
//freopen("elect.in","r",stdin);
//freopen("elect.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>st1;
cin>>st2;

s=parse(st1);
t=parse(st2);

//while (s!=t)
//{
      while (s.first<t.first&&s.second<t.second)
      {
       ans.push_back("RU");++s.first;++s.second;
      }
      
      while (s.first>t.first&&s.second>t.second)
      {
       ans.push_back("LD");--s.first;--s.second;
      }
      
      while (s.first<t.first&&s.second>t.second)
      {
       ans.push_back("RD");++s.first;--s.second;
      }
      while (s.first>t.first&&s.second<t.second)
      {
       ans.push_back("LU");--s.first;++s.second;
      }
      
      while (s.first<t.first)
      {
       ans.push_back("R");++s.first;
      }
      while (s.first>t.first)
      {
       ans.push_back("L");--s.first;
      }

      while (s.second<t.second)
      {
       ans.push_back("U");++s.second;
      }
      while (s.second>t.second)
      {
      ans.push_back("D");--s.second;
      }
      
      cout<<ans.size()<<endl;
      for (int i=0;i<ans.size();i++)
      cout<<ans[i]<<endl;
      
cin.get();cin.get();
return 0;}