#include <iostream>
#include <cstring>
#define dmax 53
#define nmax 100003
using namespace std;

struct person
{
    char x[dmax], y[dmax];
};
person a[nmax];
int n;
char f[dmax], l[dmax];

void solve()
{
    int ce;
    char last[dmax];
    last[0]=0;
    for(int i=1; i<=n; i++)
    {
        cin>>ce;
        char *mi, *ma;
        if(strcmp(a[ce].x, a[ce].y)==1)
        {
            mi=a[ce].y;
            ma=a[ce].x;
        }
        else
        {
            mi=a[ce].x;
            ma=a[ce].y;
        }
        if(strcmp(last, mi)<=0)
        {
            strcpy(last, mi);
        }else
        if(strcmp(last, ma)<=0)
        {
            strcpy(last, ma);
        }else
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>f>>l;
        strcpy(a[i].x, f);
        strcpy(a[i].y, l);

    }
    solve();
    return 0;
}