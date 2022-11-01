#include<algorithm>
#include<vector>
#include<cstdio>
#define X first
#define Y second

using namespace std;

typedef pair<int,int> pii;
typedef long double ld;
vector<int>v[20000];
int n,a,b;
bool mark1[300000];
ld MAX[20000],MAX1,MAX2,f[20000];

void add(int j)
{
    for(int i=0;i<v[j].size();i++)
        mark1[v[j][i]]=true;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        if(MAX[a]<b)
        {
            v[a].clear();
            MAX[a]=b;
        }
        if(MAX[a]==b)
            v[a].push_back(i);
    }
    for(int i=1;i<=10000;i++)
        if(MAX[i]!=0)
            f[i]=MAX[i]/i;
    for(int i=1;i<=10000;i++)
    {
        if(MAX[i]==0)
            continue;
        bool mark=false;
        MAX2=0;
        MAX1=10000000000000000.0;
        for(int j=1;j<i;j++)
            if(MAX[j]>MAX[i])
                MAX1=min(MAX1,((ld)i-(ld)j)/(MAX[j]-MAX[i])*f[i]*f[j]);
        for(int j=i+1;j<=10000;j++)
        {
            if(MAX[j]!=0 && MAX[j]<MAX[i])
                MAX2=max(MAX2,((ld)j-(ld)i)/(MAX[i]-MAX[j])*f[i]*f[j]);
            else if(MAX[j]!=0)
                mark=true;
        }
        if((MAX1==10000000000000000.0 || MAX2==0 || MAX1>=MAX2) && mark==false)
            add(i);
    }
    for(int i=1;i<=n;i++)
        if(mark1[i])
            printf("%d ",i);
    printf("\n");
}