#include<bits/stdc++.h>
using namespace std;
int ind[100100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        priority_queue<pair<int,int> > pq;
        int n,m,x;
        cin>>n>>m>>x;
        while(m--)
            pq.push(make_pair(0,m+1));
        for(int i=0;i<n;i++)
        {
            int y;
            cin>>y;
            pair<int,int> p=pq.top();
            pq.pop();
            p.first-=y;
            ind[i]=p.second;
            pq.push(p);
        }
        puts("YES");
        for(int i=0;i<n;i++)
            cout<<ind[i]<<" ";
        puts("");
    }
    return 0;
}