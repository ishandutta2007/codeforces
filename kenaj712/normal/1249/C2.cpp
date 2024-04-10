#include<bits/stdc++.h>
using namespace std;
long long a;
long long mini=4*1e18;
void rek(long long act,long long pot)
{
    if(pot==0)
        return;
    if(act+pot>=a)
    {
         mini=min(mini,act+pot);
         rek(act,pot/3);
    }
    else
        rek(act+pot,pot/3);


}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long pom=1;
	while(pom<1e18)
        pom*=3;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a;
        rek(0,pom);
        cout<<mini<<'\n';
        mini=4*1e18;
    }
	return 0;
}