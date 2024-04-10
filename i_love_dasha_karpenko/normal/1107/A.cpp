#include <bits/stdc++.h>

using namespace std;
#define DIM 207
#define INF 1000000007
typedef pair<long long,long long> pairll;
long long q,n;
string a;
int main()
{
    //freopen("input.txt","r",stdin);
    cin>>q;
for (int i = 1;i<=q;i++){
    cin>>n;
    cin>>a;
    if (a.length()==2 && a[0]>=a[1]){
            cout<<"NO"<<endl;
            continue;
    }

    cout<<"YES"<<endl<<2<<endl<<a[0]<<' ';
    for (int j = 1;j<a.length();j++)cout<<a[j];
    cout<<endl;
}
}