#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int n,m1,m2,F1[100005],F2[100005];
vector<int> V1[100005],V2[100005];
int Find1(int x)
{
    return F1[x]==x ? x : F1[x]=Find1(F1[x]);
}
int Find2(int x)
{
    return F2[x]==x ? x : F2[x]=Find2(F2[x]);
}
void Del(set<int> &St,vector<int> vec)
{
    for(auto &p : vec)
    {
        auto It=St.find(p);
        if(It!=St.end()) St.erase(*It);
    }
}
int main()
{
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=n;i++)
    {
        F1[i]=F2[i]=i;
    }
    for(int i=1;i<=m1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(Find1(u)!=Find1(v)) F1[Find1(u)]=Find1(v);
    }
    for(int i=1;i<=m2;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(Find2(u)!=Find2(v)) F2[Find2(u)]=Find2(v);
    }
    for(int i=1;i<=n;i++)
    {
        V1[Find1(i)].push_back(i);
        V2[Find2(i)].push_back(i);
    }
    set<int> UnGet1,UnGet2;
    for(int i=1;i<=n;i++)
    {
        sort(V1[i].begin(),V1[i].end());
        sort(V2[i].begin(),V2[i].end());
        UnGet1.insert(i);
        UnGet2.insert(i);
    }
    Del(UnGet1,V1[Find1(1)]);
    Del(UnGet2,V2[Find2(1)]);
    vector<pair<int,int> > Ans;
    while(!UnGet1.empty() && !UnGet2.empty())
    {
        // printf("?\n");
        // printf("Print :\n");
        // for(int i=1;i<=n;i++) if(UnGet1.find(i)!=UnGet1.end()) printf("%d ",i);
        // printf("\n");
        // for(int i=1;i<=n;i++) if(UnGet2.find(i)!=UnGet2.end()) printf("%d ",i);
        // printf("\n");
        auto It1=UnGet1.begin();
        if(UnGet2.find(*It1)!=UnGet2.end())
        {
            Ans.push_back(make_pair(1,*It1));
            int tmp=(*It1);
            Del(UnGet1,V1[Find1(tmp)]);
            Del(UnGet2,V2[Find2(tmp)]);
            continue;
        }
        auto It2=UnGet2.begin();
        if(UnGet1.find(*It2)!=UnGet1.end())
        {
            Ans.push_back(make_pair(1,*It2));
            int tmp=(*It2);
            Del(UnGet1,V1[Find1(tmp)]);
            Del(UnGet2,V2[Find2(tmp)]);
            continue;
        }
        Ans.push_back(make_pair(*It1,*It2));
        int tmp1=(*It1);
        int tmp2=(*It2);
        Del(UnGet1,V1[Find1(tmp1)]);
        Del(UnGet2,V2[Find2(tmp2)]);
    }
    printf("%d\n",Ans.size());
    for(auto &p : Ans)
    {
        printf("%d %d\n",p.first,p.second);
    }
}