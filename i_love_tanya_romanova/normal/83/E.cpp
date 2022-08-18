/*
Im not the devil
But I can show my horns
All the things I did to you
Could have been in a porn
Then I heard the rumors
Now I know theyre true
Some strange motherfucker
Is gonna do 'em to you

I said I loved you but you didnt listen
I know theres another dick in the system
I said I loved you but you didnt listen
I know theres another dick in the system

Ive lived with angels
Ive laid with whores
I gave you nothing but honesty
Then I licked your sores
Im not the one to crucify
With blood, iron and wood
Youre not the saviour to me anymore
Youre damaged goods Yeah

I said I loved you but you didnt listen
I know theres another dick in the system
I said I loved you but you didnt listen
I know theres another dick in the system

I said I loved you but you didnt listen
I know theres another dick in the system
I said I loved you but you didnt listen
I know theres another dick in the system
Hey Hey
Hey Hey
Hey Hey Hey
Hey Hey Hey
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

int n;
string st;
int m;
int ar[1<<20];
int dp[22][1<<21];
int add_all;

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
    cin>>st;
    m=st.size();
    for (int j=0;j<st.size();j++)
    {
        ar[i]=ar[i]*2+st[j]-48;
    }
}

for (int i=0;i<=20;i++)
    for (int j=0;j<=(1<<m);j++)
        dp[i][j]=1e9;

add_all=m;

dp[0][0]=0;

for (int i=2;i<=n;i++)
{
    int memo=add_all;
    int F=0;
    for (int j=m;j;--j)
    {
        if ((ar[i]>>(m-j))==(ar[i-1]&((1<<j)-1)))
            {F=j;break;}
    }
    add_all+=m-F;
//  cout<<i<<"   "<<F<<endl;
    
    int bst=1e9;
    for (int j=0;j<=m;j++)
    {
        bst=min(bst,dp[j][ar[i]>>(m-j)]+(m-j));
    }
    for (int j=0;j<=m;j++) // i W other, i-1 becomes tail
    {
        int tail=(ar[i-1]&((1<<j)-1));
        dp[j][tail]=min(dp[j][tail],bst+(memo-add_all));
    }
}

int ans=1e9;
for (int i=0;i<=m;i++)
    for (int j=0;j<(1<<m);j++)  
        ans=min(ans,dp[i][j]);

cout<<ans+add_all<<endl;

//cin.get();cin.get();
return 0;}