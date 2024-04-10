/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin>>n;

    int freq[n+1]={0},pos[n+1][4],a[n-1][4];
    for(int i=1;i<=n-2;i++)
    {
        for(int j=1;j<=3;j++)
        {
            int x;
            cin>>x;
            a[i][j]=x;
            freq[x]++;
            pos[x][freq[x]]=i;
        }
        a[i][0]=a[i][1]+a[i][2]+a[i][3];
    }

    int A=0,b=0,c=0,d=0;
    for(int i=1;i<=n;i++)
    {
        if(freq[i]==1)
        {
            if(A==0) A=i;
            else d=i;
        }
        if(freq[i]==2)
        {
            if(b==0) b=i;
            else c=i;
        }
    }

    cout<<A<<" ";
    int p1=pos[A][1],w,x,l1,l2,l3;
    if(b==a[p1][1] || b==a[p1][2] || b==a[p1][3])
    {
        cout<<b<<" ";
        w=b;
        x=a[p1][0]-A-b;
    }
    else
    {
        cout<<c<<" ";
        w=c;
        x=a[p1][0]-A-c;
        c=b;
    }

    l1=pos[w][1];
    //cout<<endl<<l1<<endl;
    if(a[l1][1]!=A && a[l1][2]!=A && a[l1][3]!=A) p1=l1;
    else p1=pos[w][2];

    for(int i=3;i<=n-2;i++)
    {
        cout<<x<<" ";
        int temp=a[p1][0]-w-x;

        l1=pos[x][1]; l2=pos[x][2]; l3=pos[x][3];

        if(a[l1][1]!=w && a[l1][2]!=w && a[l1][3]!=w) p1=l1;
        else if(a[l2][1]!=w && a[l2][2]!=w && a[l2][3]!=w) p1=l2;
        else p1=l3;

        w=x;
        x=temp;

    }

    cout<<c<<" "<<d<<endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	while(t--)
	{
        solve();
	}
	return 0;
}