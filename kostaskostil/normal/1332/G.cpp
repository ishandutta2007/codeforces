#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int nmax=2e5+100;

int mn[nmax][20];
int mx[nmax][20];
int lg[nmax];
int a[nmax];
int rt[nmax];
int lt[nmax][20];
int cl[nmax];
int clmx[nmax][20];

pair<int, int> mnmx(int l, int r)
{
    int j=lg[r-l+1];
    r-=((1<<j)-1);
    return make_pair(
        (a[mn[l][j]] < a[mn[r][j]]) ? mn[l][j] : mn[r][j],
        (a[mx[l][j]] > a[mx[r][j]]) ? mx[l][j] : mx[r][j]);
}

int mxlt(int l, int r)
{
    int j=lg[r-l+1];
    r-=((1<<j)-1);
    return max(lt[l][j], lt[r][j]);
}

int clmxf(int l, int r){
    int j=lg[r-l+1];
    r-=((1<<j)-1);
    return (cl[clmx[l][j]] < cl[clmx[r][j]]) ? clmx[l][j] : clmx[r][j];
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=2; i<=nmax; i++)
        lg[i]=lg[i/2]+1;

    int n, q;
    cin>>n>>q;
    for (int i=1; i<=n; i++)
        cin>>a[i], mn[i][0]=mx[i][0]=i;
    for (int j=1; j<20; j++)
        for (int i=1; i<=n+1-(1<<j); i++)
        {
            mn[i][j] = ( a[mn[i][j-1]] < a[mn[i+(1<<(j-1))][j-1]] ) ? mn[i][j-1] : mn[i+(1<<(j-1))][j-1];
            mx[i][j] = ( a[mx[i][j-1]] > a[mx[i+(1<<(j-1))][j-1]] ) ? mx[i][j-1] : mx[i+(1<<(j-1))][j-1];
        }
    for (int i=1; i<=n; i++)
    {
        int l, r;

        l=i, r=n+1;
        while (r-l>1){
            int m=(l+r)/2;
            auto pa=mnmx(i, m);
            if ((a[i]==a[pa.fi]) or (a[i]==a[pa.se]))
                l=m;
            else
                r=m;
        }
        rt[i]=r;

        l=0, r=i;
        while (r-l>1){
            int m=(l+r)/2;
            auto pa=mnmx(m, i);
            if ((a[i]==a[pa.fi]) or (a[i]==a[pa.se]))
                r=m;
            else
                l=m;
        }
        lt[i][0]=l;
    }
    for (int j=1; j<20; j++)
        for (int i=1; i<=n+1-(1<<j); i++)
            lt[i][j]=max(lt[i][j-1], lt[i+(1<<(j-1))][j-1]);
    for (int i=1; i<=n; i++)
    {
        int l, r;
        l=rt[i]-1, r=n+1;
        while (r-l>1)
        {
            int m=(l+r)/2;
            if (mxlt(rt[i], m)>=i)
                r=m;
            else
                l=m;
        }
        cl[i]=r;
    }

//    for (int i=1; i<=n; i++)
//        cout<<a[i]<<" ";
//    cout<<"\n";
//    for (int i=1; i<=n; i++)
//        cout<<lt[i][0]<<" ";
//    cout<<"\n";
//    for (int i=1; i<=n; i++)
//        cout<<rt[i]<<" ";
//    cout<<"\n";
//    for (int i=1; i<=n; i++)
//        cout<<cl[i]<<" ";
//    cout<<"\n";

    for (int i=1; i<=n; i++)
        clmx[i][0]=i;
    for (int j=1; j<20; j++)
        for (int i=1; i<=n+1-(1<<j); i++)
            clmx[i][j] = ( cl[clmx[i][j-1]] < cl[clmx[i+(1<<(j-1))][j-1]] ) ? clmx[i][j-1] : clmx[i+(1<<(j-1))][j-1];
    set<int> up, down;
    for (int i=1; i<n; i++)
        if (a[i]<a[i+1])
            up.insert(i);
        else if (a[i]>a[i+1])
            down.insert(i);

    for (int i=1; i<=q; i++)
    {
        int l, r;
        cin>>l>>r;
        int clmax=clmxf(l, r);
        if (cl[clmax]>r)
        {
            auto itup=up.lower_bound(l);
            auto itdown=down.lower_bound(l);
            if ((itup==up.end()) or (itdown==down.end()) or ((*itup)>=r) or ((*itdown)>=r))
                cout<<"0\n";
            else
            {
                int upi=*itup;
                int downi=*itdown;
                int t=max(upi, downi);
                cout<<"3\n"<<min(upi, downi)<<" "<<t<<" "<<t+1<<"\n";
            }
        }
        else
        {
            int a1=clmax;
            int a4=cl[clmax];
            auto pa=mnmx(a1, a4);
            int a2=min(pa.fi, pa.se);
            int a3=max(pa.fi, pa.se);
            cout<<"4\n"<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<"\n";
        }
    }

    return 0;
}
/*
10 10
2 9 8 6 10 1 7 4 3 5
1 10
2 9
3 8
4 7
3 7
4 8
1 4
5 10
4 9
1 7
*/