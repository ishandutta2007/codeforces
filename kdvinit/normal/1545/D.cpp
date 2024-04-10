#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, k, x, y, val; cin>>n>>k; int s1[k+1]={0}, s2[k+1]={0};
    for(int i=1; i<=k; i++) for(int j=1; j<=n; j++) cin>>x, s1[i]+=x, s2[i]+=(x*x);
    map<int, int> dif; for(int i=2; i<=k; i++) { y = s1[i]-s1[i-1]; if(++dif[y]>2) val=y; }
    for(int i=2; i<k; i++) if( (s1[i]-s1[i-1])!=val) { y=i; break; }
    int j = (y+3<=k ? y+2:y-2), d1 = s1[y+1]-s1[y]-val;
    int d2 = ((s2[y-1]+s2[y+1]-2*s2[y]) - (s2[j-1]+s2[j+1]-2*s2[j]))/2;
    int p = ((d2-(d1*d1))/(2*d1))+d1; cout<<y-1<<" "<<p<<endl;
}