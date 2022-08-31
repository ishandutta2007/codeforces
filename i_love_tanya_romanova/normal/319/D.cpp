/*
I see no light
Fade to black
Kiss the cheek then coincide

Identify then crucify

Force-feeding your ideals
Coerced against my will
A prophecy the second coming
A forecast haunting me
Forgive and be forgiven

A hypocrisy deceiving me
Hypnotizing with your religion
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
#define bsize 512

using namespace std;

string S;
int n;
char st[3][200000];
int cur,nxt;

int main(){
//freopen("gadgets.in","r",stdin);
//freopen("gadgets.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>S;
n=S.size();
for (int i=0;i<n;i++)
    st[1][i]=S[i];

cur=1;
nxt=1;

for (int len=1;len<=n/2;len++)
{
    int tn=n;
    int l=0;
    int cnt=0;
    cur=len%2;
    int C=0;
    nxt=(1^cur);
    for (int i=0;i<n;i++)
    {
        st[nxt][C]=st[cur][i];
        ++C;
        if (i+len<n&&st[cur][i]==st[cur][i+len])
            ++l;
        else
            l=0;
        if (l==len)
        {
            C-=l;
            tn-=l;
            l=0;
        }
    }
    n=tn;
/*    for (int i=0;i<n;i++)
        cout<<st[nxt][i];
    cout<<endl;*/
}

for (int i=0;i<n;i++)
    cout<<st[nxt][i];
cout<<endl;
//cin.get();cin.get();
return 0;}