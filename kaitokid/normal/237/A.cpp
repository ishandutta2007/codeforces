#include <bits/stdc++.h>

using namespace std;

int main()
{
int n,hx,mx;
vector<int>h,m;
cin>>n>>hx>>mx;
h.push_back(hx);
m.push_back(mx);
int x=1,l=1;
for(int i=1;i<n;i++)
{cin>>hx>>mx;
h.push_back(hx);
m.push_back(mx);
if(h[i]==h[i-1]&&m[i]==m[i-1]){l++;}else{x=max(x,l);l=1;}

}
x=max(x,l);
cout<<x;
    return 0;
}