#include<bits/stdc++.h>
using namespace std;

#define ch() getchar()
#define pc(x) putchar(x)
using namespace std;
template<typename T>void read(T&x){
	static char c;static int f;
	for(c=ch(),f=1;c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c>='0'&&c<='9';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>void write(T x){
	static char q[65];int cnt=0;
	if(x<0)pc('-'),x=-x;
	q[++cnt]=x%10,x/=10;
	while(x)
		q[++cnt]=x%10,x/=10;
	while(cnt)pc(q[cnt--]+'0');
}

#define PL 20000001
int NOP[PL]={0};

long long int Power2(int n)
{
    long long int ans = 1LL << n;
    return ans;
}

int Make_Prime()
{
    for(int i=2; i<PL; i++)
    {
        if(NOP[i]!=0) continue;
        for(int j=i; j<PL; j+=i)
        {
            NOP[j]++;
        }
    }

    return 0;
}
int Implement_Make_Prime=Make_Prime();

int GCD(int x, int y)
{
    if(x%y==0) return y;
    else return GCD(y, x%y);
}

void solve()
{
    int c, d, x;
    read(c);
    read(d);
    read(x);

    int g = GCD(c, d);
    if(x%g!=0)
    {
        write(0);
        pc('\n');
        return;
    }

    c/=g;
    d/=g;
    x/=g;

    long long int ans=0;
    int i;
    for(i=1; i*i<x; i++)
    {
        if(x%i!=0) continue;

        if( (i+d)%c==0 )
        {
            ans+= (long long int)Power2(NOP[((i+d)/c)]);
        }

        if( ((x/i)+d)%c==0 )
        {
            ans+= (long long int)Power2(NOP[(((x/i)+d)/c)]);
        }
    }

    if( i*i==x )
    {
        if( (i+d)%c==0 )
        {
            ans+= (long long int)Power2(NOP[((i+d)/c)]);
        }
    }

    write(ans);
    pc('\n');
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; read(t);
    while(t--) solve();
    return 0;
}