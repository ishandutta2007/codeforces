#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int a,b,q,lm;
        cin>>a>>b>>q;
        lm=a*b/gcd(a,b);
        int check[lm+1]={0};
        for(int i=1;i<lm+1;i++)
        {
            int cntr=0;
            if(((i%a)%b)!=((i%b)%a)) cntr++;
            check[i]=check[i-1]+cntr;
        }
        while(q>0)
        {
            long long int l,r;
            cin>>l>>r;
            l-=1;
            long long int xl=l/lm;
            long long int xr=r/lm;
            cout<<(xr*check[lm]+check[r%lm])-(xl*check[lm]+check[l%lm])<<" ";
            q--;
        }
        cout<<endl;
        t--;
    }
    return 0;
}