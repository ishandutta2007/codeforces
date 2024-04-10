/*
I want to reach out
And touch the sky
I want to touch the stuff
But I don't need to fly

I'm gonna climb up
every mountain on the moon
And find the dish
that ran away with the spoon

I've crossed the ocean, turned every bend
I found the plastic and the golden rainbow's end
I've been through magic and through life's reality
I've lived a thousand years and it never bothered me

Got no religion
Don't need no friends
Got all I want
And I don't need to pretend

Don't try to reach me
'Cause I'd tear up your mind
I've seen the future
And I've left it behind
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

string LAN;
int L;
int tp[1000];
int n,rules;
int tp1[1<<20],tp2[1<<20];
int a[1<<20],b[1<<20];
int tried[1<<20];
vector<int> ans;
int flag;

int get(char x)
{
    if (x=='V')
        return 0;
    return 1;
}

string INPUT;
int have[10];
int error;

vector<int> order;
int used[1<<20];
vector<int> g[1<<20],gr[1<<20];
int comps;

void add_edge(int a,int b)
{
//  cout<<a<<" ! "<<b<<endl;
    
    g[a].push_back(b);
    gr[b].push_back(a);
}

void dfs1(int v)
{
    used[v]=1;
    for (int i=0;i<g[v].size();i++)
    {
        int to=g[v][i];
        if (used[to])
            continue;
        dfs1(to);
    }
    order.push_back(v);
}

void dfs2(int v)
{
    used[v]=comps;
    if (error)
        return;
    if (v<n&&used[v+n]==used[v])
        error=1;
    if (v>=n&&v<n*2&&used[v-n]==used[v])
        error=1;
    if (v>=n*2&&v<n*3&&used[v]==used[v+n])
        error=1;
    if (v>=n*3&&used[v]==used[v-n])
        error=1;
    
    for (int i=0;i<gr[v].size();i++)
    {
        int to=gr[v][i];
        if (used[to])
            continue;
        dfs2(to);
    }
}

int calls;

void check(int ps, int T)
{
//  cout<<"@"<<endl;
    //cout<<ps<<"@"<<T<<endl;
    
    ++calls;
    
    for (int i=0;i<4*n;i++)
        g[i].clear(),
        gr[i].clear();
    
    for (int i=0;i<4*n;i++)
        g[i].reserve(8),
        gr[i].reserve(8);
        
    order.clear();
    for (int i=0;i<4*n;i++)
        used[i]=0;
    comps=0;
    
    for (int i=0;i<n;i++) // basic 2sat
    {
        add_edge(i,i+3*n);
        add_edge(i+3*n,i);
        add_edge(i+n,i+2*n);
        add_edge(i+2*n,i+n);
    }
    
    for (int i=0;i<ans.size();i++) // constraints from pref
    {
        int id=ans[i];
        id=tp[id];
        if (id==0)
            add_edge(i,i+n),
            add_edge(i+3*n,i+2*n);
        else
            add_edge(i+n,i),
            add_edge(i+2*n,i+3*n);
    }
    
    if (T==0) // put 0 here
        add_edge(ps,ps+n),
        add_edge(ps+3*n,ps+2*n);
    
    if (T==1)// put 1 here
        add_edge(ps+n,ps),
        add_edge(ps+2*n,ps+3*n);
    
    if (have[1]==0)// all letters =0
    for (int i=0;i<n;i++)
            add_edge(i,i+n),
            add_edge(i+3*n,i+2*n);
    
    if (have[0]==0)//all letters =1
    for (int i=0;i<n;i++)
            add_edge(i+n,i),
            add_edge(i+2*n,i+3*n);
        
    for (int i=1;i<=rules;i++)
    {
//      cout<<tp1[i]<<"%"<<tp2[i]<<endl;
        if (tp1[i]==0&&tp2[i]==0)
            add_edge(a[i]+2*n,b[i]+2*n),
            add_edge(b[i]+3*n,a[i]+3*n);
        if (tp1[i]==0&&tp2[i]==1)
            add_edge(a[i]+2*n,b[i]),
            add_edge(b[i]+n,a[i]+3*n);
        if (tp1[i]==1&&tp2[i]==0)
            add_edge(a[i],b[i]+2*n),
            add_edge(b[i]+3*n,a[i]+n);
        if (tp1[i]==1&&tp2[i]==1)
            add_edge(a[i],b[i]),
            add_edge(b[i]+n,a[i]+n);
    }
    
    for (int i=0;i<n*4;i++)
    {
        if (used[i])
            continue;
        dfs1(i);
    }
    
    reverse(order.begin(),order.end());
    for (int i=0;i<n*4;i++)
        used[i]=0;
    for (int i=0;i<order.size();i++)
    {
        int id=order[i];
        if (used[id])
            continue;
        ++comps;
        dfs2(id);
        if (error)
            break;
    }
    
    for (int i=0;i<n;i++)
        if (used[i]==used[i+n]||used[i+n*2]==used[i+n*3])
            {
            error=1;
            break;
            }
    
}

vector<int> R[1<<20];
int invalid[500][4];

void update(int aa,int bb)
{
    int T=tp[bb];
    for (int i=0;i<R[aa].size();i++)
    {
        int id=R[aa][i];
        if (tp1[id]==T)
            invalid[b[id]][1^tp2[id]]=1;
    }
}
int main(){
//freopen("blind.in","r",stdin);
//freopen("blind.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>LAN;
L=LAN.size();

for (int i=0;i<L;i++)
    tp[i]=get(LAN[i]);

for (int i=0;i<L;i++)
    have[tp[i]]=1;
    
cin>>n>>rules;
string st=" ";
char c;
for (int i=1;i<=rules;i++)
{
//  cin>>a[i];
    scanf("%d",&a[i]);
    scanf("%c",&c);
    scanf("%c",&c);
//  cout<<a[i]<<endl;
//  cin>>st;
//  cout<<"@"<<c<<endl;
    tp1[i]=get(c);
    scanf("%c",&c);
    scanf("%d",&b[i]);
//  cout<<b[i]<<endl;
//  cin>>b[i];
//  cin>>st;
    scanf("%c",&c);
    scanf("%c",&c);
    tp2[i]=get(c);
    --a[i];
    --b[i];
    R[a[i]].push_back(i);
}

cin>>INPUT;
//cout<<"!!"<<INPUT<<endl;

// same string
for (int i=0;i<INPUT.size();i++)
{
    ans.push_back(INPUT[i]-'a');
}

int val=ans.back();
val=tp[val];
ans.pop_back();
error=0;
check(n-1,val);
if (error==0)
{
    ans.push_back(INPUT[INPUT.size()-1]-'a');
    for (int i=0;i<ans.size();i++)
        cout<<char(ans[i]+'a');
    cout<<endl;
    return 0;
}

ans.clear();

// com pref shit now


flag=0;

int LCP=-1;

for (int i=n-1;i+1;i--)
{
    int l;
    
    ans.clear();
    for (int j=0;j<i;j++)
        ans.push_back(INPUT[j]-'a');
    
    if (flag==0)
        l=INPUT[i]-'a';
    else
        l=0;
    
    l=INPUT[i]-'a'+1;
    
    int found=-1;
    tried[0]=tried[1]=0;
    
    for (int j=l;j<L;j++)
    {
        int ths=tp[j];
        
        if (tried[ths])
            continue;
        tried[ths]=1;
        error=0;
        check(i,ths);
        if (error)
            continue;
        found=j;
        if (j!=l)
        {
            flag=1;
        }
        break;
    }
    
    if (found!=-1) // nice
    {
        LCP=i;
        break;
    }
}

//cout<<"@@"<<LCP<<endl;

if (LCP==-1) // shit
{
    cout<<-1<<endl;
    return 0;
}

// now pick answer

ans.clear();

for (int i=0;i<LCP;i++)
{   
    ans.push_back(INPUT[i]-'a');
    update(i,INPUT[i]-'a');
}

for (int i=LCP;i<n;i++)
{
    
    int l;
    
    if (i==LCP)
        l=INPUT[i]-'a'+1;
    else
        l=0;
    
    int found=-1;
    tried[0]=tried[1]=0;
    
    for (int j=l;j<L;j++)
    {
        int ths=tp[j];
        if (invalid[i][ths])
            continue;
        
        if (invalid[i][1^ths])
        {
            found=j;
            break;
        }
        
        if (tried[ths])
            continue;
        tried[ths]=1;
        error=0;
        check(i,ths);
        if (error)
            continue;
        found=j;
        
        break;
    }
    
    ans.push_back(found);
    update(i,found);
}

for (int i=0;i<ans.size();i++)
{
    cout<<char(ans[i]+'a');
}
cout<<endl;

    
//cin.get();cin.get();
return 0;}