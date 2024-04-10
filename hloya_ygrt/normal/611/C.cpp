#include <bits\stdc++.h>

using namespace std;

    const int maxn=2e5;
    const int inf=2e9;
    const int eps=1e-5;

#define pb push_back
#define mp make_pair
#define fir first
#define sec second
int a[500][500],dph[500][500]={0},dpw[500][500]={0};
int main()
{
    int n,m;
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d %d",&n,&m);

    for (int i=0;i<n;i++)
    {
        scanf("%*c");

        for (int j=0;j<m;j++)
        {
            char c;
            scanf("%c",&c);

            if (c=='.')
                a[i][j]=0;
            else
                a[i][j]=1;
        }
    }


    for (int i=0;i<n;i++)
    for (int j=0;j<m-1;j++)
    {
        if (a[i][j]==0&&a[i][j+1]==0)
            dpw[i][j]=1;
    }

    for (int i=0;i<n-1;i++)
    for (int j=0;j<m;j++)
    {
        if (a[i][j]==0&&a[i+1][j]==0)
            dph[i][j]=1;
    }
    int i=0;
    for (int j=1;j<m;j++)
    {
        dpw[i][j]+=dpw[i][j-1];
        dph[i][j]+=dph[i][j-1];
    }

    int j=0;
    for (i=1;i<n;i++)
    {
        dpw[i][j]+=dpw[i-1][j];
        dph[i][j]+=dph[i-1][j];
    }

    for (i=1;i<n;i++)
    for (j=1;j<m;j++)
    {
        dpw[i][j]+=dpw[i-1][j]+dpw[i][j-1]-dpw[i-1][j-1];
        dph[i][j]+=dph[i-1][j]+dph[i][j-1]-dph[i-1][j-1];
    }

    int q;
    scanf("%d",&q);

    for (i=0;i<q;i++)
    {
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1--;
        x2--;
        y1--;
        y2--;
        int ans=0;

        if (x1>0&&y1>0)
            {
            if (x1!=x2)
            ans+=(dph[x2-1][y2]-dph[x1-1][y2]-dph[x2-1][y1-1]+dph[x1-1][y1-1]);
            if (y1!=y2)
            ans+=(dpw[x2][y2-1]-dpw[x1-1][y2-1]-dpw[x2][y1-1]+dpw[x1-1][y1-1]);
            }
        else if (x1==0&&y1>0)
        {if (x1!=x2)
            ans+=(dph[x2-1][y2]-dph[x2-1][y1-1]);
           if (y1!=y2) ans+=(dpw[x2][y2-1]-dpw[x2][y1-1]);
        }
        else
            if (y1==0&&x1>0)
            {
             if (x1!=x2)   ans+=(dph[x2-1][y2]-dph[x1-1][y2]);
                if (y1!=y2)  ans+=(dpw[x2][y2-1]-dpw[x1-1][y2-1]);
            }
        else
          {

           if (x1!=x2) ans=dph[x2-1][y2];
           if (y1!=y2) ans+=dpw[x2][y2-1];

        }
        cout<<ans<<endl;
    }

    return 0;
}