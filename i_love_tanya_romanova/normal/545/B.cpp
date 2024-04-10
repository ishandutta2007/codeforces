/*
Life it seems to fade away
Drifting further everyday
Getting lost within myself
Nothing matters no one else
I have lost the will to live
Simply nothing more to give
There is nothing more for me
Need the end to set me free

Things not what they used to be
Missing one inside of me
Deathly loss this can't be real
Cannot stand this hell I feel
Emptiness is filling me
To the point of agony
Growing darkness taking dawn
I was me but now, he's gone

No one but me can save myself, but its too late
Now I can't think, think why I should even try

Yesterday seems as though it never existed
Death greets me warm, now I will just say goodbye
Goodbye
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

string st1,st2;
int cnt;
int need;

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1;
cin>>st2;
for (int i=0;i<st1.size();i++)
 if (st1[i]!=st2[i]) ++cnt;
if(cnt&1)
 cout<<"impossible"<<endl;
 else
 {
    need=cnt/2;
    for (int i=0;i<st1.size();i++)
    {
        if (st1[i]==st2[i]||need==0)
         cout<<st1[i];
        else
        {
            --need;
            cout<<st2[i];
        }
    }
    cout<<endl;
 }
 
//cin.get();cin.get();
return 0;}