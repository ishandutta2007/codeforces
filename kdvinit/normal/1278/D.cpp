/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mxn=5e5+1;
int parent[mxn];
int siz[mxn];

void make_set(int v)
{
    parent[v] = v;
    siz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b) return true;

    if (siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
    return false;
}

void solve()
{
    int n;
    cin>>n;

    int ind[2*n+1],type[2*n+1],l,r;
    for(int i=1;i<=n;i++)
    {
        make_set(i);
        cin>>l>>r;
        ind[l]=i;
        type[l]=0;
        ind[r]=i;
        type[r]=1;
    }

    vector<int> seg;
    int cnte=0;
    for(int i=1;i<=2*n;i++)
    {
        if(type[i]==0)
        {
            seg.push_back(ind[i]);
        }
        else
        {
            int m=seg.size();
            for(int j=m-1;j>=0;j--)
            {
                if(seg[j]==ind[i])
                {
                    seg.erase(seg.begin()+j);
                    break;
                }

                cnte++;
                if(union_sets(ind[i],seg[j]))
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }

    if(cnte!=n-1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}