#include <bits/stdc++.h>

using namespace std;

char s[10007];
int n, k, l, r;

void solve(int l, int r, int k)
{
    int lg=r-l+1;
    k=k%lg;
   char ss[10007];
    
    for(int i=1; i<=lg; i++)
    {
        int pos=r-k+i;
        if(pos>r)pos-=lg;
        ss[i-1]=s[pos];
        ss[i]=0;
    }
    //cout<<ss<<" === dsf\n";
    for(int i=l; i<=r; i++)
        s[i]=ss[i-l];
}
int main()
{
    
    cin>>s;
    cin>>n;
    while(n)
    {
        cin>>l>>r>>k;
        l--;
        r--;
        solve(l, r, k);
        n--;
    }
        cout<<s<<'\n';



    return 0;
}