#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
    fr[0]=fr[1]=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        fr[(x%2)]++;
    }
    cout<<min(fr[0],fr[1])<<endl;

    }


    return 0;

}