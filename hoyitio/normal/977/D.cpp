#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

const int MAXN = 110;
struct node{
    long long num;
    int w;
}N[MAXN];

bool cmp(node a,node b)
{
   if(a.w == b.w)
   {
       return a.num<b.num;
   }
   return a.w>b.w;

}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%lld",&N[i].num);
        long long t = N[i].num;
        N[i].w = 0;
        while(t%3==0)
        {
            N[i].w++;
            t/=3;
        }
    }
    sort(N,N+n,cmp);
    for(int i = 0 ; i < n ; i++)
    {
        printf("%lld ",N[i].num);
     //  cout<<N[i].num<<" ";
    }
    return 0;
}