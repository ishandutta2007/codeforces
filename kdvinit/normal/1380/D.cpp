/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	long long int n,m,x,k,y,z,ans=0;
	cin>>n>>m>>x>>k>>y;
	z=min(x,y*k);

	int a[n+2]={0},b[m+2]={0},c[n+2]={0};

	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];

	int cnt=0;
	for(int i=0;i<=n+1;i++)
    {
        if(a[i]==b[cnt]) cnt++;
    }

    if(cnt<m+2) { cout<<-1<<endl; return 0; }

    cnt=0;
    int cntr=0,val,mval;
    for(int i=0;i<=n+1;i++)
    {
        if(a[i]==b[cnt])
        {
            cnt++;
            if(cntr==0) continue;

            mval=max(b[cnt-2],b[cnt-1]);

            if(cntr<k)
            {
                if(mval<val) { cout<<-1<<endl; return 0; }
                else ans+=cntr*y;
            }
            else
            {
                int a1=cntr/k,b1=cntr%k;
                if(x<=y*k)
                {
                    ans+=b1*y;
                    ans+=a1*x;
                }
                else
                {
                    if(mval<val) ans+=(x+(cntr-k)*y);
                    else ans+=cntr*y;
                }
            }
            cntr=0;
        }
        else
        {
            cntr++;
            if(cntr==1) val=a[i];
            else val=max(val,a[i]);
        }
    }

    cout<<ans<<endl;
	return 0;
}