//KeNaj712
#include<bits/stdc++.h>
using namespace std;
long long check(long long sr,long long b)
{
    return sr-sr/b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        long long pocz=0,kon=1e10,sr;
        while(pocz!=kon)
        {
            sr=(pocz+kon)/2;
            if(check(sr,a)<b)
                pocz=sr+1;
            else
                kon=sr;
        }
        cout<<pocz<<'\n';
    }

    return 0;
}