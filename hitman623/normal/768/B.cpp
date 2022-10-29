#include <bits/stdc++.h>
using namespace std;
long long p;
long long cal(long long n)
{
    if(n==1) return 1;
    return 2*cal(n/2)+1;
}
int solve(long long n,long long l)
{
  p=cal(n);
  if(l==(p+1)/2) return n%2;
  if(l<(p+1)/2) solve(n/2,l);
  else solve(n/2,l%((p+1)/2));
}
int main()
{
    long long n,l,r,c=0;
    cin>>n>>l>>r;
    if(!n) {cout<<0;exit(0);}
    while(l<=r)
    if(solve(n,l++)) c++;
    cout<<c;
    return 0;
}