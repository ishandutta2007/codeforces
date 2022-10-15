#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	long long int n;
	cin>>n;
	long long int m=(n+1)/2,a[n+2],x,sum=0;

	for(long long int i=1;i<=m;i++)
    {
         cin>>a[i];
         sum+=a[i];
    }

	cin>>x;
    for(long long int i=m+1;i<=n;i++) a[i]=x;

    if(x>=0)
    {
        if((sum+(n-m)*x)>0) { cout<<n<<endl; return 0;}
        else { cout<<-1<<endl; return 0;}
    }
    else
    {
        long long int m2=m;
        if(n%2==0) m++;
        long long int i,lowst[m],temp=0;
        lowst[0]=0;

        for(i=1;i<m;i++)
        {
            temp+=x-a[i];
            lowst[i]=min(lowst[i-1],temp);
        }

        for(i=m;i<=n;i++)
        {
            if((lowst[n-i]+sum+(i-m2)*x)>0) break;
        }

        if(i<=n) { cout<<i<<endl; return 0; }
        else { cout<<-1<<endl; return 0; }
    }

    return 0;
}