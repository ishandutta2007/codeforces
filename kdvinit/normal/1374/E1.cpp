/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n,k;
	cin>>n>>k;

	int both[n+1],al[n+1],bob[n+1],cnt2=0,cnta=0,cntb=0;
	for(int i=1;i<=n;i++)
    {
        int t,a,b;
        cin>>t>>a>>b;

        if(a==0 && b==0) continue;
        if(a==1 && b==1) both[++cnt2]=t;
        if(a==1 && b==0) al[++cnta]=t;
        if(a==0 && b==1) bob[++cntb]=t;
    }
	if(cntb+cnt2<k || cnta+cnt2<k) { cout<<-1<<endl; return 0; }

	sort(both+1,both+cnt2+1);
	sort(al+1,al+cnta+1);
	sort(bob+1,bob+cntb+1);

	int p2=1,pa=1,pb=1;
	long long int ans=0;
	for(int i=1;i<=k;i++)
    {
        if(pa==cnta+1 || pb==cntb+1) { ans+=both[p2++]; continue; }
        if(p2==cnt2+1) { ans+=al[pa++]+bob[pb++]; continue; }
        if(al[pa]+bob[pb]>both[p2]) { ans+=both[p2++]; continue; }
        else { ans+=al[pa++]+bob[pb++]; continue; }
    }

    cout<<ans<<endl;
	return 0;
}