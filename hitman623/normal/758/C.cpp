#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,k,x,y,mi=0,ma=0,s=0;
    cin>>n>>m>>k>>x>>y;
    if(n>2)
        {
            ma=k/((2*n-2)*m);
            mi=ma;
            s=ma;
            ma*=2;
            if(x!=1 && x!=n) s*=2;
            ma+=(k%((2*n-2)*m))>m?1:0;
            ma+=((k%((2*n-2)*m))>m*n)?1:0;
            if(k && !ma) ma=1;
            mi+=(k%((2*n-2)*m))>=(n*m)?1:0;
            s+=((k%((2*n-2)*m))/((x-1)*m+y))?1:0;
        }
    else
        {
            ma=k/(m*n);
            mi=ma;
            s=ma;
            ma+=(k%(m*n))?1:0;
            s+=((k%(n*m)>=(x-1)*m+y))?1:0;
        }
    if(n>=x+1)
    s+=((k%((2*n-2)*m))/((n*m+(n-x-1)*m+y)))?1:0;
    cout<<ma<<" "<<mi<<" "<<s;
    return 0;
}