/*
Cursed
Black magic night
We've been struck down
Down in this Hell
Spells surround me day and night
Stricken by the force of evil light
The force of evil light

Cast
Under his spell
Blinding my eyes
Twisting my mind
Fight to resist the evil inside
Captive of a force of Satan's might
A force of Satan's might

Fighting the curse
Break it I must
Laughing in sorrow
Crying in lust

My strength slips fast
Soon I must fall
Victim of fortune
My sources grow small
Life slips away
As demons come forth
Death takes my hand
And captures my soul
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <memory.h>
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
 
#define  INF 100000000
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
//#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

string st1,st2;
long q,w;
vector<long> ans;

int main(){
//freopen("processing.in","r",stdin);
//freopen("processing.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st1;
cin>>st2;
long q=0;
while (q<st1.size()&&q<st2.size()&&st1[q]==st2[q])++q;

w=st1.size();

while (w>0&&st1[w]==st2[w-1])--w;


//cout<<q<<" "<<w<<endl;

for (int i=w+1;i<=q+1;i++)
ans.push_back(i);
cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
    if (i)cout<<" ";
    cout<<ans[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}