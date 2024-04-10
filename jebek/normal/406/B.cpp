#include <iostream>
#include<vector>
#include<cstdio>

using namespace std;

typedef pair<int,int> pii;
const int n=1000000;
int m,k,a;
vector<pii>v;
bool mark[1000100];

int main()
{
    scanf("%d",&m);
    printf("%d\n",m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a);
        mark[a]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(mark[i]==true && mark[n-i+1]==false)
        {
            printf("%d ",n-i+1);
        }
        if(mark[i]==true && mark[n-i+1]==true && i<n-i+1)
            k++;
        if(mark[i]==false && mark[n-i+1]==false && i<n-i+1)
            v.push_back(pii(i,n-i+1));
    }
    for(int i=0;i<k;i++)
        printf("%d %d ",v[i].first,v[i].second);
}