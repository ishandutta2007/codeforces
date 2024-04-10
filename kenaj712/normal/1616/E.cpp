#include<bits/stdc++.h>
using namespace std;
int tab1[1000005];
int tab2[1000005];
int pot = (1<<20);
int tree[3000005];
bool odw[1000005];
vector<int> v[105];
vector<int> updates;
void ins(int a)
{
    updates.push_back(a);
    int pom = a + pot;
    while(pom != 0)
    {
        tree[pom]++;
        pom /= 2;
    }
}
void usun(int a)
{
    int pom = a + pot;
    while(pom != 0)
    {
        tree[pom]--;
        pom /= 2;
    }
}
int check(int a,int b)
{
    int l = a + pot, r = b + pot;
    if(l > r)
        return 0;
    int war = tree[l];
    if(l != r)
        war += tree[r];
    while(l/2 != r/2)
    {
        if(l % 2 == 0)
            war += tree[l+1];
        if(r % 2 == 1)
            war += tree[r-1];
        l/=2;
        r/=2;
    }
    return war;
}
void wczytaj(int a)
{
    string c,d;
    cin>>c>>d;
    for(int x=0;x<a;x++)
    {
        tab1[x+1] = c[x] - 'a';
        v[c[x]-'a'].push_back(x+1);
        tab2[x+1] = d[x] - 'a';
    }
    for(int x=0;x<=26;x++)
        reverse(v[x].begin(),v[x].end());
}
void solve()
{
    int a;
    cin>>a;
    wczytaj(a);
    long long act = 0, res = 1e18;
    int ptr = 1;
    for(int x=1;x<=a;x++)
    {
        if(tab1[ptr] < tab2[x])
            res = min(res,act);
        else
        {
            int pom = tab2[x];
            int mini = 1e9;
            for(int x=0;x<pom;x++)
                if(!v[x].empty())
                    mini = min(mini, v[x].back());
            if(mini != 1e9)
            {
                int pom2 = mini - ptr - check(ptr,mini);
                res = min(res,act + pom2);
            }
            if(tab1[ptr] == tab2[x])
            {
                v[tab1[ptr]].pop_back();
                odw[ptr] = true;
                ptr++;
                while(odw[ptr])
                    ptr++;
            }
            else
            {
                if(v[tab2[x]].empty())
                    break;
                int pom = v[tab2[x]].back();
                act += pom - ptr - check(ptr,pom);
                ins(pom);
                odw[pom] = true;
                v[tab2[x]].pop_back();
            }

        }

    }
    cout<<(res == 1e18 ? -1 : res)<<'\n';
    for(auto x:updates)
        usun(x);
    updates.resize(0);
    for(int x=0;x<=26;x++)
        v[x].resize(0);
    for(int x=1;x<=a;x++)
        odw[x] = false;
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}