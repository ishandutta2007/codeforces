/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 1;
int child[N];

void get_child(vector<int> adj[], int c, int p)
{
    int sum=1;
    for(int i=0;i<adj[c].size();i++)
    {
        int cc=adj[c][i];
        if(cc==p) continue;
        get_child(adj, cc, c);
        sum+=child[cc];
    }
    child[c]=sum;
}

int fibu, fibv, val_fibv;
bool find_fib(vector<int> adj[], int c, int p, int fib1, int fib2)
{
    for(int i=0;i<adj[c].size();i++)
    {
        int cc=adj[c][i];
        if(cc==p) continue;

        if(child[cc]==fib1 || child[cc]==fib2)
        {
            fibu=c;
            fibv=cc;
            val_fibv=child[cc];
            return true;
        }

        if(find_fib(adj, cc, c, fib1, fib2)) return true;
    }
    return false;
}

bool check_fib_tree(vector<int> adj[], int root, int fib)
{
    if(fib==1 || fib==2 || fib==3) return true;

    int x=1, y=1, z=2;
    while(z<fib)
    {
        x=y;
        y=z;
        z=x+y;
    }

    if(z!=fib) return false;

    get_child(adj, root, -1);

    if(find_fib(adj, root, -1, x, y)==1)
    {
        for(int i=0; i<adj[fibu].size(); i++)
        {
            if(adj[fibu][i]==fibv)
            {
                adj[fibu].erase(adj[fibu].begin() + i);
                break;
            }
        }

        for(int i=0; i<adj[fibv].size(); i++)
        {
            if(adj[fibv][i]==fibu)
            {
                adj[fibv].erase(adj[fibv].begin() + i);
                break;
            }
        }

        int fv = fibv, fu = fibu, vv = val_fibv, vu = (fib-val_fibv);

        int f1 = check_fib_tree(adj, fv, vv);
        int f2 = check_fib_tree(adj, fu, vu);

        if(f1==1 &&  f2==1) return true;
        else return false;
    }

    else return false;
}

void solve()
{
    int n;
    cin>>n;

    vector<int> adj[n+1];
    for(int i=1;i<n;i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(check_fib_tree(adj, 1, n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}