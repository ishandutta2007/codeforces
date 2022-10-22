#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=2e5+5,INF=0x3f3f3f3f;
int a[maxn];
int last[maxn];

int main()
{
    int n;
    cin>>n;
    memset(last,INF,sizeof(last));
    for(int i=0;i<n;i++)
    {
       cin>>a[i];
       last[a[i]]=i;
    }
    sort(last,last+maxn);
    cout<<a[last[0]]<<endl;//
    return 0;
}