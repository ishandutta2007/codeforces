/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int r,c,k;
    cin>>r>>c>>k;

    char ans[r+1][c+1],a[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
    int b[r+1][c+1],cntr=0;

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            char x;
            cin>>x;
            if(x=='.') b[i][j]=0;
            else { b[i][j]=1; cntr++; }
        }
    }

    int d=cntr/k+1,e=cntr%k,cnt=0;

    char rce[cntr+1];
    rce[0]='a';
    for(int i=0;i<k;i++)
    {
        if(i==e) d--;
        int temp=d;
        while(temp--) { rce[++cnt]=a[i]; }
    }
    cntr=0;

    for(int i=1;i<=r;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=c;j++)
            {
                cntr+=b[i][j];
                ans[i][j]=rce[cntr];
            }
        }
        else
        {
            for(int j=c;j>0;j--)
            {
                cntr+=b[i][j];
                ans[i][j]=rce[cntr];
            }
        }
    }

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++) cout<<ans[i][j];
        cout<<endl;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
        solve();
	}
	return 0;
}