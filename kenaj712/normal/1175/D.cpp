#include<bits/stdc++.h>
using namespace std;
vector<long long> v;;
int tab[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    b--;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    long long sum=0,out=0;
    for(int x=a;x>=1;x--)
    {
        sum+=tab[x];
        if(x!=1)
            v.push_back(sum);
    }
    out+=sum;
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int x=0;x<b;x++)
        out+=v[x];
    cout<<out;
	return 0;
}