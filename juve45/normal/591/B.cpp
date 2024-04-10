#include <bits/stdc++.h>

using namespace std;

char a[200009], c, d;
int m[30];
vector <int> v[30];

void makemap()
{
    for(int i=0;i<=26;i++)
        for(int j=0;j<v[i].size();++j)
    {
        m[v[i][j]]=i;
    }
}

void pre()
{
    for(int i=0;i<=26;++i)
        v[i].push_back(i);
}
int n, m2;
int main()
{
cin>>n>>m2;

for(int i=1;i<=n;i++)
    cin>>a[i];
    pre();
for(int i=1;i<=m2;i++)
    {
        cin>>c>>d;
        c-='a';
        d-='a';
        if(c!=d)
        {
            vector <int> aux;
            aux=v[c];
            v[c]=v[d];
            v[d]=aux;
        }
    }
    
    makemap();
    
    for(int i=1;i<=n;i++)
    {
        cout<<(char)(m[a[i]-'a']+'a');
    }
    cout<<'\n';
    
    return 0;
}