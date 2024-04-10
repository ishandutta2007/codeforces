#include <bits/stdc++.h>

using namespace std;

struct disset
{
    long long data;
    long long parent;
};

long long find_parent(struct disset*a,long long x)
{
    long par;
    if(a[x].parent==x) return x;
    a[x].parent=find_parent(a,a[x].parent);
    return a[x].parent;
}
void merge_set(struct disset *a,long long x,long long y)
{
    long long parent1=find_parent(a,x);
    long long parent2=find_parent(a,y);
        a[parent1].parent=parent2;
        a[parent2].data+=a[parent1].data;
}
long long n,q,c,x,y,i,p[100005],m[100005]={0},j;
struct disset a[100005]={0};
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i].data;
    }
    a[0].parent=0;
    for(i=0;i<n;i++)
    {
        cin>>p[i];
    }
    for(i=n-1;i>=0;i--)
    {
        a[p[i]].parent=p[i];
        if(a[p[i]-1].parent!=0)
        {
            merge_set(a,p[i],p[i]-1);
        }
        if(a[p[i]+1].parent!=0)
        {
            merge_set(a,p[i]+1,p[i]);
        }
        m[i]=max(m[i+1],a[a[p[i]].parent].data);
    }
    for(i=1;i<n;++i)
        cout<<m[i]<<endl;
    cout<<0;
    return 0;
}