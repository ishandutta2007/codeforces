#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(char a)
{
    int pom = (a - 'a');
    return (1<<pom);
}
void check_impossible(int b,string d)
{
    int sum = 0;
    for(auto x:d)
        sum+=f(x);
    if(sum == b)
    {
        cout<<"No";
        exit(0);
    }
}
int must[70];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    string d;
    cin>>d;
    //check_impossible(b,d);
    b-=f(d.back());
    d.pop_back();
    b+=f(d.back());
    d.pop_back();
    int sum  = 0;
    b = abs(b);
    for(auto x:d)
    {
        must[(x-'a')+1]++;
        sum += f(x);
    }
    if(sum < b)
    {
        cout<<"No";
        exit(0);
    }
    b = sum - b;
    for(int x=0;x<=60;x++)
    {
        if(b%2==1 && must[x] == 0)
        {
            cout<<"No";
            return 0;
        }
        must[x] -= b%2;
        must[x+1]+=must[x]/2;
        b/=2;
    }
    cout<<"Yes";
	return 0;
}