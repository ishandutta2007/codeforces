#include <iostream>

using namespace std;
string s,d;int n, fi[101],se[101];bool ans;
int main()
{
    cin>>s>>n;
    for(int i=0;i<n;i++){cin>>d;if(d==s)ans=true;if(d[0]==s[1])fi[i]=1;if(d[1]==s[0])se[i]=1;}
    for(int i=0;i<n;i++) {for(int j=0;j<n;j++) if(fi[i]+se[j]==2) ans=true;}
    if(ans)cout<<"YES";else cout<<"NO";
    return 0;
}