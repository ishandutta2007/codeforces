#include <iostream>

using namespace std;
long long n, a[123], nr1, ans;
int main()
{
    cin>>n;
    long long ans=1;
    for(long long i=1; i<=n; i++)
    {
        cin>>a[i];
        nr1+=a[i];
    }
    if(nr1==0)
    {
       cout<<"0\n";
       return 0;
    }
    long long st=1;
    long long fin=n;
    while(a[st]==0) st++;
    while(a[fin]==0) fin--;
    for(long long i=st; i<=fin; i++)
    {
        long long nr0=0;

        while(a[i]==0 && i<=fin)
            i++, nr0++;

        ans*=(nr0+1);
    }

    cout<<ans<<'\n';

    return 0;
}