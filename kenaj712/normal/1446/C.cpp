#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int solve(int pocz,int kon,int kor)
{
    if(kor == 0)
        return (kon-pocz+1);
    int sr = pocz;
    while(sr<kon && (tab[sr+1]&kor)==0)
        sr++;
    if((tab[pocz]&kor) != 0 || sr == kon)
        return solve(pocz,kon,kor/2);
    return max(solve(pocz,sr,kor/2)+1,solve(sr+1,kon,kor/2)+1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=1;x<=a;x++)
        cin>>tab[x];
    sort(tab+1,tab+a+1);
    cout<<a-solve(1,a,(1<<30));
	return 0;
}