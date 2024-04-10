#include <iostream>

using namespace std;

long long n, k, h, ans, rr;
long long sol;

void solve(long long l, long long r, long long k, long long p)
{
    rr=rr/2LL;
    if(l==r)
    {
        return ;
    }
    else{
        long long m=(l+r)/2LL;
        if(m>=k)
        {
            if(p==0)
            sol++,solve(l, m, k, 1-p);
            if(p==1)
            sol+=rr,solve(l, m, k, p);
        }
        else
         {
             if(p==0)
                sol+=rr,solve(m+1, r, k, p);
            if(p==1)
                sol++,solve(m+1, r, k, 1-p);
         }
    }
}

int main()
{
    cin>>h>>n;
    long long k=(1LL<<h)+n-1LL;
    long long l=1LL<<h;
    long long p=0;
    rr=2*l;

solve(1LL, l, n, p);

cout<<sol;
    return 0;
}