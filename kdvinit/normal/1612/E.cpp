/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5;
int msg[N+1], kk[N+1], n;

double expec(int l)
{
    int add[N+1]={0};
    for(int i=1; i<=n; i++)
    {
        if(kk[i]>=l) add[msg[i]]+=l;
        else add[msg[i]]+=kk[i];
    }
    sort(add+1, add+N+1);

    //cout<<"Hello"<<endl;

    //for(int i=1; i<=N; i++)
//    {
//        if(add[i]!=0) cout<<i<<" -> "<<add[i]<<endl;
//    }

    //cout<<"Hello"<<endl;

    double tot=0;
    for(int i=1; i<=l; i++) tot+=add[N-i+1];
    tot/=l;
    return tot;
}

void printl(int l)
{
    int add[N+1]={0};
    for(int i=1; i<=n; i++)
    {
        //cout<<i<<" -> "<<msg[i]<<" "<<kk[i]<<endl;
        if(kk[i]>=l) add[msg[i]]+=l;
        else add[msg[i]]+=kk[i];
    }

    vector<pair<int, int>> vec;
    for(int i=1; i<=N; i++) vec.push_back({add[i], i});
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    cout<<l<<endl;
    for(int i=0; i<l; i++) cout<<vec[i].second<<" ";
    cout<<endl;
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++) cin>>msg[i]>>kk[i];

    double val=0;
    int ansl=0;

    for(int i=1; i<=100; i++)
    {
        double cur = expec(i);
        if(cur>val) { val=cur; ansl=i; }
    }

    printl(ansl);
}

int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}