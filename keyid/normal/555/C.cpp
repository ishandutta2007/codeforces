#include <cstdio>
#include <set>
#define mp make_pair
using namespace std;

typedef pair<int,pair<int,int> > p3i;

set <p3i> s;
set <int> appear;

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    s.insert(mp(0,mp(0,0)));
    s.insert(mp(n+1,mp(0,0)));
    while (q--)
    {
        int x,y;
        char op[5];
        scanf("%d%d%s",&x,&y,op);
        if (appear.find(x)!=appear.end())
        {
            puts("0");
            continue;
        }
        appear.insert(x);
        p3i seg=*(--s.upper_bound(mp(x,mp(n+2,n+2))));
        if (op[0]=='U')
        {
            printf("%d\n",y-seg.second.second);
            s.insert(mp(x,mp(x,seg.second.second)));
        }
        else
        {
            s.erase(seg);
            printf("%d\n",x-seg.second.first);
            s.insert(mp(seg.first,mp(seg.second.first,y)));
            s.insert(mp(x,mp(seg.second.first,seg.second.second)));
        }
    }
    return 0;
}