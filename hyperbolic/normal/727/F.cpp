#include <stdio.h>
#include <queue>
#include <algorithm>
struct str{
    long long int x0;
    int y0;
}y[200010];
int a,b,ans[200010],x[1000];
bool cmp(str a, str b)
{
    return a.x0<b.x0;
}
int func(int k)
{
    std::priority_queue<int> Q;
    long long int s = y[k].x0;
    int count = 0;
    for(int i=1;i<=a;i++)
    {
        s+=x[i];
        if(x[i]<0) Q.push(-x[i]);
        while(s<0)
        {
            s+=Q.top();
            Q.pop();
            count++;
        }
    }
    return count;
}
void func2(int s, int t, int max, int min)
{
    if(s>t) return;
    if(max==min)
    {
        for(int i=s;i<=t;i++) ans[y[i].y0] = max;
        return;
    }
    int h = (s+t)/2;
    int k = func(h);
    ans[y[h].y0]=k;
    func2(s,h-1,max,k);
    func2(h+1,t,k,min);
}
int main()
{
    long long int c;
    scanf("%d%d",&a,&b);
    for(int i=1;i<=a;i++) scanf("%d",&x[i]);
    for(int i=1;i<=b;i++)
    {
        scanf("%I64d",&c);
        y[i].x0 = c;
        y[i].y0 = i;
    }
    std::sort(y+1,y+b+1,cmp);
    func2(1,b,a,0);
    for(int i=1;i<=b;i++) printf("%d\n",ans[i]);
}