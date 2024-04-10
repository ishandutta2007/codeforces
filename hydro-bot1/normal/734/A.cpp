// Hydro submission #62550d7917cd4d0a41764d67@1649741190254
#include<bits/stdc++.h>
using namespace std;
string s;
int A,D;
int main()
{
    int n,i;cin>>n>>s;
    for(i=0;i<s.size();i++)
    if(s[i]=='A') A++;else D++;
    if(A>D) printf("Anton\n");
    else if(A<D) printf("Danik\n");
    else printf("Friendship\n");
    return 0;
}