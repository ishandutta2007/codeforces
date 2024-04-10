#include <cstdio>
#include <set>
using namespace std;

int n,k,a;
set <int> s;

inline int query(int l,int r)
{
    if (r-l+1<a) return 0;
    return 1+(r-l+1-a)/(a+1);
}

int main()
{
    int m;
    scanf("%d%d%d%d",&n,&k,&a,&m);
    int now=query(1,n);
    s.insert(0);
    s.insert(n+1);
    for (int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        if (s.find(x)!=s.end()) continue;
        else
        {
            set <int> :: iterator it=s.lower_bound(x);
            int r=*it;
            int l=*--it;
            now-=query(l+1,r-1);
            now+=query(l+1,x-1);
            now+=query(x+1,r-1);
            if (now<k)
            {
                printf("%d",i);
                return 0;
            }
            s.insert(x);
        }
    }
    printf("-1");
    return 0;
}