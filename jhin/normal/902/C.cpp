#include <bits/stdc++.h>

using namespace std;
bool p=true;int x,n,c,pos;
vector <int> level(1),level2;
void cpy(){int x=level2.size();for(int i=0;i<x;i++)level.push_back(level2[i]);}
int a[200000];
int main()
{

    cin>>n;n++;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==1)x=0;
        else x++;
        
        if(x==2&&p) p=false,pos=i;
    }
    if(p) cout<<"perfect";
    else
    {     cout<<"ambiguous"<<endl;

        for(int i=0;i<n;i++)
        {    int s=level.size();
            for(int j=0;j<a[i];j++)
            {cout<<level[0]<<" ";level2.push_back(++c);}
            level.clear();cpy();level2.clear();
        }
        cout<<endl;c=0;level.clear();level.push_back(0);
        for(int i=0;i<n;i++)
        {
            int s=level.size();
            for(int j=0;j<a[i];j++)
            {if(pos==i&&!p)p=true,cout<<level[1]<<" ";
            else cout<<level[0]<<" ";level2.push_back(++c);}
            level.clear();cpy();level2.clear();
        }
    }

    return 0;
}