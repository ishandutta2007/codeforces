#include <bits/stdc++.h>

using namespace std;
int mny=9999,mxy=0;
int mnx=9999,mxx=0;
int main()
{
    ios::sync_with_stdio(0);
pair<int,int> a[3];

for(int i=0;i<3;i++){cin>>a[i].first>>a[i].second;
mny=min(mny,a[i].second);mxy=max(mxy,a[i].second);
mnx=min(mnx,a[i].first);mxx=max(mxx,a[i].first);}
sort(a,a+3);
cout<<mxx+mxy-mnx-mny+1<<endl;
for(int i=a[0].first;i<a[1].first;i++)cout<<i<<" "<<a[0].second<<endl;
for(int i=mny;i<=mxy;i++)cout<<a[1].first<<" "<<i<<endl;
for(int i=a[1].first+1;i<=a[2].first;i++)cout<<i<<" "<<a[2].second<<endl;
    return 0;
}