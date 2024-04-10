#include <bits/stdc++.h>

using namespace std;

int n,x,cnt1,cnt2;
int main()
{
cin>>n;
for(int i=0;i<n;i++)
{cin>>x;if(x>0)cnt1++;else cnt2++;cin>>x;}
 if(min(cnt1,cnt2)<2)cout<<"Yes";else cout<<"NO";
    return 0;
}