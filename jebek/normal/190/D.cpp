#include <iostream>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>

using namespace std;

typedef pair<int,int> pii;
long long ans;
int n,k,a[500000],p;
set<pii>s;
map<int,int>t;

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        s.erase(pii(t[a[i]],a[i]));
        t[a[i]]++;
        s.insert(pii(t[a[i]],a[i]));
        while(s.size() && (--s.end())->first>=k)
        {
            s.erase(pii(t[a[p]],a[p]));
            t[a[p]]--;
            if(t[a[p]]>0)
                s.insert(pii(t[a[p]],a[p]));
            p++;
        }
        ans+=(long long)p;
    }
    printf("%lld\n",ans);
}