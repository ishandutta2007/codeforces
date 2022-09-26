#include <bits/stdc++.h>
using namespace std;

int scum(int n)
{
    int c=n;
    int a=0;
    int q=1;
    while (n>0)
    {
        a+=n%10;
        if (n%10!=0)
            a++;
        if (n%10==1)
            a-=max(q, 0), q--;
        n/=10;
    }
    if ((q==0) and (c%10==1))
    a++;
    return a;
}

int dp[100];
int f(int q, int l)
{
    if (dp[q]<=l)
        return 0;
    if (q>=100)
        return 0;
    dp[q]=l;
    f(q+1, l+1);
    if ((q%10!=0) and (q>10))
        f(10*(q%10)+(q/10), l+1);
    return 0;
}


int main()
{
    cout<<"red"<<"\n";
    return 0;

}