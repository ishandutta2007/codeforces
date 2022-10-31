// Hydro submission #628b7e5b60218028ca5f2164@1653309020236
#include <bits/stdc++.h>
using namespace std;
int lastreach[100010],reach[100010],linereach[100010],last[100010];
int main()
{
    int n,m,q;scanf("%d%d",&n,&m);
    memset(linereach,0x3f,sizeof(linereach));
    memset(last,0x3f,sizeof(last));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
        int x;scanf("%d",&x);
        if(x<last[j]) reach[j]=i;
        else reach[j]=lastreach[j];
        lastreach[j]=reach[j];
        last[j]=x;
        linereach[i]=min(linereach[i],reach[j]);
    }
    scanf("%d",&q);
    while(q--){int l,r;scanf("%d%d",&l,&r);printf(linereach[r]<=l?"Yes\n":"No\n");}
    return 0;
}