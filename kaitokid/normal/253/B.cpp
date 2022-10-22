#include <bits/stdc++.h>

using namespace std;
int a[10009],b[10009],c[10009];
vector<int> s;
int main()
{
   // ios::sync_with_stdio(0);
   freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

   int n,x;
scanf("%d",&n);
   for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        a[x]=x;
       s.push_back(x);
    }
    int l=1;
  for(int i=1;i<10001;i++)
  {if(a[i]!=0)l=a[i];
  a[i]=l;


  }


sort(s.begin(),s.end());
for(int i=0;i<n;i++)
{
    c[s[i]]=i;


}
int res= 0;
for(int i=0;i<n;i++)
{
   res=max(res,c[a[s[i]*2]]-i+1);
}

    printf("%d",n-res);
    return 0;
}