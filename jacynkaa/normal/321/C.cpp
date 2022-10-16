#include<bits/stdc++.h>
using namespace std;

vector<vector <int> > G;
vector <vector<int> > zablokowane;
vector <int> wartosci;
const int stala=30;
int n;

void dfs(int x)
{
//cout <<x<<endl;
     wartosci[x]=-2;
    for (auto y :G[x])
        if(wartosci[y]==-1)
            dfs(y);

    for (auto y :G[x])
        for(int i=0; i<stala; i++)
        if(zablokowane[y][i]>0)
            zablokowane[x][i]++;

    int wybrany=-1;
    for (int i=0; i<stala; i++)
    {
        if (wybrany==-1 && zablokowane[x][i]==0)
            wybrany=i;
        if(zablokowane[x][i]>1)
            wybrany=-1;
        }

        wartosci[x]=wybrany;
    zablokowane[x][wybrany]=1;
    for (int i=0; i<wybrany; i++)
        zablokowane[x][i]=0;
}

void wczyt ()
{
    cin>>n;
    G.resize(n+5);
    vector <int> X (stala,0);
    zablokowane.resize(n+5,X);
    wartosci.resize(n+5,-1);


    for (int i=0; i<n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1);
    for (int i=1; i<=n; i++)
    {
        char c='Z'-wartosci[i];

        if(c<'A')
        {
            int x=0;
            c=c/x;
        }
        cout <<c<<" ";
    }
    cout <<endl;
}

main()
{
wczyt();
}