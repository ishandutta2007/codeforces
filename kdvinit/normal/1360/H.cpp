#include <iostream>
using namespace std;

int compare(int median[],int a[],int m)
{
    for(int i=0;i<m;i++)
    {
        if(median[i]==a[i]) continue;
        if(median[i]>a[i]) return -1;
        if(median[i]<a[i]) return 1;
    }
    return 0;
}

void add1(int median[],int m)
{
    median[m-1]++;
    for(int i=m-1;i>=0;i--)
    {
        if(median[i]!=2) break;
        median[i]=0;
        median[i-1]++;
    }
}

void sub1(int median[],int m)
{
    median[m-1]--;
    for(int i=m-1;i>=0;i--)
    {
        if(median[i]!=-1) break;
        median[i]=1;
        median[i-1]--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int a[n][m],median[m];
        median[0]=0;
        for(int i=1;i<m;i++) median[i]=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char x;
                cin>>x;
                if(x=='1') a[i][j]=1;
                else a[i][j]=0;
            }
        }

        for(int i=0;i<n;i++)
        {
            int cmpr=compare(median, a[i], m);

            if(i%2==0)
            {
                if(cmpr==1) continue;
                while(1)
                {
                    add1(median, m);
                    int j;
                    for(j=0;j<i;j++)
                    {
                        if(compare(median,a[j],m)==0) break;
                    }
                    if(j==i) break;
                }
            }
            else
            {
                if(cmpr==-1) continue;
                while(1)
                {
                    sub1(median, m);
                    int j;
                    for(j=0;j<i;j++)
                    {
                        if(compare(median,a[j],m)==0) break;
                    }
                    if(j==i) break;
                }
            }
        }

        for(int i=0;i<m;i++) cout<<median[i];
        cout<<endl;

    }
    return 0;
}