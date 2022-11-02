#include<bits/stdc++.h>
using namespace std;
long long maks=0,a;
long long tab[15];
long long zero;
void rek(long long ile,long long gdzie)
{
    if(ile<=a)
        maks=max(ile,maks);
    if(gdzie==0)
        return;

    long long pom=min((a-ile)/gdzie+1,tab[gdzie]);
    for(long long x=pom;x>=max(zero,pom-8);x--)
        rek(ile+x*gdzie,gdzie-1);

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>a;
    for(int x=1;x<=8;x++)
        cin>>tab[x];
    rek(0,8);
    cout<<maks;
	return 0;
}