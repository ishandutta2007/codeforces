// Hydro submission #62551013ac286d0a56b8729b@1649741848448
#include<bits/stdc++.h>
using namespace std;
string s,t;
int main()
{
    cin>>s>>t;
    if(s.size()!=t.size())
    printf("%d\n",max(s.size(),t.size()));
    else if(s!=t) printf("%d\n",s.size());
    else printf("-1\n");
    return 0;
}