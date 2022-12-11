#include <cstdio>
#include <cstdlib>
#include <climits>
#include <vector>
using namespace std;

typedef long long LL;

const int MAXN=100005;

int n,k,a[MAXN*2];
bool uns[MAXN*2];

void work(int l,int r,int cnt,int sig)
{
    if (r<=0)
    {
        for (int i=1;i<=cnt;i++)
            a[sig-=k]=r-i;
    }
    else if (l>=0)
    {
        for (int i=cnt;i>=1;i--)
            a[sig-=k]=l+i;
    }
    else
    {
        int t1=0,t2=1;
        for (;;)
        {
            if (t1>l)
            {
                t1--;
                if (!(--cnt)) break;
            }
            if (t2<r)
            {
                t2++;
                if (!(--cnt)) break;
            }
        }
        for (int i=t2-1;i>t1;i--) a[sig-=k]=i;
    }
}

bool cal(int fir)
{
    int bf=INT_MIN,cnt=0;
    for (int i=fir;i<n+k;i+=k)
        if (!uns[i])
        {
            if (a[i]<=bf||(LL)a[i]-bf-1<cnt) return false;
            if (cnt) work(bf,a[i],cnt,i);
            cnt=0;
            bf=a[i];
        }
        else cnt++;
    return true;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        char num[15];
        scanf("%s",num);
        if (num[0]=='?') uns[i]=true;
        else sscanf(num,"%d",&a[i]);
    }
    for (int i=n;i<n+k;i++) a[i]=INT_MAX;
    for (int i=0;i<k;i++)
        if (!cal(i))
        {
            printf("Incorrect sequence");
            return 0;
        }
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}