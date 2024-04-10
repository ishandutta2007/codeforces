#include <bits/stdc++.h>

using namespace std;
int a;
set<int> ans;
void vrt(int x)
{
    if(x>a){return;}
    ans.insert(x);
    vrt(x*10);
    vrt(x*10 +1);
}
int main()
{

cin>>a;
vrt(1);
cout<<ans.size();
    return 0;
}