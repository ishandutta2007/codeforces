#include <bits/stdc++.h>

using namespace std;
void qs(long long *arr, long long left, long long right,long long f[]){
    long long mi = (left+right)/2;
    long long i = left;
    long long j = right;
    long long pivot = arr[mi];

    while(left<j || i<right)
    {
        while(arr[i]<pivot)
        i++;
        while(arr[j]>pivot)
        j--;

        if(i<=j){
            swap(arr[i],arr[j]);
            swap(f[i],f[j]);
            i++;
            j--;
        }
        else{
            if(left<j)
                qs(arr, left, j,f);
            if(i<right)
                qs(arr,i,right,f);
            return;
        }
    }
}
long long n,m,k,x,s,a[200000],b[200000],c[200000],d[200000],i,j,t=0,an,z;
int main()
{
    cin>>n>>m>>k>>x>>s;
   for(i=0;i<m;++i)
    cin>>a[i];
   for(i=0;i<m;i++)
    cin>>b[i];
   for(i=0;i<k;++i)
    cin>>c[i];
   for(i=0;i<k;++i)
    cin>>d[i];
    qs(b,0,m-1,a);
    an=n*x;
    for(i=1;i<m;++i)
        if(a[i]>a[i-1]) a[i]=a[i-1];
    for(i=0;i<k;++i)
    {   if(d[i]<=s)
        { z=upper_bound(b,b+m,s-d[i])-b;
           if(z>0)an=min(an,a[z-1]*(n-c[i]));
           else an=min(an,x*(n-c[i]));
        }
        else break;
    }
    z=upper_bound(b,b+m,s)-b;
    if(z>0) an=min(an,a[z-1]*(n));
    cout<<an;
    return 0;
}