// Hydro submission #62972c35b0c5e75beb1586b8@1654074422497
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s;
        printf(s.find("r")>s.find("R")||s.find("g")>s.find("G")||s.find("b")>s.find("B")?"NO\n":"YES\n");
    }
    return 0;
}