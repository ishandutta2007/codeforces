/*
Can't they imagine that we (don't) need no more
no more fighting
'cause what is it for 
They all fooled us
These stupid rulers
Those who followed
soon were swallowed 
And what they told us has never been untrue Don't they feel
that there are other things to do 
What are they there for
If they rule no more
What are they there for 
Time to end the suffering
Out of nothing something
And we will not discuss it anymore 
Time to stop the fighting
Nowhere left for hiding
And on all of our leaders we wage war 
Time to stop the talking
Destiny is knocking
And you can't run away from the door 
All these discussions about these stupid wars
Only talking
as if they can't do more 
What the past shows
Is when fear grows
All these leaders
Talk like preachers 
Then they move people like puppets in a store
Without a feeling
They will move some more 
What are they there for
If they rule no more
What are they there for 
Time to end the suffering
Out of nothing something
And we will not discuss it anymore 
Time to stop the fighting
Nowhere left for hiding
And on all of our leaders we wage war 
Time to stop the talking
Destiny is knocking
And you can't run away from the door
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
#define bsize 1024

using namespace std;

int n,m,ar[1<<20];
int inblock[1<<15][30];
int sorted[1<<16];
string st;

int toadd[1000];

void unroll(int block)
{
    if (sorted[block]==0)return;
    int ptr;
    if (sorted[block]==2)
        ptr=25;
    else
        ptr=0;
    for (int i=0;i<26;i++)
        toadd[i]=inblock[block][i];
        
    for (int i=block*bsize;i<block*bsize+bsize;i++)
    {
        while (toadd[ptr]==0)
        {
            if (sorted[block]==1)
                ++ptr;
            else
                --ptr;
        }
        ar[i]=ptr;
        toadd[ptr]--;
    }
}

int have[200];

void update(int l,int r,int tp)
{
    if (l/bsize==r/bsize)
    {
        unroll(l/bsize);
        sorted[l/bsize]=0;
        sort(ar+l,ar+r+1);
        if (tp==1)
            reverse(ar+l,ar+r+1);
        return ;
    }
    
    unroll(l/bsize);
    unroll(r/bsize);
    sorted[l/bsize]=sorted[r/bsize]=0;
    
    for (int i=0;i<26;i++)
        have[i]=0;
        
    for (int i=l/bsize*bsize;i<l/bsize*bsize+bsize;i++)
    {
        if (i<l)continue;
        have[ar[i]]++;
        inblock[i/bsize][ar[i]]--;
    }
    
    for (int i=l/bsize+1;i<r/bsize;i++)
        for (int j=0;j<26;j++)
            have[j]+=inblock[i][j];
            
    for (int i=r/bsize*bsize;i<=r;i++)
    {
        have[ar[i]]++;
        inblock[i/bsize][ar[i]]--;
    }
    
    int ptr;
    
    if (tp==1)
        ptr=25;
    else 
        ptr=0;
    
    for (int i=l/bsize*bsize;i<l/bsize*bsize+bsize;i++)
    {
        if (i<l)continue;
        while (have[ptr]==0)
        {
            if (tp==0)++ptr;
            else
                --ptr;
        }
        ar[i]=ptr;
        inblock[i/bsize][ptr]++;
        have[ptr]--;
        //cout<<i<<"#"<<ptr<<endl;
    }
    
    //------------ PSi
    
    for (int i=l/bsize+1;i<r/bsize;i++)
    {
        for (int j=0;j<26;j++)
            inblock[i][j]=0;
            
        if (tp==0)
            sorted[i]=1;
        else
            sorted[i]=2;
        int toadd=bsize;
        while (toadd)
        {
            while (have[ptr]==0)
            {
                if (tp==0)
                    ++ptr;
                else
                    --ptr;
            }
            int can_add=min(have[ptr],toadd);
            inblock[i][ptr]=can_add;
            have[ptr]-=can_add;
            toadd-=can_add;
        }
    }
    
    // tail
    
    for (int i=r/bsize*bsize;i<=r;i++)
    {
        while (have[ptr]==0)
        {
            if (tp==0)++ptr;
            else
                --ptr;
        }
        ar[i]=ptr;
        inblock[i/bsize][ptr]++;
        have[ptr]--;
    }
    
    
}

int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;

cin>>st;

for (int i=0;i<st.size();i++)
{
    inblock[i/bsize][st[i]-'a']++;
    ar[i]=st[i]-'a';
}

for (;m;--m)
{
    int l,r,tp;
    cin>>l>>r>>tp;
    tp^=1;
    --l;
    --r;
    update(l,r,tp);
}

for (int i=0;i<=st.size()/bsize;i++)
{
    if (sorted[i]==0)
    {
        for (int j=i*bsize;j<i*bsize+bsize&&j<n;j++)
        {
            cout<<char(ar[j]+'a');
        }
    }
    else if (sorted[i]==1)
    {
        for (int j=0;j<26;j++)
        {
            for (int q=0;q<inblock[i][j];q++)
            {
                cout<<char(j+'a');
            }
        }
    }
    else
    {
        for (int j=25;j>=0;--j)
        {
            for (int q=0;q<inblock[i][j];q++)
            {
                cout<<char(j+'a');
            }
        }
    }
}

cout<<endl;

//cin.get();cin.get();
return 0;}