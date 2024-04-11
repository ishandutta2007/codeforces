#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

const int n=333;
int stage=1;
int corner=0;
int xs=3*n/2;
int ys=3*n/2;
int a, b;
int x[100500];
int y[100500];
int xi[100500];
int yi[100500];
int brd[1100][1100];

bool t(int q, int w)
{
    if ((q==a) and (w==b))
        return false;
    if ((q<1) or (q>3*n) or (w<1) or (w>3*n))
        return false;
    if (brd[q][w]==0)
        return true;
    return false;
}

void mov(int q, int w)
{
    a=q;
    b=w;
    cout<<q<<" "<<w<<"\n";
    fflush(stdout);
}

int check()
{
    if ((xi[a]>0) or (yi[b]>0))
        exit(0);
    if (xi[a+1]>0)
    {
        if (t(a+1, b+1))
        {
            mov(a+1, b+1);
            exit(0);
        }
        if (t(a+1, b))
        {
            mov(a+1, b);
            exit(0);
        }
        if (t(a+1, b-1))
        {
            mov(a+1, b-1);
            exit(0);
        }
    }
    if (xi[a-1]>0)
    {
        if (t(a-1, b+1))
        {
            mov(a-1, b+1);
            exit(0);
        }
        if (t(a-1, b))
        {
            mov(a-1, b);
            exit(0);
        }
        if (t(a-1, b-1))
        {
            mov(a-1, b-1);
            exit(0);
        }
    }

    if (yi[b+1]>0)
    {
        if (t(a+1, b+1))
        {
            mov(a+1, b+1);
            exit(0);
        }
        if (t(a, b+1))
        {
            mov(a, b+1);
            exit(0);
        }
        if (t(a-1, b+1))
        {
            mov(a-1, b+1);
            exit(0);
        }
    }
    if (yi[b-1]>0)
    {
        if (t(a+1, b-1))
        {
            mov(a+1, b-1);
            exit(0);
        }
        if (t(a, b-1))
        {
            mov(a, b-1);
            exit(0);
        }
        if (t(a-1, b-1))
        {
            mov(a-1, b-1);
            exit(0);
        }
    }
}

        int s[5];
void move_()
{
    check();
    if ((a==xs) and (b==ys) and (stage==1))
    {
        for (int i=1; i<=2*n; i++)
        {
            if ((x[i]<xs) and (y[i]<ys))
                s[1]++;
            if ((x[i]>xs) and (y[i]<ys))
                s[2]++;
            if ((x[i]>xs) and (y[i]>ys))
                s[3]++;
            if ((x[i]<xs) and (y[i]>ys))
                s[4]++;
        }
        if ((s[1]<=s[1]) and (s[1]<=s[2]) and (s[1]<=s[3]) and (s[1]<=s[4]))
            corner=3;
        if ((s[2]<=s[1]) and (s[2]<=s[2]) and (s[2]<=s[3]) and (s[2]<=s[4]))
            corner=4;
        if ((s[3]<=s[1]) and (s[3]<=s[2]) and (s[3]<=s[3]) and (s[3]<=s[4]))
            corner=1;
        if ((s[4]<=s[1]) and (s[4]<=s[2]) and (s[4]<=s[3]) and (s[4]<=s[4]))
            corner=2;
        stage=2;
    }
    /// 4 3
    /// 1 2
    if (stage==1)
    {
        int p=0, r=0;
        if (xs>a)
            p=1;
        if (xs<a)
            p=-1;
        if (ys>b)
            r=1;
        if (ys<b)
            r=-1;
        mov(a+p, b+r);
    }
    else
    {
        if (corner==1)
            mov(max(a-a+1, a-1), max(b-b+1, b-1));
        if (corner==2)
            mov(min(3*n, a+1), max(b-b+1, b-1));
        if (corner==3)
            mov(min(3*n, a+1), min(3*n, b+1));
        if (corner==4)
            mov(max(a-a+1, a-1), min(3*n, b+1));
    }
}

main()
{
    srand(time(0));
    //ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //cout.tie(0);

    cin>>a>>b;
    for (int i=1; i<=2*n; i++)
        {
            cin>>x[i]>>y[i];
            brd[x[i]][y[i]]=1;
            xi[x[i]]++;
            yi[y[i]]++;
        }
    int k, l, r;
    while(true)
    {
        move_();
        cin>>k>>l>>r;
        if ((k==0) and (l==0) and (r==0))
            while (true)
                k++;
        int l0=x[k];
        int r0=y[k];
        xi[l0]--;
        yi[r0]--;
        xi[l]++;
        yi[r]++;
        brd[l0][r0]=0;
        brd[l][r]=1;
        x[k]=l;
        y[k]=r;
    }
    return 0;
}