/*
It's caving in around me
What I thought was solid ground
I tried to look the other way
But I couldn't turn around
It's OK for you to hate me
For all the things I've done
I've made a few mistakes
But I'm not the only one

Step away from the ledge
I'm coming down

I could never be
What you want me to
You pulled me under
To save yourself
(Save yourself)
You will never see
What's inside of me
I pulled you under just to save myself

Was there ever any question
On how much I could take? 
You kept feeding me your bullshit
Hoping I would break
Is there anybody out there? 
Is there anyone who cares? 
Is there anybody listening? 
Will they hear my final prayers? 

Step away from the ledge
I'm coming down

I could never be
What you want me to
You pulled me under
To save yourself
(Save yourself) 
You will never see
What's inside of me
I pulled you under just to save myself
(Save myself) 

It's caving in around me 
(Caving in)
It's tearing me apart
(Tearing me)
It's all coming down around me
(Coming down)
Does anyone
Anyone
Care at all? 

I will never be
What you want me to
You pull me under
I pull you under

I could never be
What you want me to
You pulled me under
To save yourself
(Save yourself)
You will never see
What's inside of me
I pulled you under just to save myself
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
#define eps 1e-6
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60

using namespace std;

long n,ar[200000],s;
long ans;
long reach[1000];

void dfs(long q)
{
     reach[q]=1;
     long rem=2*n-1-q;
     for (int inter=0;inter<=q;inter++)
     if (inter<=n)
     {
      if (n-inter<=rem){long tn=q-inter+(n-inter);
      if (reach[tn]==0)dfs(tn);}
     }
     
}

int main(){
//freopen("tape.in","r",stdin);
//freopen("tape.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=0;i<2*n-1;i++)
cin>>ar[i];
ans=-1000000;
sort(ar,ar+2*n-1);

reach[n]=1;
dfs(n);

//for (int i=0;i<=2*n-1;i++)
//cout<<i<<" "<<reach[i]<<endl;

for (int i=0;i<=2*n-1;i++)
if (reach[i])
{
             s=0;
             for (int j=0;j<i;j++)
             s-=ar[j];
             for (int j=i;j<2*n-1;j++)
             s+=ar[j];
             ans=max(ans,s);
}cout<<ans<<endl;

cin.get();cin.get();
return 0;}