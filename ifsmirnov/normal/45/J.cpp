#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector<vector<int> > arr(100, vector<int>(100, 0));
void f (int n, int m)
{
    int i, j;
    if (n%2==0)
    {
        for (i=0;i<m;++i)
        {
            for (j=0;j<n/2;++j)
            {
                arr[i][j]=i*n+j*2+1;
            }
            for (j=0;j<n/2;++j)
            {
                arr[i][n/2+j]=i*n+j*2+2;
            }
        }
    }
    else
    {
        for (i=0;i<m;++i)
        {
            for (j=0;j<n/2;++j)
            {
                arr[i][j]=i*n+j*2+1;
            }
            arr[i][n/2]=(i+1)*n;
            for (j=1;j<=n/2;++j)
            {
                arr[i][n/2+j]=i*n+(j-1)*2+2;
            }
        }
    }
}
void f_44 (int n, int m)
{
    int i, j;
    for (i=0;i<m;++i)
    {
        for (j=0;j<n/2;++j)
        {
            arr[i][j]=i*n+j*2+2;
        }
        for (j=0;j<n/2;++j)
        {
            arr[i][n/2+j]=i*n+j*2+1;
        }
    }
}
void f_23 ()
{
    cout << "3 6 2\n5 1 4";
};
void f_32 ()
{
    cout << "3 5\n6 1\n2 4";

};
void f_33 ()
{

    cout << "1 4 8\n6 2 5\n9 7 3";
};
int main()
{
    int n, m, i, j;
    cin>>n>>m;
    if (max(n, m)<4)
    {
        if (n==2 && m==3)
        {
            f_23();
        }
        else if (n==3 && m==2)
        {
            f_32();
        }
        else if (n==3 && m==3)
        {
            f_33();
        }
        else if (n==1 && m==1)
        {
            cout<<1;
        }
        else
        {
            cout<<-1;
        }
        return 0;
    }
    if (max(n, m)==4)
    {
        if (n<m)
        {
            f_44(m, n);
            for (i=0;i<n;++i)
            {
                for (j=0;j<m;++j)
                {
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else
        {
            f_44(n, m);
            for (i=0;i<n;++i)
            {
                for (j=0;j<m;++j)
                {
                    cout<<arr[j][i]<<" ";
                }
                cout<<endl;
            }
        }
        return 0;
    }
    if (n<m)
    {
        f(m, n);
        for (i=0;i<n;++i)
        {
            for (j=0;j<m;++j)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        f(n, m);
        for (i=0;i<n;++i)
        {
            for (j=0;j<m;++j)
            {
                cout<<arr[j][i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}