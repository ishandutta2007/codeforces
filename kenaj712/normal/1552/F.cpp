#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int tab[200005][3];
int pot = (1<<18);
int tree[1000005];
void ins(int a,int war)
{
    int pom = a + pot;
    while(pom != 0)
    {
        tree[pom] = (tree[pom] + war) % mod;
        pom /= 2;
    }
}
int check(int a,int b)
{
    if(a > b)
        return 0;
    int l = a + pot, r = b + pot;
    long long sum = tree[l];
    if(l != r)
        sum += tree[r];
    while(l/2 != r/2)
    {
        if(l % 2 == 0)
            sum += tree[l+1];
        if(r % 2 == 1)
            sum += tree[r-1];
        l/=2;
        r/=2;
    }
    return sum % mod;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        for(int y=0;y<3;y++)
            cin>>tab[x][y];
    long long out = 0;
    for(int x=1;x<=a;x++)
    {
        int pocz = 1, kon = x , sr;
        while(pocz != kon)
        {
            sr = (pocz + kon) / 2;
            if(tab[sr][0] < tab[x][1])
                pocz = sr + 1;
            else
                kon = sr;
        }
        long long sum = tab[x][0] - tab[x][1];
        sum += check(pocz,x-1);
        sum %= mod;
        ins(x,sum);
        if(tab[x][2])
            out += sum;
    }
    cout<<(out + tab[a][0] + 1)%mod;
	return 0;
}