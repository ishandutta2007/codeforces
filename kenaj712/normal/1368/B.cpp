#include<bits/stdc++.h>
using namespace std;
long long tab[1000005];
long long f()
{
    long long pom=1;
    for(int x=0;x<10;x++)
        pom*=tab[x];
    return pom;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a;
    cin>>a;
    long long pom=1;
    while(pom*pom*pom*pom*pom*pom*pom*pom*pom*pom<a)
        pom++;
    for(int x=0;x<10;x++)
        tab[x]=pom;
    for(int x=0;x<10;x++)
    {
        tab[x]--;
        if(f()>=a)
            continue;
        tab[x]++;
    }
    string xd="codeforces";
    for(int x=0;x<10;x++)
        while(tab[x]--)
            cout<<xd[x];

	return 0;
}