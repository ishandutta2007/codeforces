#include<bits/stdc++.h>
using namespace std;
int scan(int a, int b)
{
    cout<<"SCAN "<<a<<" "<<b<<'\n';
    cout.flush();
    int c;
    cin>>c;
    return c;
}
bool dig(int a,int b)
{
    cout<<"DIG "<<a<<" "<<b<<'\n';
    cout.flush();
    int c;
    cin>>c;
    return c;
}
void solve()
{
    int a,b;
    cin>>a>>b;
    int val1 = scan(1,1), val2 = scan(1,b);
    int x1 = 1, x2 = b;
    while(val1 > val2)
    {
        val1 -= 2;
        x1++;
    }
    while(val1 < val2)
    {
        val2 -= 2;
        x2--;
    }
    int sr = (x1 + x2) / 2;
    int val3 = scan(1,sr);
    while(val1 > val3)
    {
        val1 -= 2;
        x1++;
    }
    while(val3 < val2)
    {
        val2 -= 2;
        x2--;
    }
    int szer = x2 - x1;
    int pom = (val3 - szer) / 2;
    int val4 = scan(1 + pom, sr);
    val4 -= szer;
    val3 -= szer;
    val3 -= val4;
    int y1 = 1 + val3/2;
    int y2 = y1 + val4;
    //cout<<"SIEMA "<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<'\n';
    if(dig(y1,x1))
        dig(y2,x2);
    else
    {
        dig(y1,x2);
        dig(y2,x1);
    }
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