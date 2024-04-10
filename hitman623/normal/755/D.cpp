
 #include <iostream>

using namespace std;

int main()
{
    long long n,k,p=1,c=1,u=1;
    cin>>n>>k;
    if(k>n/2) k=n-k;
    while(p<n*k+1)
    {
       c+=k;
       if(c>n) {c%=n;u++;}
       p+=u;
       if(u%2==0) u++;
       if(p-1==n*k+1) cout<<p-1;
       else cout<<p<<" ";
    }
    return 0;
}