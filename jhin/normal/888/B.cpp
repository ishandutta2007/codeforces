#include <iostream>

using namespace std;
int n,a[4],ans;string s;
int main()
{
   cin>>n>>s;
   for(int i=0;i<n;i++)a[s[i]]++;
    cout<<2*(min(a['L'],a['R'])+min(a['U'],a['D']));
    return 0;
}