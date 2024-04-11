#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010,S=31,D=1010;

bitset<N> sw[S];
bool in_basis[S];
int mask[S];
set<int> can[S];

bool cmp1(const bitset<N>&x,const bitset<N>&y)
{
    return x._Find_first()<y._Find_first();
}

bool cmp2(const pair<bitset<N>,int>&x,const pair<bitset<N>,int>&y)
{
    return x.first._Find_first()<y.first._Find_first();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,s,d;
    cin>>n>>s>>d;
    n=N;
    for(int i=1;i<=s;i++)
    {
        int c;
        cin>>c;
        while(c--)
        {
            int x;
            cin>>x;
            sw[i].set(x);
        }
    }
    int a=0,b=0;
    {
        vector<bitset<N>> basis;
        for(int i=1;i<=s;i++)
        {
            auto x=sw[i];
            for(const auto&y:basis)
                if(x._Find_first()==y._Find_first())
                    x^=y;
            if(x.any())
            {
                basis.push_back(x);
                in_basis[i]=true;
                sort(basis.begin(),basis.end(),cmp1);
                a++;
            }
            else
            {
                in_basis[i]=false;
                b++;
            }
        }
    }
    for(int i=1;i<=s;i++)
        for(int j=i+1;j<=s;j++)
            if(!in_basis[i]&&in_basis[j])
                swap(sw[i],sw[j]),
                swap(in_basis[i],in_basis[j]);
    vector<pair<bitset<N>,int>> basis;
    for(int i=1;i<=s;i++)
    {
        auto x=sw[i];
        for(const auto&y:basis)
            if(x._Find_first()==y.first._Find_first())
                x^=y.first,
                mask[i]^=y.second;
        if(x.any())
        {
            mask[i]^=1<<i;
            basis.push_back({x,mask[i]});
            sort(basis.begin(),basis.end(),cmp2);
        }
    }
    if(a>=b)
    {
        while(d--)
        {
            int c;
            cin>>c;
            bitset<N> cur;
            while(c--)
            {
                int x;
                cin>>x;
                cur.set(x);
            }
            int cur_mask=0;
            for(const auto&y:basis)
                if(cur._Find_first()==y.first._Find_first())
                    cur^=y.first,
                    cur_mask^=y.second;
            if(cur.any())
            {
                cout<<-1<<"\n";
                continue;
            }
            int ans=100;
            for(int take=0;take<(1<<b);take++)
            {
                int now_mask=cur_mask;
                for(int i=0;i<b;i++)
                    if((take>>i)&1)
                        now_mask^=mask[a+1+i];
                ans=min<int>(ans,__builtin_popcount(take)+__builtin_popcount(now_mask));
            }
            cout<<ans<<"\n";
        }
    }
    else
    {
        vector<int> masks;
        for(int i=a+1;i<=a+b;i++)
            masks.push_back(mask[i]);
        sort(masks.begin(),masks.end());
        masks.erase(unique(masks.begin(),masks.end()),masks.end());
        b=masks.size();
        for(int take=0;take<(1<<b);take++)
        {
            int now_mask=0;
            for(int i=0;i<b;i++)
                if((take>>i)&1)
                    now_mask^=masks[i];
            can[__builtin_popcount(take)].insert(now_mask);
        }
        while(d--)
        {
            int c;
            cin>>c;
            bitset<N> cur;
            while(c--)
            {
                int x;
                cin>>x;
                cur.set(x);
            }
            int cur_mask=0;
            for(const auto&y:basis)
                if(cur._Find_first()==y.first._Find_first())
                    cur^=y.first,
                    cur_mask^=y.second;
            if(cur.any())
            {
                cout<<-1<<"\n";
                continue;
            }
            int ans=100;
            for(int now_mask=0;now_mask<(1<<a);now_mask++)
                for(int i=0;i<=s;i++)
                    if(can[i].count(now_mask))
                        ans=min<int>(ans,i+__builtin_popcount(cur_mask^now_mask));
            cout<<ans<<"\n";
        }
    }
}