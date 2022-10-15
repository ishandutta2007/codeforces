/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 998244353;
int k, A, h;
int Rank[100], powa[100];

int Rank_List(int bm, vector<int> p1)   //returns winner
{
    int cr = 1+(p1.size());
    while(p1.size()!=1)
    {
        vector<int> p2; int m = p1.size();
        for(int i=0; i<m; i+=2)
        {
            int x=(bm%2); bm/=2; int y=x^1;
            int px=p1[i+x]; int py=p1[i+y];
            Rank[px]=cr;
            p2.push_back(py);
        }
        p1=p2; cr=(cr/2)+1;
    }
    Rank[p1[0]]=2;
    return p1[0];
}

int Get_Hash(int l, int r)
{
    int val=0;
    for(int i=l; i<=r; i++)
    {
        int cur = (i*powa[Rank[i]])%mod;
        val=(val+cur)%mod;
    }
    return val;
}

void print_rank(int n)
{
    for(int i=1; i<=n; i++) cout<<Rank[i]<<" ";
    cout<<endl;
}

void solve()
{
    cin>>k>>A>>h;
    int n = 1<<(k);
    int n2 = n/2;

    powa[0]=1;
    for(int i=1; i<100; i++) powa[i]=(powa[i-1]*A)%mod;

    vector<int> p1, p2;
    for(int i=1; i<=n2; i++) p1.push_back(i);
    for(int i=n2+1; i<=n; i++) p2.push_back(i);

    map<int, int> pos1, bm1, pos2, bm2;
    vector<array<int, 3>> hbw1, hbw2;       //hash, bitmask, winner;

    int m = 1<<(n2-1);
    for(int bm=0; bm<m; bm++)
    {
        int w1 = Rank_List(bm, p1); int c1 = Get_Hash(1, n2);
        int w2 = Rank_List(bm, p2); int c2 = Get_Hash(n2+1, n);
        pos1[c1]=1; bm1[c1]=bm;
        pos2[c2]=1; bm2[c2]=bm;
        hbw1.push_back({c1, bm, w1});
        hbw2.push_back({c2, bm, w2});
    }

    for(auto x: hbw1)
    {
        int h1 = x[0]; int cb1 = x[1]; int w1 = x[2];
        int t1 = (w1*powa[2])%mod; int t2 = (w1*powa[1])%mod;
        h1 = (h1-t1+t2)%mod; 
        int h2 = (h-h1)%mod; if(h2<0) h2+=mod;
        if(pos2[h2]==0) continue;
        int cb2 = bm2[h2];
        Rank_List(cb1, p1); Rank[w1]=1;
        Rank_List(cb2, p2);
        print_rank(n);
        return;
    }

    for(auto x: hbw2)
    {
        int h2 = x[0]; int cb2 = x[1]; int w2 = x[2];
        int t1 = (w2*powa[2])%mod; int t2 = (w2*powa[1])%mod;
        h2 = (h2-t1+t2)%mod;
        int h1 = (h-h2)%mod; if(h1<0) h1+=mod;
        if(pos1[h1]==0) continue;
        int cb1 = bm1[h1];
        Rank_List(cb1, p1);
        Rank_List(cb2, p2); Rank[w2]=1;
        print_rank(n);
        return;
    }

    cout<<-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}