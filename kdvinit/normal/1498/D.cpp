/*
K.D. Vinit  |,,|
Don't Stalk My Code :)
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e5+5;
int Ans[M];
int x;
int y;

int Time;
int Cnt[M];
int n, m;
int Lakh = 100000;

int Ceil(double z)
{
    int flr = z;
    if(flr==z) return flr;
    else return flr+1;
}

void Update(int chi, int par)
{
    if(chi>m) return;
    if(Ans[chi]!=-1) return;
    Ans[chi] = Time;
    if(Ans[par]==Time) Cnt[chi] = Cnt[par]+1;
    else Cnt[chi] = 1;
}

void Add()
{
    for(int i=0; i<=m; i++)
    {
        if(Ans[i]==-1) continue;
        if(Ans[i]==Time && Cnt[i]==y) continue;
        int z = i*Lakh + x;
        int zz =  z/Lakh; //ceil(z);   //Ceil(z);
        if(zz*Lakh!=z) zz++;
        Update(zz, i);
    }
}

void Mul()
{
    for(int i=0; i<=m; i++)
    {
        if(Ans[i]==-1) continue;
        if(Ans[i]==Time && Cnt[i]==y) continue;
        int z = i;
        z*=x;
        int zz = z/Lakh;  //ceil(z);   //Ceil(z);
        if(zz*Lakh!=z) zz++;
        Update(zz, i);
    }
}

void solve()
{
    cin>>n>>m;

    Ans[0]=-2;
    Cnt[0]=0;
    for(int i=1; i<=m; i++) Ans[i]=-1;

    int op;
    for(int i=1; i<=n; i++)
    {
        Time = i;
        cin>>op>>x>>y;
        //double Lakh = 100000;
        //x/=Lakh;
        if(op==1) Add();
        else Mul();
    }

    for(int i=1; i<=m; i++) cout<<Ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    std::cout << std::setprecision(15); std::cout << std::fixed;
    solve();
    return 0;
}