/*
Dogs of war  
Dogs of war  
Dogs of war 
Dogs of war 
Dogs of war 

You be a fightin' man 
Make all the cash you can 
Don't mix and feel your tide 
They wanna risk their lives 
Takin' all you can 
Riskin' ain't in the plan 
Feel the boots upon the ground 
Trouble brewin' all around 
Dodgin' the bullets, shootin' the missiles 
Soldiers of fortune, such a pretty name 
Face the game 
Mercenary thing 

We be the dogs of war (Soldier of fortune) 
We'll be the dogs of war (Soldier of fortune) 
Call in the dogs of war (Soldier of fortune) 
Send in the dogs of war (Soldier of fortune) 

I'll fire-fight in the night 
Run away or die of fright 
Keep in time, keep in line 
Where there's smoke, there's fire 
Dodgin' the bullets, shootin' the missiles 
Soldiers of fortune, such a pretty name 
Face the game 
You mercenary man 

We be the dogs of war (Soldier of fortune) 
We be the dogs of war (Soldier of fortune) 
Call in the dogs of war (Soldier of fortune) 
Bring in the dogs of war (Soldier of fortune) 
We be the dogs of war 

Dogs of war 
Dogs of war 
Call in the dogs of war 

Dogs of war (Soldier of fortune) 
We be the dogs of war (Soldier of fortune) 
Call in the dogs of war (Soldier of fortune) 
Send in the dogs of war (Soldier of fortune) 

Marchin' through the nightness 
Those mercenary men
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

int n;
int tests;
string st;
set<int> let;
set<int>::iterator it;
int L,R;
int cur[1<<20];
int cnt;
int eval(int a,int b)
{
    if (a+1<=b)
        return b-a;
    return 0;
}

int ans;

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>tests;
cin>>st;
let.insert(0);
let.insert(n+1);

for (int i=0;i<st.size();i++)
{
    if (st[i]=='.')
    {
        ++cnt;
        cur[i+1]=1;
    }
    else
    {
        cur[i+1]=0;
        let.insert(i+1);
        if (cnt>1)
            ans+=cnt-1;
        cnt=0;
    }
}

if (cnt>1)
    ans+=cnt-1;

for (;tests;--tests)
{
    int id;
    string tst;
    cin>>id;
    cin>>tst;
    int tp=(tst[0]=='.');
    
    if (tp==cur[id])
    {
        cout<<ans<<endl;
        continue;
    }
    
    if (tp==0) //. -> l
    {
        it=let.lower_bound(id);
        R=(*it);
        --it;
        L=(*it);
        ans-=eval(L+1,R-1);
        let.insert(id);
        ans+=eval(L+1,id-1);
        ans+=eval(id+1,R-1);
    }
    else
    {
        it=let.lower_bound(id);
        ++it;
        R=(*it);
        --it;
        --it;
        L=(*it);
        ans+=eval(L+1,R-1);
        let.erase(id);
        ans-=eval(L+1,id-1);
        ans-=eval(id+1,R-1);
    }
    
    cur[id]=tp;
    cout<<ans<<endl;
}
//cin.get();cin.get();
return 0;}