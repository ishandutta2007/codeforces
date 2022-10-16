#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    if(b==0)cout<<"1"<<endl;
    else cout<<min(a-b,b)<<endl;
    return 0;
}