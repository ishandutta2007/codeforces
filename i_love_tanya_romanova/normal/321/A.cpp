/*
Good day, how do? 
And I send a smile to you 
Don't waste, waste your breath 
And I won't waste my hate on you 

Ain't gonna waste my hate 
Ain't gonna waste my hate on you 
I think I'll keep it for myself 
Ain't gonna give no more 
Ain't got the time to help you score 
I think it's time you pleased yourself, yourself 

Good day, how do? 
And I send a smile to you 
Don't waste, waste your breath 
And I won't waste my hate on you, waste my hate on you 

Think you're worthy now 
You think enough to even raise the brow 
And to laugh and tip that two pronged crown 
Well I see my hands, I see my feet 
I feel that blood that pumps in beat 
But where the hell's my mind goin' now, goin' now 

Good day, how do? 
And I send a smile to you 
Don't waste, waste your breath 
And I won't waste my hate on you, waste my hate on you 
I feel I'll keep it for myself 

Ain't gonna waste my hate 
But I'm so greedy when they say, "Better to give than to receive" 
Ain't gonna waste my hate 
No, no ain't got time to waste my hate on you 
Yea, I think I keep it all for myself, for myself 

Good day, how do? 
And I send a smile to you 
Don't waste, waste your breath 
And I won't waste my hate on you, waste my hate on you 
I think I keep it all for myself 
Hate
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
#define lr asgasgash
 
#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3

using namespace std;

long long n,m,shx[1000],shy[10000],tx,ty,fl;
string st;
long long mx,my;


void check(long long x,long long y)
{
     if (x!=0&&mx==0)return;
     if (y!=0&&my==0)return;
//     if (x==0&&mx==0&&y==0&&my==0)fl=1;
     if (mx!=0){
     if (x%mx)return;
     x/=mx;
     }
     
     if (my!=0)
     {if (y%my)return;
     y/=my;
     }
     if (y<0)return;
     if (x<0)return;
     if (my!=0&&mx!=0)
     if (x!=y)return;
     fl=1;
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
cin>>st;
for (int i=0;i<st.size();i++)
{
    shx[i+1]=shx[i];shy[i+1]=shy[i];
    if (st[i]=='U')shy[i+1]++;
    if (st[i]=='D')shy[i+1]--;
    if (st[i]=='L')shx[i+1]--;
    if (st[i]=='R')shx[i+1]++;
}

mx=shx[st.size()];
my=shy[st.size()];

for (int i=0;i<=st.size();i++)
{
 tx=n-shx[i];
 ty=m-shy[i];
 check(tx,ty);
}
if (fl)cout<<"Yes"<<endl;
else cout<<"No"<<endl;

cin.get();cin.get();
return 0;}