#include <stdio.h>
#include <vector>
int size[400010],check[400010],ans[400010];
int a;
std::vector<int> V[400010];
void clear()
{
    for(int i=1;i<=a;i++) check[i] = 0;
}
int makeSize(int s)
{
    check[s] = 1;
    int ans = 1;
    for(int i=0;i<V[s].size();i++) if(check[V[s][i]]==0) ans+=makeSize(V[s][i]);
    size[s] = ans;
    return ans;
}
int findCentroid(int k)
{
    check[k] = 1;
    for(int i=0;i<V[k].size();i++)
    {
        if(check[V[k][i]]==0)
        {
            if(size[V[k][i]]>a/2) return findCentroid(V[k][i]);
        }
    }
    return k;
}
void func(int s, int t)
{
    if(t>a/2) return;
    check[s] = 1;
    ans[s] =1;
    for(int i=0;i<V[s].size();i++)
    {
        if(check[V[s][i]]==0) func(V[s][i],t+size[s]-size[V[s][i]]);
    }
}
int main()
{
    int b,c,root;
    scanf("%d",&a);
    for(int i=1;i<a;i++)
    {
        scanf("%d%d",&b,&c);
        V[b].push_back(c);
        V[c].push_back(b);
    }
    makeSize(1);
    clear();
    root = findCentroid(1);
    clear();
    makeSize(root);
    clear();
    check[root] = 1;

    int max1=0,max2=0;
    int index1=-1,index2=-1;
    for(int i=0;i<V[root].size();i++)
    {
        if(size[V[root][i]]>max1)
        {
            max2 = max1;
            index2 = index1;
            max1 = size[V[root][i]];
            index1 = V[root][i];
        }
        else if(size[V[root][i]]>max2)
        {
            max2 = size[V[root][i]];
            index2 = V[root][i];
        }
    }

    if(a%2==0&&max1==a/2)
    {
        for(int i=1;i<=a;i++) printf("1 ");
        return 0;
    }
    check[root] = 1;
    ans[root] =1;
    for(int i=0;i<V[root].size();i++)
    {
        if(V[root][i]!=index1) func(V[root][i],a-size[V[root][i]]-max1);
        else
        {
            if(index2==-1) func(V[root][i],a-size[V[root][i]]);
            else func(V[root][i],a-size[V[root][i]]-max2);
        }
    }
    for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}