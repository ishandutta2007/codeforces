#include <iostream>
#include <vector>
#define pb push_back
#define N 1000000
using namespace std;
int need, n, k, use[N+2];
vector <int> sol, got;

int main()
{

cin>>n;
for(int i=1;i<=n;i++)
    cin>>k, use[k]=1;
int ok=n;
for(int i=1;i<=N/2 && ok>0;i++)
    {
        if(use[i]==1)
        {
            if(use[N-i+1]==1)
                need++;
            else sol.pb(N-i+1), ok--;
        }
        else
        if(use[i]==0)
            {if(use[N-i+1]==0)
        {
        if(need==0) got.pb(i);
        else need--, sol.pb(i), sol.pb(N-i+1), ok-=2;
        }
        if(use[N-i+1]==1) sol.pb(i), ok--;
            }
    }
int h=0;
cout<<n<<'\n';
while(ok>0)
{
sol.pb(got[h]);
sol.pb(N-got[h]+1);
h++;
ok--;
ok--;
}
for(int i=0;i<n;i++)
cout<<sol[i]<<' ';


    return 0;
}