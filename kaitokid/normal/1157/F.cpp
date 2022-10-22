#include <iostream>

using namespace std;
int n,x,a[200004],ans;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){cin>>x;
    a[x]++;}
    int i=1,j=1,res=0,q,f;
    while(j<200001)
    {
        if(a[j]==0){j++;i=j;res=0;continue;}
        if(a[j]==1){res++;if(res>ans){ans=res;q=i;f=j;}
        i=j;
        j++;
        res=1;
        continue;
        }
    res+=a[j];
    if(res>ans){ans=res;q=i;f=j;}
    j++;
    }
    cout<<ans<<endl;
    for(int j=q;j<=f;j++)cout<<j<<" ";
    for(int j=f;j>=q;j--)for(int l=1;l<a[j];l++)cout<<j<<" ";
    return 0;
}