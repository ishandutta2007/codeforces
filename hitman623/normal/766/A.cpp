#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()

using namespace std;

int main()
{
    char a[100005],b[100005];
    cin>>a>>b;
    if(strcmp(a,b)==0) cout<<-1;
    else cout<<max(strlen(a),strlen(b));
    return 0;
}