#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int m,l,r,k;
    cin>>m;
    while(m--)
    {
        cin>>l>>r>>k;
        l--;r--;
        char A[r-l+1];
        for(int i = 0;i<=r-l;i++)
            A[i] = s[i+l];
        for(int i = 0;i<=r-l;i++)
            s[i+l] = A[((i-k)%(r-l+1)+r-l+1)%(r-l+1)];
    }
    cout<<s;
}