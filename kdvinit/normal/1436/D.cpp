/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int a[200001],mx[200001],cnt[200001],lft[200001];

void do_func(vector< vector<int> >& adj,int par,int chi) // '&' is veru Important here;
{
    int tmx=0,tcnt=0,tlft=0;
    int cmx=0,ccnt=0,clft;

    if(adj[chi].size()==1 && chi!=1)
    {
        tmx=a[chi];
        tcnt=1;
        tlft=0;
        mx[chi]=tmx; cnt[chi]=tcnt; lft[chi]=tlft;


        //cout<<chi<<" "<<mx[chi]<<" "<<cnt[chi]<<" "<<lft[chi]<<endl;

        return;
    }

    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        do_func(adj,chi,adj[chi][i]);

        cmx=mx[adj[chi][i]];
        ccnt=cnt[adj[chi][i]];
        clft=lft[adj[chi][i]];

        if(cmx<tmx)
        {
            tlft+=(tmx-cmx)*ccnt;
        }
        else
        {
            tlft+=(cmx-tmx)*tcnt;
            tmx=cmx;
        }

        tcnt+=ccnt;
        tlft+=clft;
    }

    if(tlft>=a[chi]) tlft-=a[chi];
    else
    {
        int x=a[chi]-tlft;
        int y=( (x-1)/tcnt )+1;
        tmx+=y;
        y*=tcnt;
        y-=x;
        tlft=y;
    }

    mx[chi]=tmx; cnt[chi]=tcnt; lft[chi]=tlft;

    //cout<<chi<<" "<<mx[chi]<<" "<<cnt[chi]<<" "<<lft[chi]<<endl;
}

void solve()
{
    int n;
    cin>>n;

    vector< vector<int> > adj(n+1);
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    for(int i=1;i<=n;i++) cin>>a[i];

    do_func(adj,0,1);
    cout<<mx[1]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}