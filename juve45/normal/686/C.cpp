#include <iostream>

using namespace std;

int nrn, nrm, n, m, ans, use[11], v[11], v2[11];

long long log7(long long k)
{
    if(k==1) return 1;
    k--;
    long long ans=0;
    while(k!=0)
    {
        k/=7;
        ans++;
    }
    return ans;
}

bool check(int val, int lg, int* v)
{
    int s=0;
    int f=1;
    for(int i=lg-1;i>=0;i--)
    {
        s+=v[i]*f;
        f*=7;

    }
    if(s<val)
        return true;
    return false;
}

void BKT2(int k, int lg)
{
    if(k==lg)
    {
        if(check(m, lg, v2))
            ans++;
    }
    else
    {
        for(int i=0;i<7;i++)
        {
                if(!use[i])
                {
                    use[i]=1;
                    v2[k]=i;
                    BKT2(k+1, lg);
                    use[i]=0;
                }
        }
    }
}

void BKT(int k, int lg)
{
    if(k==lg)
    {
        if(check(n, lg, v))
            BKT2(0, nrm);
    }
    else
    {
        for(int i=0;i<7;i++)
        {
                if(!use[i])
                {
                    use[i]=1;
                    v[k]=i;
                    BKT(k+1, lg);
                    use[i]=0;
                }
        }
    }
}

int main()
{

    cin>>n>>m;
    nrn=log7(n);
    nrm=log7(m);

    BKT(0, nrn);

    cout<<ans<<'\n';
    return 0;
}