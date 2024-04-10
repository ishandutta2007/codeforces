#include<bits/stdc++.h>
using namespace std;

vector <bool> wartosci;
vector <bool> czy_cos_zmienia;
vector <vector <int> > G;
vector <string> co; // "AND", "OR", "XOR", "NOT" or "IN"
int n;

void wczytywanie()
{

    cin>>n;
    wartosci.resize(n);
    G.resize(n);
    co.resize(n);
    czy_cos_zmienia.resize(n);

    for (int i=0; i<n; i++)
    {
        cin>>co[i];

        if(co[i][0]=='A')
        {
            int a,b;
            cin>>a>>b;
            G[i].push_back(a-1);
            G[i].push_back(b-1);

           // cout<<" ok"<<endl;
        }

        if(co[i][0]=='X')
        {
            int a,b;
            cin>>a>>b;
            G[i].push_back(a-1);
            G[i].push_back(b-1);
        }

        if(co[i][0]=='O')
        {
            int a,b;
            cin>>a>>b;
            G[i].push_back(a-1);
            G[i].push_back(b-1);
        }

        if(co[i][0]=='N')
        {
            int a;
            cin>>a;
            G[i].push_back(a-1);
        }

        if(co[i][0]=='I')
        {
            bool a;
            cin>>a;
            wartosci[i]=a;

            //  cout<<" okii"<<endl;
        }
    }
}

void dfs(int i)
{
    if(co[i][0]=='A')
    {
        int a=G[i][0];
        int b=G[i][1];
        dfs(a);
        dfs(b);
        wartosci[i]=wartosci[a]&&wartosci[b];
        return;
    }

    if(co[i][0]=='X')
    {
        int a=G[i][0];
        int b=G[i][1];
        dfs(a);
        dfs(b);
        wartosci[i]=wartosci[a]^wartosci[b];
        return;
    }

    if(co[i][0]=='O')
    {
        int a=G[i][0];
        int b=G[i][1];
        dfs(a);
        dfs(b);
        wartosci[i]=wartosci[a]||wartosci[b];
        return;
    }

    if(co[i][0]=='N')
    {
        int a=G[i][0];
        dfs(a);
        wartosci[i]=!wartosci[a];
        return;
    }

    return;
}

void dfs_znajdujacy_odpowiedz(int i)
{

    if(co[i][0]=='N')
    {
        int a=G[i][0];
        dfs_znajdujacy_odpowiedz(a);
        return;
    }

    if(co[i][0]=='A')
    {
        int a=G[i][0];
        int b=G[i][1];
        int awar=!wartosci[a];
        int bwar=!wartosci[b];

        if((awar&&wartosci[b])!=wartosci[i])
            dfs_znajdujacy_odpowiedz(a);

        if((bwar&&wartosci[a])!=wartosci[i])
            dfs_znajdujacy_odpowiedz(b);
        return;
    }

    if(co[i][0]=='X')
    {
        int a=G[i][0];
        int b=G[i][1];
        int awar=!wartosci[a];
        int bwar=!wartosci[b];

        if((awar^wartosci[b])!=wartosci[i])
            dfs_znajdujacy_odpowiedz(a);

        if((bwar^wartosci[a])!=wartosci[i])
            dfs_znajdujacy_odpowiedz(b);
        return;
    }

    if(co[i][0]=='O')
    {
        int a=G[i][0];
        int b=G[i][1];
        int awar=!wartosci[a];
        int bwar=!wartosci[b];

        if((awar||wartosci[b])!=wartosci[i])
            dfs_znajdujacy_odpowiedz(a);

        if((bwar||wartosci[a])!=wartosci[i])
            dfs_znajdujacy_odpowiedz(b);
        return;
    }


    if(co[i][0]=='I')
    {
        czy_cos_zmienia[i]=true;
        return;
    }
}

main()
{
    wczytywanie();
    dfs(0);
    dfs_znajdujacy_odpowiedz(0);


    for (int i=0; i<n; i++)
    {
        if(co[i][0]=='I')
        {
     //   cout <<"super"<<endl;
            if(czy_cos_zmienia[i]==false)
                cout <<wartosci[0];
            else
                cout <<!wartosci[0];
        }
    }
    cout <<endl;
}