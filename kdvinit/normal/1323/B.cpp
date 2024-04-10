//mistake 2 not using long long int for (k,i,j,l) as k will be n.m
//mistake 3 not applying long long everywhere
//don't know why but didn't work for all long long so made all just long
//optimizing the code by line neglecting the case of l>n
//didn't saw that though k is long ans can be long long.
#include <iostream>
using namespace std;

long int seg(long int a[],long int pos1a[],long int fa,long int n,long int l)
{
    if(l>fa) return 0;
    int cntr=0,ans=0;
    for(long int i=0;i<=pos1a[fa-l+1];i++) //mistake 1 not putting equal sign with i and pos1a here;
    {
        if(a[i]==1)
        {
            cntr++;
            if(pos1a[cntr+l-1]==i+l-1) ans++;
        }
    }
    return ans;
}

int main()
{
    long int n,m,k,fa=0,fb=0; //fa stands for frequency on 1 in a
    long long ans=0;
    cin>>n>>m>>k;
    long int a[n],b[m],pos1a[n+1],pos1b[m+1]; // pos1a stands will give the position of a particular 1 in a, this is done to avoid a for loop while count the number of segments of length j in array a made of all 1;
    for(long int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            fa++;
            pos1a[fa]=i;
        }
    }
    for(long int i=0;i<m;i++)
    {
        cin>>b[i];
        if(b[i]==1)
        {
            fb++;
            pos1b[fb]=i;
        }
    }
    int y=min(k,max(n,m));
    for(long int i=1;i<=y;i++)
    {
        long int x=k/i;
        if(k%i==0) ans+=seg(a,pos1a,fa,n,i)*seg(b,pos1b,fb,m,x);
    }
    cout<<ans<<endl;
    return 0;
}