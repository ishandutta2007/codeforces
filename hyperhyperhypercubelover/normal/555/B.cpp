#include<cstdio>
#include<set>
#include<algorithm>

long long l[222222];
long long r[222222];
std::pair<std::pair<long long,long long>,int> a[222222];
int rr[222222];

std::multiset<std::pair<long long,int> > S;
std::multiset<std::pair<long long,int> >::iterator it;

int main()
{
    long long t;
    int i,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%I64d%I64d",&l[i],&r[i]);
    for(i=0;i<m;i++)
    {
        scanf("%I64d",&t);
        S.insert(std::make_pair(t,i));
    }
    for(i=1;i<n;i++)
    {
        a[i].first.first=r[i]-l[i-1];
        a[i].first.second=l[i]-r[i-1];
        a[i].second=i;
    }
    std::sort(a+1,a+n);
    for(i=1;i<n;i++)
    {
        it=S.lower_bound(std::make_pair(a[i].first.second,0));
        if(it==S.end()||it->first>a[i].first.first)
        {
            puts("No");
            return 0;
        }
        rr[a[i].second]=it->second;
        S.erase(it);
    }
    puts("Yes");
    for(i=1;i<n;i++)printf("%d ",rr[i]+1);
}