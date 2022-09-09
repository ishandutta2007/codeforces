#include <iostream>
#include <cstdio>

using namespace std;

const int maxn=2005;

char a[maxn][maxn];
int b[maxn][maxn];
int d[maxn],mustx[maxn],musty[maxn];

int main()
{
    int n;
    scanf("%d\n",&n);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            scanf("%c",&a[i][j]);
            b[i][j]=(int)(a[i][j])-48;
        }
        if (i!=n) scanf("\n");
    }
//    for (int i=1;i<=n;i++)
//    {
//        for (int j=1;j<=n;j++) cout << b[i][j];
//        cout << endl;
//    }
    for (int i=1;i<=n;i++)
    {
        mustx[i]=0;
        musty[i]=0;
    }
    int ans=0;
    for (int i=n;i>1;i--)
    {
        for (int j=1;j<=n-i+1;j++)
        {
//            cout << i << j << mustx[j] << musty[i] << b[j][i] << endl;
            if ((mustx[j] ^ musty[i+j-1])!=b[j][i+j-1])
            {
//                cout << "true" << endl;
                mustx[j]=mustx[j] ^ 1;
                musty[i+j-1]=musty[i+j-1] ^ 1;
                ans++;
            }
        }
    }
//    cout << ans << endl;
    for (int i=1;i<=n;i++) d[i]=mustx[i]^musty[i];
    for (int i=1;i<=n;i++)
    {
        mustx[i]=0;
        musty[i]=0;
    }
    for (int i=n;i>1;i--)
    {
        for (int j=1;j<=n-i+1;j++)
        {
            if ((mustx[i+j-1] ^ musty[j])!=b[i+j-1][j])
            {
                mustx[i+j-1]=mustx[i+j-1] ^ 1;
                musty[j]=musty[j] ^ 1;
                ans++;
            }
        }
    }
//    cout << ans << endl;
    for (int i=1;i<=n;i++) d[i]=d[i]^mustx[i]^musty[i];
    for (int i=1;i<=n;i++) if (d[i]!=b[i][i]) ans++;
    cout << ans;
    return 0;
}