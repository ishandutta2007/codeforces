#include<bits/stdc++.h>
using namespace std;
int mov[1000005][2];
int tab[1000005];
vector<int> v;
set<pair<int,int>> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,t;
    cin>>a>>t;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    int pocz=1,kon=2;
    int roz=a+1,dokad=-1;
    for(int p=1;p<=5*a;p++)
    {
        if(s.find(make_pair(tab[pocz],tab[kon]))!=s.end()&&p>=3*a)
        {
            for(int x=kon;x<kon+a-1;x++)
            {
                v.push_back(tab[x]);
                tab[roz]=tab[x];
                roz++;
            }

            break;
        }
        else
        {
            s.insert(make_pair(tab[pocz],tab[kon]));
            mov[p][0]=tab[pocz];
            mov[p][1]=tab[kon];
            if(tab[pocz]<=tab[kon])
            {
                tab[roz]=tab[pocz];
                kon++;
                pocz=kon-1;
            }
            else
            {
                tab[roz]=tab[kon];
                kon++;
            }
            roz++;
        }
        dokad=p;
    }
    long long q;
    while(t--)
    {
        cin>>q;
        if(q<=dokad)
            cout<<mov[q][0]<<" "<<mov[q][1];
        else
        {
            q-=dokad;
            q--;
            cout<<tab[pocz]<<" "<<v[q%(a-1)];
        }
        cout<<'\n';
    }
	return 0;
}