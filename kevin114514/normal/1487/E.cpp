#include<bits/stdc++.h>
#define inf 400000001
using namespace std;
int d1[150150],d2[150150],d3[150150],d4[150150];
vector<int> bad1[150150],bad2[150150],bad3[150150];
int nd1[150150],nd2[150150],nd3[150150];
int n1,n2,n3,n4;
pair<int,int> tmp[150150];
int main()
{
    cin>>n1>>n2>>n3>>n4;
    for(int i=0;i<n1;i++)
        cin>>d1[i];
    for(int i=0;i<n2;i++)
        cin>>d2[i];
    for(int i=0;i<n3;i++)
        cin>>d3[i];
    for(int i=0;i<n4;i++)
        cin>>d4[i];
    int m1,m2,m3;
    for(int i=0;i<n1;i++)
        tmp[i]=make_pair(d1[i],i);
    sort(tmp,tmp+n1);
    for(int i=0;i<n1;i++)
        nd1[tmp[i].second]=i;
    cin>>m1;
    while(m1--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        bad1[y].push_back(nd1[x]);
    }
    for(int i=0;i<n2;i++)
        sort(bad1[i].begin(),bad1[i].end());
    for(int i=0;i<n2;i++)
    {
        int x=0;
        for(int j=0;j<(int)(bad1[i].size());j++)
            if(bad1[i][j]<=x)
            {
                x++;
            }
            else
            {
                break;
            }
        if(x==n1)
        	d2[i]=inf;
        else	d2[i]+=tmp[x].first;
    }
    for(int i=0;i<n2;i++)
        tmp[i]=make_pair(d2[i],i);
    sort(tmp,tmp+n2);
    for(int i=0;i<n2;i++)
        nd2[tmp[i].second]=i;
    cin>>m2;
    while(m2--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        bad2[y].push_back(nd2[x]);
    }
    for(int i=0;i<n3;i++)
        sort(bad2[i].begin(),bad2[i].end());
    for(int i=0;i<n3;i++)
    {
        int x=0;
        for(int j=0;j<(int)(bad2[i].size());j++)
            if(bad2[i][j]<=x)
            {
                x++;
            }
            else
            {
                break;
            }
        if(x==n2)
        	d3[i]=inf;
        else	d3[i]+=tmp[x].first;
    }
    for(int i=0;i<n3;i++)
        tmp[i]=make_pair(d3[i],i);
    sort(tmp,tmp+n3);
    for(int i=0;i<n3;i++)
        nd3[tmp[i].second]=i;
    cin>>m3;
    while(m3--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        bad3[y].push_back(nd3[x]);
    }
    for(int i=0;i<n4;i++)
        sort(bad3[i].begin(),bad3[i].end());
    for(int i=0;i<n4;i++)
    {
        int x=0;
        for(int j=0;j<(int)(bad3[i].size());j++)
            if(bad3[i][j]<=x)
            {
                x++;
            }
            else
            {
                break;
            }
        if(x==n3)
        	d4[i]=inf;
        else	d4[i]+=tmp[x].first;
    }
    if(*min_element(d4,d4+n4)>=inf)
    	puts("-1");
    else	cout<<*min_element(d4,d4+n4)<<endl;
    return 0;
}