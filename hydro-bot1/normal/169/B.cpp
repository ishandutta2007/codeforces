// Hydro submission #6253c3e8ca53060146715b91@1649656809217
#include<bits/stdc++.h>
using namespace std;
char a[1000001],s[1000001];
int main()
{
    cin>>a>>s;
    int l=strlen(a),
    j=strlen(s)-1,i;
    sort(s,s+j+1);
    for(i=0;i<l;i++)
    if(a[i]<s[j])
    a[i]=s[j--];
    cout<<a<<endl;
    return 0;
}