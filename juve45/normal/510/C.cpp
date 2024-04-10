#include <iostream>
#include <vector>
#include <queue>
#define DMAX 30

using namespace std;

string a[4*DMAX];
vector <int> v[DMAX], sol;
int n, use[DMAX][DMAX], uz[DMAX], t[DMAX];
queue <int> q;

void fill_queue()
{
    for(int i=0;i<='z'-'a';i++)
    {
        if(t[i]==0)
            q.push(i);
    }
}

bool check()
{
    for(int i=0;i<=29;i++)
    for(int j=0;j<=29;j++)
    if(use[i][j]==1 && use[j][i]==1)
    {
        cout<<"Impossible\n";
        return true;
    }
    return false;
}

int main()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            int k=0;
            int ll=min(a[j].size(), a[i].size());
            while(a[i][k]==a[j][k] && k!=ll)
                k++;

            if(k==ll)
            {
                if(a[j].size()<a[i].size())
                {
                    cout<<"Impossible\n";
                    return 0;
                }
            }

            if(k!=ll && !use[a[i][k]-'a'][a[j][k]-'a'])
            {
                v[a[i][k]-'a'].push_back(a[j][k]-'a');
                use[a[i][k]-'a'][a[j][k]-'a']=1;
                t[a[j][k]-'a']++;
            }
        }
    }

    fill_queue();

    if(!check())
    {
    while(!q.empty())
    {
        int x=q.front();
        sol.push_back(x);
        q.pop();
        uz[x]=1;
        for(int i=0;i<v[x].size();i++)
        {
            t[v[x][i]]--;
            if(t[v[x][i]]==0 && !uz[v[x][i]])
                q.push(v[x][i]);
        }


    }
    }
    else return 0;

        if(sol.size()!=26)
            cout<<"Impossible\n";
        else
        for(int i=0;i<sol.size();i++)
            cout<<char(sol[i]+'a');

    return 0;
}