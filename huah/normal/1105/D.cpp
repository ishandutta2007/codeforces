#include<bits/stdc++.h>
using namespace std;
int n,m,p,a[10],ans[10];
char s[1005][1005];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<pair<int,int> >q[10],qq;
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=p;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]>='1'&&s[i][j]<='9') q[s[i][j]-'0'].push_back(make_pair(i,j));
    bool flag=true;
    while(flag)
    {
        flag=false;
        for(int i=1;i<=p;i++)
        {
            for(int j=1;j<=a[i];j++)
            {
                while(q[i].size())
                {
                    pair<int,int> now=q[i][q[i].size()-1];
                    q[i].pop_back();
                    for(int k=0;k<4;k++)
                    {
                        int xx=now.first+dx[k];
                        int yy=now.second+dy[k];
                        if(xx<1||xx>n||yy<1||yy>m||s[xx][yy]!='.') continue;
                        s[xx][yy]=i+'0';
                        qq.push_back(make_pair(xx,yy));
                    }
                }
                if(qq.size()>0) flag=true;
                else break;
                q[i]=qq;
                qq.clear();
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(s[i][j]>='1'&&s[i][j]<='9') ans[s[i][j]-'0']++;
    for(int i=1;i<=p;i++) printf(i==p?"%d\n":"%d ",ans[i]);
}