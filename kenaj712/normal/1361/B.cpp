#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int stala=1e6+5;
long long tab[1000005];
set<int> s;
bool ok=false;
long long pot(long long a,long long b)
{
    long long ret=1,pot=a;
    while(b!=0)
    {
        if(b%2==1)
            ret*=pot;
        if(pot>stala || ret>stala)
            ok=true;
        ret%=mod;

        b/=2;
        if(pot*pot>stala && b!=0)
            ok=true;
        pot=(pot*pot)%mod;
    }
    return ret;
}
int f()
{
    if(s.empty())
        return -1;
    else
    {
        auto it=s.end();
        it--;
       return *it;

    }
}
void usun()
{
    s.erase(f());
}
void solve()
{
    int a,b;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
    {
        int c;
        cin>>c;
        tab[c]++;
        s.insert(c);
    }
    s.insert(0);
    long long nadmiar=0;
    while(f()!=-1)
    {
        int pom=f();
        usun();
        long long pom2=min(tab[pom],nadmiar);
        nadmiar-=pom2;
        tab[pom]-=pom2;
        tab[pom]%=2;
        nadmiar+=tab[pom];
        tab[pom]=0;
        long long pom3=0;
        if(f()!=-1)
            pom3=pot(b,pom-f());
        if(nadmiar*pom3>stala)
            ok=true;
        if(ok)
        {
            if(nadmiar==0)
                ok=false;
            else
            {
                long long out=pot(b,((long long)pom))*nadmiar;
                while(f()!=-1)
                {
                    if(f()==0 && tab[f()]==0)
                    {
                        usun();
                        break;
                    }
                    out-=pot(b,((long long)f()))*tab[f()];
                    tab[f()]=0;
                    out%=mod;
                    usun();
                }
                nadmiar=out;
                break;
            }
        }
        if(pom3!=0)
        nadmiar*=pom3;

    }
    ok=false;
    cout<<(nadmiar%mod+mod)%mod<<'\n';
    s.clear();
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}