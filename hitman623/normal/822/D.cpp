#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
bool v[5000006];
long sp[5000006],h=1e9+7;
long t,l,r,term=1,ans=0,i;
void Sieve(){
	for (long i = 2; i < 5000006; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (long i = 3; i < 5000006; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (long j = i; (j*i) < 5000006; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}
long cal(long x)
{
    long an=0;
    if(x==1) return 0;
    return (((((sp[x]*(sp[x]-1))/2)%h)*(x/sp[x]))%h+cal(x/sp[x]))%h;
}
int main()
{
    io
    Sieve();
    cin>>t>>l>>r;
    for(i=l;i<=r;++i)
    {
        ans=(ans+(term*cal(i))%h)%h;
        term=(term*t)%h;
    }
    cout<<ans;
    return 0;
}