#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200000],b[200000],i,z,o=0,e=0,f[200000],g[200000],l=0,oo[200000]={0},ee[200000]={0},ex[200001]={0},r=0,t=0,exc=0;
int main()
{   cin>>n>>m;
    for(i=0;i<n;++i)
      {
          cin>>a[i];
        if(a[i]&1) o++; else e++;
         b[i]=a[i];
         if(a[i]<=min(n,m)) ex[a[i]]=1;
      }
      for(i=1;i<=min(n,m);++i)
      { if(ex[i]==0)
         {if(i&1) oo[r++]=i;
         else ee[t++]=i;}
      }
    sort(b,b+n);
    f[0]=b[0];g[0]=1;
    for(i=1;i<n;++i)
    {
     if(b[i]==b[i-1]) g[l]++;
     else {f[++l]=b[i];g[l]=1;}
    }
     r=0;t=0;
    for(i=0;i<n;++i)
    {
        z=upper_bound(f,f+l+1,a[i])-f;
       if(g[z-1]>1)
       {
           if(o>e)
           {
               if(a[i]%2==1)
                {a[i]=ee[r++];if(a[i]==0) {cout<<-1;exit(0);}
                 o--;e++;}
                else {a[i]=ee[r++];if(a[i]==0) {cout<<-1;exit(0);}}
           }
           else if(e>o)
           {
               if(a[i]%2==0)
                { a[i]=oo[t++];if(a[i]==0) {cout<<-1;exit(0);}
                  e--;o++; }
                else {a[i]=oo[t++];if(a[i]==0) {cout<<-1;exit(0);}}
           }
           else
           {
               if(a[i]%2==1)
                {a[i]=oo[t++];if(a[i]==0) {cout<<-1;exit(0);}}
                else {a[i]=ee[r++];if(a[i]==0) {cout<<-1;exit(0);}}
           }
           g[z-1]--;exc++;
       }
    }
    if(abs(o-e)!=0)
    {
      for(i=0;i<n;++i)
      {
        z=upper_bound(f,f+l+1,a[i])-f;
           if(o>e)
           {
               if(a[i]%2==1)
                {a[i]=ee[r++];if(a[i]==0) {cout<<-1;exit(0);}
                 o--;e++;exc++;}
           }
           else if(e>o)
           {
               if(a[i]%2==0)
                { a[i]=oo[t++];if(a[i]==0) {cout<<-1;exit(0);}
                  e--;o++;exc++;}
           }
           else break;
      }
    }
    cout<<exc<<endl;
    for(i=0;i<n;++i)
        cout<<a[i]<<" ";
    return 0;
}