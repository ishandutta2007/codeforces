/*
In the middle of nowhere
Where the wild spruces grow
Stands a man with his chainsaw
Gloomy thoughts in his mind
Until my foot has gone to sleep I must have sawn
A million blocks of wood, no payment before
What a hell did I do wrong to deserve this trade
Feels like I'm a marionette, an errand boy, a slave
But I never give up
I will never give up
Gnawing bones, muscle cramps, backache
Coldness, warmth, heavy rains, mosquitos
And this goddamn saw that will never work
But with a madman's eyes I carry on, nothing they can do
A man with mystery
A man without history
A man with his story
A man with mystery
A man with mystery
A man without history
A man with his story
A man with mystery
*/

#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define INF 1000000000
using namespace std;
long a[200000],b[200000],qq;
vector <string> v;
string st,zr;
bool pm(string st)
{if (st.size()<4)return false;
 zr="lios";
 for (int j=1;j<=4;j++)
 if (st[st.size()-j]!=zr[4-j])return false;
 return true;
 }       

bool pz(string st)
{if (st.size()<5)return false;
zr="liala";
 for (int j=1;j<=5;j++)
 if (st[st.size()-j]!=zr[5-j])return false;
 return true;
}

bool sm(string st)
{if (st.size()<3)return false;
 zr="etr";
 for (int j=1;j<=3;j++)
 if (st[st.size()-j]!=zr[3-j]) return false;
 return true;
}

bool sz(string st)
{if (st.size()<4)return false;
 zr="etra";
 for (int j=1;j<=4;j++)
 if (st[st.size()-j]!=zr[4-j]) return false;
 return true;
 }

bool gm(string st)
{if (st.size()<6)return false;
zr="initis";
for (int j=1;j<=6;j++)
if (st[st.size()-j]!=zr[6-j])return false;
return true;
}

bool gz(string st)
{
 if (st.size()<6)return false;
 zr="inites";
 for (int j=1;j<=6;j++)
 if (st[st.size()-j]!=zr[6-j])return false;    
 return true;
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
while (cin>>st)
{//if (st=="-")break;
v.push_back(st);}
for (int i=0;i<v.size();i++)
{if (pm(v[i])){a[i]=1;b[i]=1;}
 if (pz(v[i])){a[i]=1;b[i]=2;}
 if (sm(v[i])){a[i]=2;b[i]=1;}
 if (sz(v[i])){a[i]=2;b[i]=2;}
 if (gm(v[i])){a[i]=3;b[i]=1;}
 if (gz(v[i])){a[i]=3;b[i]=2;}
}

qq=b[0];
if (qq==0)
{cout<<"NO"<<endl; return 0;}

for (int i=1;i<v.size();i++)
{if (b[i]!=qq){cout<<"NO"<<endl; return 0;}
}

if(v.size()==1){cout<<"YES"<<endl;}
else {
qq=0;
while (a[qq]==1){++qq;}
if (qq>=v.size()||a[qq]!=2){cout<<"NO"<<endl; return 0;}
++qq;
if (a[qq]==2){cout<<"NO"<<endl;return 0;}
while (a[qq]==3)++qq;
if (qq!=v.size()){cout<<"NO"<<endl; return 0;}
else cout<<"YES"<<endl;
}
cin.get();cin.get();
return 0;
}