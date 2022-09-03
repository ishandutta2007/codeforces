#include<cstdio>
#include<algorithm>

std::pair<long long,long long> f(std::pair<long long,long long> x)
{
    if(x.first==0LL)return std::make_pair(0LL,1LL);
    std::pair<long long,long long> y=f(std::make_pair(x.second%x.first,x.first));
    return std::make_pair(y.second-x.second/x.first*y.first,y.first);
}

int main()
{
	std::pair<long long,long long> r;
	long long a,b,c,t;
    scanf("%I64d%I64d%I64d",&a,&b,&c);
	r=f(std::make_pair(a,b));
	t=r.first*a+r.second*b;
    if(c%t)puts("-1");
    else printf("%I64d %I64d",-c/t*r.first,-c/t*r.second);
}