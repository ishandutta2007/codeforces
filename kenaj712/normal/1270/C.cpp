#include<bits/stdc++.h>
using namespace std;
long long pot=1;
void solve()
{
    cout<<3<<'\n';
    int a,b;
    cin>>a;
    long long suma=0,kor=0;
    for(int x=0;x<a;x++)
    {
        cin>>b;
        suma+=b;
        kor^=b;
    }
    long long pom=pot;
    if(suma%2==1)
        pom++;
    cout<<pom<<" ";
    suma+=pom;
    kor^=pom;
    pom=kor*2-suma;
    cout<<pom/2<<" "<<pom/2<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int x=1;x<=58;x++)
        pot*=2;
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}