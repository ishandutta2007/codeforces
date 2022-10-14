#include <iostream>

using namespace std;
long long n,k,maxer,a[501];
bool win(int x){int pl=a[x];int num=k-1;if(x==0)num++;
       for(int i=x+1,j=0;j<num;i++,j++){
          if(i==n)i=0;
          if(pl<a[i])return false;}
return true;}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){cin>>a[i];if(a[i]>maxer)maxer=a[i];}
    if(k>n)cout<<maxer;
    else
    {
        for(int i=0;i<n;i++)
        if(win(i)){cout<<a[i];return 0;}
    }
    return 0;
}