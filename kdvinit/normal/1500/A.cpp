/*
K.D. Vinit  |,,|

Plz dont stalk me.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

map<int,int> mp;
map<int,int> mp2;

const int N = 2e5 + 5;
const int Inf = 1e7;
int a[N];
int used[N]={0};
int n;

void Search(int x)
{
    for(int i=1; i<=n; i++)
    {
        if(used[i]==1) continue;
        if(a[i]!=x) continue;
        used[i]=1;
        cout<<i<<" ";
        return;
    }
}

void print(int w, int x, int y, int z)
{
    int c[4]={w, x, y, z};
    sort(c, c+4);

    cout<<"YES"<<endl;
    Search(c[0]);
    Search(c[3]);
    Search(c[1]);
    Search(c[2]);
    cout<<endl;
}

void check_less()
{
    map<int, vector< array<int,2> > > mp;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            int sum = a[i] + a[j];
            mp[sum].push_back({i,j});
            int ms = mp[sum].size();
            if(ms==1) continue;

            for(int k=0; k<ms; k++)
            {
                int u = mp[sum][k][0];
                int v = mp[sum][k][1];
                if(u==i || u==j || v==i || v==j) continue;

                cout<<"YES"<<endl;
                cout<<i<<" "<<j<<" "<<u<<" "<<v<<endl;
                return;
            }
        }
    }

    cout<<"NO"<<endl;
    return;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=Inf;

    if(n>5000)
    {
        int b[n+2];
        for(int i=1; i<=n+1; i++) b[i]=a[i];
        sort(b+1, b+n+1);

        map<int,int> mp;

        int diff;

        for(int i=2; i<=n; i++)
        {
            int x = abs(b[i] - b[i-1]);
            int y = abs(b[i+1] - b[i]);
            mp[x]++;

            if(mp[x]==2)
            {
                diff=x;
                break;
            }

            if(x==y) i++;
        }

        vector<int> ind;
        for(int i=2; i<=n; i++)
        {
            int x = abs(b[i] - b[i-1]);
            if(x==diff)
            {
                ind.push_back(b[i-1]);
                ind.push_back(b[i]);
                if(ind.size()==4) break;
                i++;
            }
        }

        print(ind[0], ind[1], ind[2], ind[3]);
        return;
    }

    check_less();
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}