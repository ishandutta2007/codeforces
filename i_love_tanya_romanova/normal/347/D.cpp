/*
Are we left all alone?
Mother has no time but she cares for me
and she cried all the tears
I am joining now the river flow
I am three days old
Now the time has come
You have to be man
I don't want to destroy
the only chance I have
to survive down here
The wind blows I'm so scared
and the waves so big, I'm not prepared
I will have to be strong
but for now I cry all the tears

Now enter the storm and feel electric sword
My entire life is about to burn
I am struggling, life is illusion
But I keep the dream of a better time

This secret knowledge
I receive from where I am
So precious the treasured icons
Extended to this point
Forget the ones that hurt
They all want, they struggle
They fight and try to dry their tears

We are all left on our own
We are bound yet by each others lives
Now I'm leaving this world
I will never forget the river flow

The pains and traps of life
I put my scars away and love

I have to face the truth of living
I left my boat behind
I am not taking it
Where I go I won't be crying
I die
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
#include <memory.h>

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
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 250
#define clone agsdahfaassdg

using namespace std;

string temp,st1,st2,v;
long bmatch[200][200];
long fl;
long ai,aj,aq;
pair<long, long> tp1,tp2;

long nxt1[200][200],nxt2[200][200],dp[125][125][125];
long aa,bb,cc;
pair<long, long> par1[125][125][125],par2[125][125][125];
vector<char> av;

int main(){
//freopen("police.in","r",stdin);
//freopen("police.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st1;
cin>>st2;
cin>>v;

for (int i=0;i<v.size();i++)
{
    for (char ad='A';ad<='Z';++ad)
    {
        temp="";
        for (int j=0;j<i;j++)
        temp+=v[j];
        temp+=ad;
//        cout<<i<<" "<<ad<<" "<<temp<<endl;
        
        bmatch[i][ad]=0;
        for (int j=i;j+1;--j)
        {
            fl=0;
            for (int q=i;q>=j;--q)
            if (q-j>=v.size()||v[q-j]!=temp[q])fl=1;
            if (fl==0)
            bmatch[i][ad]=i-j+1;
            
        }
//        if (bmatch[i][ad]>0)cout<<i<<" "<<ad<<" "<<bmatch[i][ad]<<endl;
    }
}

for (int i=0;i<st1.size();i++)
for (int ch='A';ch<='Z';ch++)
{
    nxt1[i][ch]=1000;
    for (int q=st1.size()-1;q>=i;--q)
    if (st1[q]==ch)nxt1[i][ch]=q;
}


for (int i=0;i<st2.size();i++)
for (int ch='A';ch<='Z';ch++)
{
    nxt2[i][ch]=1000;
    for (int q=st2.size()-1;q>=i;--q)
    if (st2[q]==ch)nxt2[i][ch]=q;
}

long answ=-1;

for (int i=0;i<=st1.size();i++)
for (int j=0;j<=st2.size();j++)
for (int q=0;q<=v.size();q++)
dp[i][j][q]=-1000000;
dp[0][0][0]=0;

for (int i=0;i<st1.size();i++)
for (int j=0;j<st2.size();j++)
for (int com=0;com<v.size();com++)
{
    for (int chad='A';chad<='Z';chad++)
    {
        if (bmatch[com][chad]==v.size())continue;
        aa=nxt1[i][chad];
        bb=nxt2[j][chad];
        if (aa>=st1.size())continue;
        if (bb>=st2.size())continue;
        cc=bmatch[com][chad];
//     if (i==8&&j==1&&com==1)
 //     cout<<i<<" "<<j<<" "<<com<<" "<<aa<<" "<<bb<<" "<<cc<<" "<<char(chad)<<endl;
        if (dp[aa+1][bb+1][cc]<=dp[i][j][com])
        {
         dp[aa+1][bb+1][cc]=dp[i][j][com]+1;
         par1[aa+1][bb+1][cc]=make_pair(i,j);
         par2[aa+1][bb+1][cc]=make_pair(com,chad);
  //       answ=max(answ,dp[aa+1][bb+1][cc]);
  if (dp[aa+1][bb+1][cc]<=answ)continue;
   ai=aa+1;aj=bb+1;aq=cc;answ=dp[aa+1][bb+1][cc];
        }
    }
};
//cout<<dp[11][5][0]<<endl;

if (answ<0)cout<<0<<endl;
else
{
    for (int q=1;q<=answ;q++)
    {
        tp1=par1[ai][aj][aq];
        tp2=par2[ai][aj][aq];
        av.push_back(tp2.second);
        ai=tp1.first;
        aj=tp1.second;
        aq=tp2.first;
    }
reverse(av.begin(),av.end());
for (int i=0;i<av.size();i++)
cout<<av[i];
cout<<endl;
}
cin.get();cin.get();
return 0;}