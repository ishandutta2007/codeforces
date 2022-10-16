#include <iostream>

using namespace std;

int v[500009], n;
int ansmax=0;
void remake(int pos, int val)
{
    if(val>ansmax)
        ansmax=val;
    if(val%2==0)
    {
        for(int i=1;i<=val/2;i++)
            v[pos-i]=v[pos];
        for(int i=val/2+1;i<=val;i++)
            v[pos-i]=1-v[pos];
    }
    else{
        for(int i=1;i<=val;i++)
            v[pos-i]=v[pos];
        
    }
}


int main()
{
cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    v[0]=v[1];
    v[n+1]=v[n];
    for(int i=1;i<=n;i++)
    {
        int ans=1;
        if(v[i]==v[i-1])
            continue;
        else{
            if(v[i]!=v[i+1] && i<n)
            while(v[i]!=v[i-1]) i++, ans++;
        remake(i-1, ans-2);
        }
    }
    ansmax++;
    cout<<ansmax/2<<'\n';
    for(int i=1;i<=n;i++)
        cout<<v[i]<<' ';
    
    return 0;
}