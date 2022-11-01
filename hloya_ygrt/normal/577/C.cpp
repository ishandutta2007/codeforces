#include <iostream>

using namespace std;

int main()
{
    const int maxn=1e5;
    int n,que[maxn],l=0,r=0;
    cin>>n;
    bool pr[n+3];

    for (int i=0;i<=n;i++) pr[i]=0;
    for (int i=2;i<=n;i++)
    {
        if (pr[i]==0){
            que[r]=i;
            r++;
            for (int j=i;j<=n;j+=i){
                pr[j]=1;
            }
            int j=i*i;
            while(j<=n)
            {
                que[r]=j;
                r++;
                j*=i;
            }
        }
    }
    cout<<r<<endl;
    if (r!=0)cout<<que[0];
    for (int i=l+1;i<r;i++)
        cout<<" "<<que[i];
    return 0;
}