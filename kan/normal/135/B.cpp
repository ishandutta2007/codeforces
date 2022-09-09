#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

unsigned char was[8];
long long x[8],y[8];

bool sc(int i1,int i2,int i3)
{
//    cerr << i1 << i2 << i3 << ' ' << (x[i3]-x[i2])*(x[i2]-x[i1])+(y[i3]-y[i2])*(y[i2]-y[i1]) << endl;
    return ((x[i3]-x[i2])*(x[i2]-x[i1])+(y[i3]-y[i2])*(y[i2]-y[i1]))==0;
}

long long d(int i,int j)
{
//    cerr << i << ' '  << j << ' ' << (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) << endl;
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

bool can(int i1,int i2,int i3,int i4)
{
//    cerr << "try " << i1 << i2 << i3 << i4 << endl;
    memset(was,0,sizeof(was));
    was[i1]=1;
    was[i2]=1;
    was[i3]=1;
    was[i4]=1;
    if (i1==0 && i2==1 && i3==2 && i4==3)
    {
//        cout << sc(i1,i2,i3) << ' ' << sc(i2,i3,i4) << ' ' <<  sc(i3,i4,i1) << ' ' <<  sc(i4,i1,i2) << endl;
    }
    if (!(sc(i1,i2,i3) && sc(i2,i3,i4) && sc(i3,i4,i1) && sc(i4,i1,i2) && d(i1,i2)==d(i2,i3) && d(i2,i3)==d(i3,i4) && d(i3,i4)==d(i4,i1))) return false;
//    cout << "try" << endl;
    for (int j1=0;j1<8;j1++) if (was[j1]!=1)
        for (int j2=0;j2<8;j2++) if (was[j2]!=1 && j1!=j2)
            for (int j3=0;j3<8;j3++) if (was[j3]!=1 && j1!=j3 && j2!=j3 && sc(j1,j2,j3))
                for (int j4=0;j4<8;j4++) if (was[j4]!=1 && j4!=j1 && j4!=j2 && j4!=j3 && sc(j2,j3,j4))
                    if (sc(j3,j4,j1) && sc(j4,j1,j2) && d(j1,j2)==d(j3,j4) && d(j2,j3) == d(j4,j1))
                    {
                        cout << "YES\n";
                        printf("%d %d %d %d\n",i1+1,i2+1,i3+1,i4+1);
                        printf("%d %d %d %d\n",j1+1,j2+1,j3+1,j4+1);
                        return true;
                    }
    return false;
}

int main()
{
    //freopen("input.txt","r",stdin);
    for (int i=0;i<8;i++) cin >> x[i] >> y[i];
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++) if (i!=j)
        {
            for (int i1=0;i1<8;i1++) if (i1!=i && i1!=j)
            {
                for (int j1=0;j1<8;j1++) if (j1!=i && j1!=j && j1!=i1)
                {
                    if (can(i,j,i1,j1))
                    {
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO";
    return 0;
}