#include <bits/stdc++.h>
using namespace std;

string a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ///freopen("a.in","r",stdin);

    int n;
    cin>>n>>a;

    for(int i=0; i<a.size(); i++){
        if((a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y')&&(a[i+1]=='a'||a[i+1]=='e'||a[i+1]=='i'||a[i+1]=='o'||a[i+1]=='u'||a[i+1]=='y')){ a.erase(i+1,1); i--; }
    }

    cout<<a;

    return 0;
}