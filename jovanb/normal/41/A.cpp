#include <bits/stdc++.h>

using namespace std;
char a[1000],b[1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    cin>>a>>b;
    int k=strlen(a),i;
    for(i=0;i<k;i++){
        if(a[i]!=b[k-i-1]){cout<<"NO";return 0;}
    }
    cout<<"YES";
    return 0;
}