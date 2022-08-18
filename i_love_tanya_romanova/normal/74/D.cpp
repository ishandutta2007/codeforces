/*
Lost in a shadow
The planet rolls like a ball
Darkness will follow
And soon the whole thing will fall

'Cause now I'm able
To see the little light
'Cause now I'm able
To know what's in the sky

Ground is shaking
And it's still far away
Sure it's coming
The drama is on its way

'Cause this is much faster
Than a runaway star
Too brilliant
To watch it with my eyes

Radical abortion
Impulsive conclusion
All things good get their end
Even vast, no man's land

Too many reasons
Too much oppression
My mind's mutation
With my psychic power
Imploring the quasar

There is no freedom
No satisfaction
I want some action
With my psychic power
Everything is over

That's why I do that
That's why it's a fact
Why do I regret
Nothing better yet

Sky is red
And nature falls in disgrace
Space is dread
There's no place to be safe

The quasar is coming
Ordered by my mind
Spreading X-rays
Making the system blind

Astral rotation
Turning the wrong way
Solar collision
Causing the end of this age

Comets flying
Emanating a gas
Intoxicating
Every form of life

For a lost dimension
Have a wise solution
Better now than never
Don't need more, you neither

Too many reasons
Too much oppression
My mind's mutation
With my psychic power
Imploring the quasar

There is no freedom
No satisfaction
I want some action
With my psychic power
Everything is over

That's why I do that
That's why it's a fact
Why do I regret
Nothing better yet

The final process
Hard and so complex
Reverse the motion
Adding some tension

Setting the machine
Awaiting to leave
My bones and my soul
On my way back home

Have a look behind
Nothing more to find
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
#define time asdfasdfasfd

using namespace std;

int n,queries;
vector<int> values,uvalues;
map<int, int> mapp;
set<pair<int, int> > seg;
set<int>cp;
int t[1<<20];
int tp[1<<20];
int a[1<<20],b[1<<20];
map<int, int> cnt;
map<int, int> pos;
int placed[1<<20];

int get(int v,int tl,int tr,int l,int r)
{
    if (l>r)
        return 0;
    if (tl==l&&tr==r)
        return t[v];
    int tm=tl+tr;
    tm/=2;
    return get(v*2,tl,tm,l,min(r,tm))+get(v*2+1,tm+1,tr,max(tm+1,l),r);
}

void update(int v,int tl,int tr,int ps,int val)
{
    if (tl==tr)
    {
        t[v]=val;
        return ;
    }
    int tm=tl+tr;
    tm/=2;
    if (ps<=tm)
        update(v*2,tl,tm,ps,val);
    else
        update(v*2+1,tm+1,tr,ps,val);
    t[v]=t[v*2]+t[v*2+1];
}

int get_free()
{
    set<pair<int, int> > ::iterator it;
/*  for (it=seg.begin();it!=seg.end();it++)
    {
        cout<<"!"<<(*it).first<<" "<<(*it).second<<endl;
    }
*/  
    it=seg.end();
    --it;
    pair<int, int> tp=(*it);
    seg.erase(it);
    int l,r;
    l=tp.second;
    r=l+tp.first-1;
    int tomiss=tp.first/2;
    int res=l+tomiss;
    if (res>l)
        seg.insert(make_pair(res-l,l));
    if (res<r)
        seg.insert(make_pair(r-res,res+1));
    
    cp.insert(res);
    
//  cout<<"@!"<<res<<endl;
    
    return res;
}

void remove_position(int ps)
{
    set<int> ::iterator it;
    it=cp.upper_bound(ps);
    int val1=(*it);
    --it;
    --it;
    int val2=(*it);
    if (val1>ps+1)
        seg.erase(make_pair(val1-1-ps,ps+1));
    if (val2<ps-1)
        seg.erase(make_pair(ps-val2-1,val2+1));
    seg.insert(make_pair(val1-val2-1,val2+1));
    cp.erase(ps);
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>queries;
seg.insert(make_pair(n,1));
cp.insert(0);
cp.insert(n+1);

for (int i=1;i<=queries;i++)
{
    int val;
    cin>>val;
    if (val==0)
    {
        tp[i]=0;
        cin>>a[i]>>b[i];
        values.push_back(a[i]);
        values.push_back(b[i]);
        continue;
    }
    
    if (cnt[val]%2==0)
    {
        cnt[val]++;
        tp[i]=1;
        int ps=get_free();
        values.push_back(ps);
        pos[val]=ps;
        placed[i]=ps;
        continue;
    }
    
    cnt[val]++;
    tp[i]=2;
    int ps=pos[val];
    placed[i]=ps;
    remove_position(ps);
    values.push_back(ps);
}

sort(values.begin(),values.end());

for (int i=0;i<values.size();i++)
    if (i==0||values[i]!=values[i-1])
    {
        uvalues.push_back(values[i]);
        mapp[values[i]]=uvalues.size();
    }
/*
for (int i=1;i<=queries;i++)
{
    cout<<tp[i]<<" "<<mapp[placed[i]]<<endl;
}*/

int N=uvalues.size();

for (int i=1;i<=queries;i++)
{
    if (tp[i]==0)
    {
    //  cout<<"@"<<
        cout<<get(1,1,N,mapp[a[i]],mapp[b[i]])<<endl;
        continue;
    }
    placed[i]=mapp[placed[i]];
    if (tp[i]==2)
        update(1,1,N,placed[i],0);
    else
        update(1,1,N,placed[i],1);
}

//cin.get();cin.get();
return 0;}