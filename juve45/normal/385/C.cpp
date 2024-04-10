#include <iostream>
#include <vector>
#include <cstdio>

#define DMAX 1000001
#define XMAX 10000001
#define pb push_back

using namespace std;

bool pr[XMAX];
long long sol[XMAX];
vector <int> p;
int n, m;

void Ciur(int k)
{

    if(k*k>XMAX) return;
    for(int i=2*k; i<=XMAX; i=i+k)
        pr[i]=1;
    k++;
    while(pr[k]) k++;
    Ciur(k);
}

void Decompose(int k, int a)
{
    int b=0;
    if(pr[k]==0) sol[k]++;
    else{
       //cout<<a;
       int psz=p.size();
    while(k>=p[b]&& b<psz)
    {
        int h=p[b];
        if(k%p[b]==0)
        {
            k=k/p[b];
            if(pr[k]==0 && k!=p[b]) sol[k]++, k=0;
            while(k%p[b]==0 &&k>0)
            {
                k=k/p[b];
                if(pr[k]==0 && k!=p[b])
                    sol[k]++, k=0;
            }
            sol[p[b]]++;
        }
        b++;
    }
    }


}

void PreProc()
{
    pr[0]=1;
    pr[1]=1;
    //Adding prime numbers to 10000000
    Ciur(2);

    for(int i=2; i<=XMAX; i++)
        if(pr[i]==0) p.pb(i);

    //cout<<3<<'\n';
    //decomposing numers from array in prime numbers


    //cout<<"END of PRE"<<'\n';
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin>>n;


    PreProc();
int x;
       for(int i=1; i<=n; i++)
         scanf("%i", &x), Decompose(x, i);

    //cout<<4<<'\n';
    for(int i=1; i<=XMAX; i++)
        sol[i]=sol[i]+sol[i-1];

    int a, b;
    cin>>m;
    for(int i=1; i<=m; i++)
        {scanf("%i%i", &a, &b);
        if(a>XMAX) a=XMAX;
         if(b>XMAX) b=XMAX;
         printf("%i\n",sol[b]-sol[a-1]);
         }

    return 0;
}