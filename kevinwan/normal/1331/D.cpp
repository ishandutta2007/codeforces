#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
int a[6],b[6];
int hail(string s){
    if(s=="A278832")return 0;
    if(s=="A089956")return 0;
    if(s=="A089957")return 1;
    if(s=="A144045")return 1;
}
int main(){
    ll x;
    scanf("%X",&x);
    printf("%d",x&1);
    return 0;
    string s;
    cin>>s;
    cout<<hail(s);
}